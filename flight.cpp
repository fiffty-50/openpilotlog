#include "flight.h"

/*!
 * \brief flight::printFlight Displays basic data for debugging
 */
void flight::print()
{
    QTextStream cout(stdout, QIODevice::WriteOnly);

    if(id != -1){
        cout << "Flight ID:\t\t" + QString::number(id) + "\n";
    }else{
        cout << "Flight ID:\t\tnot set\n";
    }

    if(doft.toString(Qt::ISODate).length()){
        cout << "Date of Flight:\t" + doft.toString(Qt::ISODate) + "\n";
    }else{
        cout << "Date of Flight:\tnot set\n";
    }

   if(dept != QStringLiteral("INVA")){
       cout << "Departure:\t\t" + dept  + "\n";
    }else{
       cout << "Departure:\t\tnot set\n";
    }

   if(dest != QStringLiteral("INVA")){
       cout << "Destination:\t\t" + dest  + "\n";
    }else{
       cout << "Destination:\t\tnot set\n";
    }

   if(tofb.toString("hh:mm").length()){
       cout << "Departure Time:\t" + tofb.toString("hh:mm") + "\n";
   }else{
       cout << "Departure Time:\tnot set\n";
   }

   if(tonb.toString("hh:mm").length()){
       cout << "Arrival Time:\t" + tonb.toString("hh:mm") + "\n";
   }else{
       cout << "Arrival Time:\tnot set\n";
   }

    if(pic != QStringLiteral("INVA")){
        cout << "Pilot in Command:\t" + pic + "\n";
    }else{
       cout << "Pilot in Command:\tnot set\n";
    }

    if(acft != QStringLiteral("INVA")){
        cout << "Aircraft:\t\t" + acft + "\n";
    }else{
       cout << "Aircraft:\t\tnot set\n";
    }

    if(tblk.isValid()){
        cout << "Blocktime:\t\t" + tblk.toString("hh:mm") + "\n";
    }else{
       cout << "Blocktime:\t\tnot set\n";
    }

    if(isValid){
        cout << "Object status:\t\033[38;2;0;255;0;48;2;0;0;0m VERIFIED \033[0m\n";
    }else{
        cout << "Object status:\t\033[38;2;255;0;0;48;2;0;0;0m UNVERIFIED \033[0m\n";
    }
    if(!invalidItems.isEmpty()){
        cout << "Invalid items:\t";
        for(auto const& item : invalidItems){
            cout << item + QLatin1Char(' ');
        }
        cout << "\n";
    }
}
/*!
 * \brief flight::debug Provides compatibility with qDebug
 * \return
 */
QString flight::debug()
{
    print();
    return QString();
}

flight flight::fromVector(QVector<QString> details)
{
    if(details.length() != 32){
        qWarning() << __PRETTY_FUNCTION__ << "Invalid Input. Aborting.";
        return flight();
    }
    flight object;
    object.id      = details[1].toInt();
    object.doft    = QDate::fromString(details[2],Qt::ISODate);
    object.dept    = details[3];
    object.dest    = details[4];
    object.tofb    = QTime::fromString(details[5],"hh:mm");
    object.tonb    = QTime::fromString(details[6],"hh:mm");
    object.pic     = details[7];
    object.acft    = details[8];
    object.tblk    = QTime::fromString(details[9],"hh:mm");
    object.tSPSE   = QTime::fromString(details[10],"hh:mm");
    object.tSPME   = QTime::fromString(details[11],"hh:mm");
    object.tMP     = QTime::fromString(details[12],"hh:mm");
    object.tNIGHT  = QTime::fromString(details[13],"hh:mm");
    object.tIFR    = QTime::fromString(details[14],"hh:mm");

    object.tPIC    = QTime::fromString(details[15],"hh:mm");
    object.tPICUS  = QTime::fromString(details[16],"hh:mm");
    object.tSIC    = QTime::fromString(details[17],"hh:mm");
    object.tDUAL   = QTime::fromString(details[18],"hh:mm");
    object.tFI     = QTime::fromString(details[19],"hh:mm");
    object.tSIM    = QTime::fromString(details[20],"hh:mm");

    object.pilotFlying  = details[21].toInt();
    object.toDay        = details[22].toInt();
    object.toNight      = details[23].toInt();
    object.ldgDay       = details[24].toInt();
    object.ldgNight     = details[25].toInt();
    object.autoland     = details[26].toInt();

    object.secondPilot  = details[27];
    object.thirdPilot   = details[28];
    object.approachType = details[29];
    object.flightNumber = details[30];
    object.remarks      = details[31];

    return object;
}

QVector<QString> flight::toVector(flight object)
{
    QVector<QString> vecOut(32);

    vecOut [1]  = QString::number(object.id);
    vecOut [2]  = object.doft.toString(Qt::ISODate);
    vecOut [3]  = object.dept;
    vecOut [4]  = object.dest;
    vecOut [5]  = object.tofb.toString("hh:mm");
    vecOut [6]  = object.tonb.toString("hh:mm");
    vecOut [7]  = object.pic;
    vecOut [8]  = object.acft;
    vecOut [9]  = object.tblk.toString("hh:mm");

    vecOut [10] = object.tSPSE.toString("hh:mm");
    vecOut [11] = object.tSPME.toString("hh:mm");
    vecOut [12] = object.tMP.toString("hh:mm");
    vecOut [13] = object.tNIGHT.toString("hh:mm");
    vecOut [14] = object.tIFR.toString("hh:mm");
    vecOut [15] = object.tPIC.toString("hh:mm");
    vecOut [16] = object.tPICUS.toString("hh:mm");
    vecOut [17] = object.tSIC.toString("hh:mm");
    vecOut [18] = object.tDUAL.toString("hh:mm");
    vecOut [19] = object.tFI.toString("hh:mm");
    vecOut [20] = object.tSIM.toString("hh:mm");

    vecOut [21] = QString::number(object.pilotFlying);
    vecOut [22] = QString::number(object.toDay);
    vecOut [23] = QString::number(object.toNight);
    vecOut [24] = QString::number(object.ldgDay);
    vecOut [25] = QString::number(object.ldgNight);
    vecOut [26] = QString::number(object.autoland);
    vecOut [27] = object.secondPilot;
    vecOut [28] = object.thirdPilot;
    vecOut [29] = object.approachType;
    vecOut [30] = object.flightNumber;
    vecOut [31] = object.remarks;

    return vecOut;
}
