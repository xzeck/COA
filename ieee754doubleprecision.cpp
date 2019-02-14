#include "ieee754doubleprecision.h"
#include <QtGlobal>
#include <QDebug>

static IEEE754::Generation Gen;
static IEEE754::Binary Bin;

QString IEEE754::Generation::GenerateDoublePrecision(QString Value) //Generates double precision value
{
    double RawValue = Value.toDouble(); //Get the Raw from QString and convert to Double
    qint64 RawValIntPart = static_cast<qint64>(RawValue); //Static cast RawValue to Int, to get the Integer part and remove decimal value
    double RawValueDecPart = RawValue - RawValIntPart; // Subtracting Int part from Raw value to get decimal value
    QString Binary; //Will store binary

    qDebug() << RawValIntPart << " " <<RawValueDecPart; // for debugging purposes

    qint64 Whole = Bin.GenerateBinaryWholePart(RawValIntPart); //Generate Binary of the Whole part
    qint64 Dec = Bin.GenerateBinaryDecimalPart(RawValueDecPart); //Generate Binary of the Decimal Part

    //Formatting stuff ( If Decimal is zero, then there's no need to display)
    if(Dec == 0)
      Binary = QString::number(Whole);
    else
      Binary = QString::number(Whole) + "." + QString::number(Dec);

    return Binary;
}


qint64 IEEE754::Binary::GenerateBinaryWholePart(qint64 WholePart)
{
  {
    qint64 Binary = 0;
    int exponent = 1;
    qint64 steps = 0;

    while(WholePart != 0)
      {
        int Remainder = WholePart % 2;

        WholePart /=2;

        Binary += Remainder * exponent;
        exponent *=10;

        steps++;
      }

    qDebug() << Binary;

    return Binary;
  }

}

qint64 IEEE754::Binary::GenerateBinaryDecimalPart(double DecimalPart)
{
  double temp;
  qint64 bin = 0;
  qint64 extract;
  temp = DecimalPart;

  for(int i =0; i<=17; i++)
    {

      temp = temp * 2;
      extract = static_cast<qint64>(temp);

      temp = temp - extract;
      bin = (bin + extract) * 10;

    }

  qDebug() << bin;

  return bin;
}
