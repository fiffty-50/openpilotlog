#include "aflightentry.h"
#include "src/experimental/adatabase.h"

namespace experimental {

AFlightEntry::AFlightEntry()
    : AEntry::AEntry(DEFAULT_FLIGHT_POSITION)
{}

AFlightEntry::AFlightEntry(int row_id)
    : AEntry::AEntry(DataPosition(QStringLiteral("flights"), row_id))
{}

AFlightEntry::AFlightEntry(TableData table_data)
    : AEntry::AEntry(DEFAULT_FLIGHT_POSITION, table_data)
{}

const QString AFlightEntry::summary()
{
    if(tableData.isEmpty())
        return QString();

    QString flight_summary;
    flight_summary.append(tableData.value("doft").toString() + " ");
    flight_summary.append(tableData.value("dept").toString() + " ");
    flight_summary.append(ACalc::minutesToString(tableData.value("tofb").toString()) + " ");
    flight_summary.append(ACalc::minutesToString(tableData.value("tonb").toString()) + " ");
    flight_summary.append(tableData.value("dest").toString() + " ");

    return flight_summary;
}

const QString AFlightEntry::getRegistration()
{
    QString tail_id = tableData.value(QLatin1String("acft")).toString();
    if(tail_id.isEmpty())
        return QString();

    QString statement = "SELECT registration "
                        "FROM tails "
                        "WHERE ROWID =" + tail_id;

    auto tail_registration = aDB()->customQuery(statement, 1);

    if(tail_registration.isEmpty()) {
        return QString();
    } else {
        return tail_registration.first();
    }
}

const QString AFlightEntry::getPilotName(pilot pilot_)
{
    QString row_id;
    switch (pilot_) {
    case pilot::pic:
        row_id = tableData.value(QLatin1String("pic")).toString();
        break;
    case pilot::sic:
        row_id = tableData.value(QLatin1String("sic")).toString();
        break;
    case pilot::thirdPilot:
        row_id = tableData.value(QLatin1String("thirdPilot")).toString();
        break;
    }
    if(row_id == QString())
        return row_id;

    QString statement = "SELECT lastname||', '||firstname "
                        "FROM pilots "
                        "WHERE ROWID =" + row_id;

    auto pilot_name = aDB()->customQuery(statement, 1);
    if(pilot_name.isEmpty()) {
        return QString();
    } else {
        return pilot_name.first();
    }
}

} // namespace experimental
