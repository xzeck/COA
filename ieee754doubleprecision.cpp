#include "ieee754doubleprecision.h"
#include <QtGlobal>
#include <QDebug>
#include <QByteArray>
#include <vector>
#include <algorithm>

static IEEE754::Binary Bin;
QString IEEE754::Generation::GenerateDoublePrecision(QString Value) //Generates double precision value
{
    double RawValue = Value.toDouble(); //Get the Raw from QString and convert to Double
    qint64 RawValIntPart = static_cast<qint64>(RawValue); //Static cast RawValue to Int, to get the Integer part and remove decimal value
    double RawValueDecPart = RawValue - RawValIntPart; // Subtracting Int part from Raw value to get decimal value
    QString Binary; //Will store binary

    qDebug() << RawValIntPart << " " <<RawValueDecPart; // for debugging purposes

    QString Whole = Bin.GenerateBinaryWholePart(RawValIntPart); //Generate Binary of the Whole part
    QString Dec = Bin.GenerateBinaryDecimalPart(RawValueDecPart); //Generate Binary of the Decimal Part

    //Formatting stuff ( If Decimal is zero, then there's no need to display)
    if(Dec == NULL)
      Binary = Whole;
    else
      Binary = Whole + "." + Dec;

    return Binary;
}


QString IEEE754::Binary::GenerateBinaryWholePart(qint64 WholePart)
{
  {
    steps = 0;
    std::vector<QString> RevBinWhole;
    QString RevString;
    IEEE754::Binary_Whole = "";

    while(WholePart != 0)
      {
        int Remainder = WholePart % 2;

        WholePart /=2;

        Binary_Whole += QString::number(Remainder);

        steps++;
      }

    for( auto x : Binary_Whole)
      {
        RevBinWhole.push_back(x);
      }
    std::reverse(RevBinWhole.begin(), RevBinWhole.end());

    for( auto x : RevBinWhole)
      {
        RevString += x;
      }

    Binary_Whole = RevString;

    qDebug() << "BinWholeRev" << Binary_Whole;


    return Binary_Whole;
  }

}

QString IEEE754::Binary::GenerateBinaryDecimalPart(double DecimalPart)
{
  double temp;
  qint64 IntegerPart;
  temp = DecimalPart;

  for(int i =0; i<=15; i++)
    {

      temp = temp * 2;
      IntegerPart = static_cast<qint64>(temp);

      temp = temp - IntegerPart;
      IEEE754::Binary_Dec = IEEE754::Binary_Dec + QString::number(IntegerPart);

    }
  qDebug() << "Binary_Dec" << Binary_Dec;

  return Binary_Dec;
}

QString IEEE754::GiveExponentBinary()
{
  IEEE754::Binary Bin;
  qint64 Exponent = 1023 + (IEEE754::steps - 1);

  qDebug() << "Steps : " << IEEE754::steps;

  IEEE754::ExponentBinary = Bin.GenerateBinaryWholePart(Exponent);

  qDebug() << "Exponent Binary = " << ExponentBinary;
  return ExponentBinary;
}

QString IEEE754::GiveMantisa(QString Value)
{
    IEEE754::Mantisa = "";
    QString replica;// = IEEE754::Binary_Whole;
    std::vector<QString> Mantisa_Vector;
    double temp = Value.toDouble();
    qint64 IntegerPart = static_cast<qint64>(temp);

    QString Replica = Bin.GenerateBinaryWholePart(IntegerPart);


    for( auto x : Replica)
      {
        Mantisa_Vector.push_back(x);
      }

    for(int i = 2; i <=Mantisa_Vector.size();i++)
      {
        replica += Mantisa_Vector[i-1];
      }

   IEEE754::Mantisa = replica;

   return IEEE754::Mantisa;
}

QString IEEE754::FinalVal()
{
    QString DoublePrecisionFormat = "";

    DoublePrecisionFormat = " " + IEEE754::ExponentBinary + " " + IEEE754::Mantisa + IEEE754::Binary_Dec;

    qDebug() << "Final : " << DoublePrecisionFormat;

    return DoublePrecisionFormat;
}
