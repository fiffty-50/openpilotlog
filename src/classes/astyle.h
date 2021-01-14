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
#ifndef ASTYLE_H
#define ASTYLE_H
#include <QString>
#include <QFileInfo>
#include <QMap>

/*!
 * \brief The AStyle class encapsulates style and stylesheet logic.
 * \todo Agree upon the file naming of the assets that will be read.
 * for now it is assumed that dark means "dark.qss"
 */
class AStyle
{
public:
    enum StyleSheet{
        Default = 0,
        Dark,
        Light
    };
private:
    static QString currentStyle;
    static QString currentStyleSheet;
public:
    static const QStringList styles;
    static const QString defaultStyle;
    static const QString defaultStyleSheet;
    static const QMap<StyleSheet, QFileInfo> defaultStyleSheets;

    static void setup();
    static void setStyle(const QString style);
    static void setStyleSheet(const StyleSheet stylesheet);
    static const QString& style();
    static const QString& styleSheet();
};

#endif // ASTYLE_H
