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
#ifndef HOMEWIDGET_H
#define HOMEWIDGET_H

#include <QWidget>
#include <QStackedLayout>
#include <QLabel>
#include <QLineEdit>
#include "src/database/db.h"
#include "src/classes/stat.h"
#include "src/classes/calc.h"
#include "src/classes/completionlist.h"
#include "src/gui/dialogues/newtaildialog.h"
#include "src/classes/aircraft.h"
#include "src/gui/dialogues/newpilotdialog.h"
#include "src/database/entry.h"
#include "src/gui/widgets/totalswidget.h"
#include "src/gui/dialogues/firstrundialog.h"
#include "src/gui/dialogues/newflightdialog.h"


namespace Ui {
class HomeWidget;
}

class HomeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HomeWidget(QWidget *parent = nullptr);
    ~HomeWidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::HomeWidget *ui;

    void showTotals();
};

#endif // HOMEWIDGET_H
