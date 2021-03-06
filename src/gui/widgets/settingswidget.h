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
#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QWidget>
#include <QButtonGroup>
#include <QRegExp>
#include <QValidator>
#include <QMessageBox>
#include <QProcess>
#include <QDebug>
#include "src/classes/settings.h"
#include "src/database/db.h"
#include "src/classes/pilot.h"

namespace Ui {
class SettingsWidget;
}

class SettingsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsWidget(QWidget *parent = nullptr);
    ~SettingsWidget();

private slots:

    void themeGroup_toggled(int id);

    void on_aboutPushButton_clicked();

    void on_acSortComboBox_currentIndexChanged(int index);

    void on_acAllowIncompleteComboBox_currentIndexChanged(int index);

    void on_prefixLineEdit_textChanged(const QString &arg1);

    void on_piclastnameLineEdit_editingFinished();

    void on_picfirstnameLineEdit_editingFinished();

    void on_employeeidLineEdit_editingFinished();

    void on_emailLineEdit_editingFinished();

    void on_phoneLineEdit_editingFinished();

    void on_aliasComboBox_currentIndexChanged(int index);

    void on_functionComboBox_currentIndexChanged(const QString &arg1);

    void on_rulesComboBox_currentIndexChanged(const QString &arg1);

    void on_approachComboBox_currentIndexChanged(const QString &arg1);

    void on_nightComboBox_currentIndexChanged(int index);

    void on_pilotSortComboBox_currentIndexChanged(int index);

    void on_logbookViewComboBox_currentIndexChanged(int index);

    void on_companyLineEdit_editingFinished();

private:
    Ui::SettingsWidget *ui;

    void fillSettings();

    void setupValidators();

    void updatePersonalDetails();
};

#endif // SETTINGSWIDGET_H
