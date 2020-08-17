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
//#include <QCoreApplication>
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QPalette>
#include <QColor>
#include <QDebug>



int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("Fiffty50");
    QCoreApplication::setOrganizationDomain("f-cloud.ch");
    QCoreApplication::setApplicationName("openLog");
    QApplication openLog(argc, argv);
    //Theming with CSS inlcues QFile,QTextStream, QDir, themes folder and TARGET = flog, RESOURCES = themes/breeze.qrc in pro
    // credit: https://github.com/Alexhuszagh/BreezeStyleSheets
    QDir::setCurrent("/themes");
    QFile file(":dark.qss");
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream stream(&file);
    openLog.setStyleSheet(stream.readAll());


    MainWindow w;
    w.show();
    return openLog.exec();
}