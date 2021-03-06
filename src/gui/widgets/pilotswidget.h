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
#ifndef PILOTSWIDGET_H
#define PILOTSWIDGET_H

#include <QWidget>
#include <QItemSelection>
#include <QSqlTableModel>
#include <QDebug>
#include <QLabel>
#include "src/classes/settings.h"
#include "src/classes/pilot.h"
#include "src/gui/dialogues/newpilotdialog.h"

namespace Ui {
class PilotsWidget;
}

class PilotsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PilotsWidget(QWidget *parent = nullptr);
    ~PilotsWidget();

private slots:
    void tableView_selectionChanged();

    void tableView_headerClicked(int);

    void on_newButton_clicked();

    void on_deletePushButton_clicked();

    void pilot_editing_finished();

    void on_searchLineEdit_textChanged(const QString &arg1);

private:
    Ui::PilotsWidget *ui;

    QSqlTableModel *model = new QSqlTableModel;

    qint32 sortColumn;

    QVector<qint32> selectedPilots;

    void refreshModelAndView();
};

#endif // PILOTSWIDGET_H
