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
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db::connect();

    // Set up Toolbar
    ui->toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->toolBar->setIconSize(QSize(64,64));
    ui->actionLogbook->setIcon(QIcon(":/icons/ionicon-icons/book-outline.png"));
    ui->actionHome->setIcon(QIcon(":/icons/ionicon-icons/home-outline.png"));
    ui->actionSettings->setIcon(QIcon(":/icons/ionicon-icons/settings-outline.png"));
    ui->actionQuit->setIcon(QIcon(":/icons/ionicon-icons/power-outline.png"));
    ui->actionNewFlight->setIcon(QIcon(":/icons/ionicon-icons/airplane-outline.png"));

    // Adds space between toolbar items and actionSetting item
    auto *spacer = new QWidget();
    spacer->setMinimumWidth(10);
    spacer->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
    ui->toolBar->insertWidget(ui->actionSettings,spacer);


    // create and show homeWidget
    auto hw = new homeWidget(this);
    ui->stackedWidget->addWidget(hw);
    ui->stackedWidget->setCurrentWidget(hw);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::nope()
{
    QMessageBox nope(this); //error box
    nope.setText("This feature is not yet available!");
    nope.exec();
}


/*
 * Slots
 */

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionHome_triggered()
{
    auto hw = new homeWidget(this);
    ui->stackedWidget->addWidget(hw);
    ui->stackedWidget->setCurrentWidget(hw);
}

void MainWindow::on_actionLogbook_triggered()
{
    auto lw = new logbookWidget(this);
    ui->stackedWidget->addWidget(lw);
    ui->stackedWidget->setCurrentWidget(lw);
}

void MainWindow::on_actionSettings_triggered()
{
    //nope();
    auto sw = new settingsWidget(this);
    ui->stackedWidget->addWidget(sw);
    ui->stackedWidget->setCurrentWidget(sw);
}

void MainWindow::on_actionNewFlight_triggered()
{/*
    QVector<QStringList> lineEdit_completionLists = {
        QStringList(),//empty dummy list for TimeLineEdits
        dbAirport::retreiveIataIcaoList(),
        dbAircraft::retreiveRegistrationList(),
        dbPilots::retreivePilotList()
    };

    NewFlight nf(this, lineEdit_completionLists);
    nf.exec();
    */
}
