#include "generatedoubleprecisionfloatingpoint.h"
#include "generatebinary.h"
#include <QString>
#include <QtDebug>


void DPFP::GenerateDoublePrecision(QString Value)
{
    double RawValue = Value.toDouble();
    qint64 RawValIntPart = (qint64)RawValue;
    double RawValueDecPart = RawValue - RawValIntPart;

    qDebug() << RawValIntPart << " " <<RawValueDecPart; // for debugging purposes

    BIN::GenerateBinaryWholePart(RawValIntPart);

}
