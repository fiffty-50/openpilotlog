/*
 *openPilot Log - A FOSS Pilot Logbook Application
 *Copyright (C) 2020  Felix Turowsky
 *
 *This program is free software: you can redistribute it and/or modify
 *it under the terms of the GNU General Public License as published by
 *the Free Software Foundation, either version 3 of the License, or
 *(at your option) any later version.
 *
 *This program is distributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *GNU General Public License for more details.
 *
 *You should have received a copy of the GNU General Public License
 *along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include "pilotswidget.h"
#include "ui_pilotswidget.h"

// Debug Makro
#define DEB(expr) \
    qDebug() << __PRETTY_FUNCTION__ << "\t" << expr

pilotsWidget::pilotsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pilotsWidget)
{
    ui->setupUi(this);

    QString welcomeMessage = "Select a Pilot to show or edit details.";
    QWidget *start = new QWidget();
    start->setObjectName("welcomePL");
    QLabel *label = new QLabel(welcomeMessage);
    label->setAlignment(Qt::AlignCenter);
    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(label);
    start->setLayout(layout);
    ui->stackedWidget->addWidget(start);
    ui->stackedWidget->setCurrentWidget(start);


    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("viewPilots");
    model->select();

    QTableView *view = ui->tableView;
    view->setModel(model);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->setSelectionMode(QAbstractItemView::SingleSelection);
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    view->horizontalHeader()->setStretchLastSection(QHeaderView::Stretch);
    view->setColumnWidth(0, 60);
    view->setColumnWidth(1, 240);
    view->setColumnWidth(2, 180);
    view->verticalHeader()->hide();
    view->setAlternatingRowColors(true);
    view->setSortingEnabled(true);
    QSettings settings;

    view->sortByColumn(settings.value("userdata/pilSortColumn").toInt(), Qt::AscendingOrder);

    view->show();

    connect(ui->tableView->selectionModel(),
            SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),
            SLOT(tableView_selectionChanged(const QItemSelection &, const QItemSelection &)));
}

pilotsWidget::~pilotsWidget()
{
    delete ui;
}

void pilotsWidget::tableView_selectionChanged(const QItemSelection &index, const QItemSelection &)
{
    setSelectedPilot(index.indexes()[0].data().toInt());
    DEB("Selected Pilot with ID#: " << selectedPilot);

    auto np = new NewPilot(Pilot("pilots", selectedPilot), Db::editExisting, this);

    np->setWindowFlag(Qt::Widget);
    ui->stackedWidget->addWidget(np);
    ui->stackedWidget->setCurrentWidget(np);
}

void pilotsWidget::setSelectedPilot(const qint32 &value)
{
    selectedPilot = value;
}

void pilotsWidget::on_newButton_clicked()
{
    auto np = new NewPilot(Db::createNew, this);
    np->show();
}

void pilotsWidget::on_deletePushButton_clicked()
{
    if (selectedPilot > 0) {

        auto pil = new Pilot("pilots", selectedPilot);
        pil->remove();


        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("viewPilots");
        model->select();
        ui->tableView->setModel(model);
        connect(ui->tableView->selectionModel(),
                SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),
                SLOT(tableView_selectionChanged(const QItemSelection &, const QItemSelection &)));

        ui->stackedWidget->setCurrentWidget(parent()->findChild<QWidget *>("welcomePL"));

    } else {
        auto mb = new QMessageBox(this);
        mb->setText("No Pilot selected.");
        mb->show();
    }
}
