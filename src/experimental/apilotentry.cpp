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
#include "apilotentry.h"

namespace experimental {

APilotEntry::APilotEntry()
    : AEntry::AEntry(DEFAULT_PILOT_POSITION)
{}

APilotEntry::APilotEntry(int row_id)
    : AEntry::AEntry(DataPosition(QStringLiteral("pilots"), row_id))
{}

APilotEntry::APilotEntry(TableData table_data)
    : AEntry::AEntry(DEFAULT_PILOT_POSITION, table_data)
{}

const QString APilotEntry::name()
{
    if (tableData.isEmpty())
        return QLatin1String("");

    return tableData.value(QStringLiteral("piclastname")).toString() + ','
           +tableData.value(QStringLiteral("picfirstname")).toString().left(1) + '.';
}

} // namespace experimental
