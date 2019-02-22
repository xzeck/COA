#include "ieee754doubleprecision.h"
#include <QtGlobal>
#include <QDebug>
#include <vector>
#include <algorithm>

IEEE754::Binary Bin;

QString IEEE754::Generation::GenerateDoublePrecision(QString Value) //Generates double precision value
{
    double RawValue = Value.toDouble(); //Get the Raw from QString and convert to Double
    qint64 RawValIntPart = static_cast<qint64>(RawValue); //Static cast RawValue to Int, to get the Integer part and remove decimal value
    double RawValueDecPart = RawValue - RawValIntPart; // Subtracting Int part from Raw value to get decimal value
    QString Binary; //Will store binary

    //qDebug() << RawValIntPart << " " <<RawValueDecPart; // for debugging purposes

    QString Whole = Bin.GenerateBinaryWholePart(RawValIntPart); //Generate Binary of the Whole part
    QString Dec = Bin.GenerateBinaryDecimalPart(RawValueDecPart); //Generate Binary of the Decimal Part

    //Formatting stuff ( If Decimal is zero, then there's no need to display)
    if(Dec == nullptr)
      Binary = Whole;
    else
      Binary = Whole + "." + Dec;

    return Binary;
}


QString IEEE754::Binary::GenerateBinaryWholePart(qint64 WholePart)
{

    v.steps = 0;
    std::vector<QString> RevBinWhole;
    QString RevString;
    IEEE754::v.Binary_Whole = "";

    //Generates binary value of the whole part and counts the number of steps
    while(WholePart != 0)
      {
        int Remainder = WholePart % 2;

        WholePart /=2;

        v.Binary_Whole += QString::number(Remainder);

        v.steps++;
      }

    //Push the value to a vector
    for( auto x : v.Binary_Whole)
      {
        RevBinWhole.push_back(x);
      }
    //Reverse the vector.
    //Obviously a linked stack could be used, but this is much easier.
    std::reverse(RevBinWhole.begin(), RevBinWhole.end());

    //convert the binary value in the vector into a string
    for( auto x : RevBinWhole)
      {
        RevString += x;
      }

    //Assign to Binary_Whole so that it can be accessed anywheere in this instance
    v.Binary_Whole = RevString;

    //qDebug() << "BinWholeRev" << Binary_Whole;

    return v.Binary_Whole;
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
      IEEE754::v.Binary_Dec = IEEE754::v.Binary_Dec + QString::number(IntegerPart);

    }
  //qDebug() << "Binary_Dec" << Binary_Dec;

  return v.Binary_Dec;
}

QString IEEE754::Finalizers::GiveExponentBinary()
{
  IEEE754::Binary Bin;
  qint64 Exponent = 1023 + (IEEE754::v.steps - 1);

  //qDebug() << "Steps : " << IEEE754::steps;

  IEEE754::v.ExponentBinary = Bin.GenerateBinaryWholePart(Exponent);

  //qDebug() << "Exponent Binary = " << ExponentBinary;
  return v.ExponentBinary;
}

QString IEEE754::Finalizers::GiveMantisa(QString Value)
{
    IEEE754::v.Mantisa = "";
    QString replica;
    std::vector<QString> Mantisa_Vector;
    double temp = Value.toDouble();
    qint64 IntegerPart = static_cast<qint64>(temp);

    QString Replica = Bin.GenerateBinaryWholePart(IntegerPart);


    for( auto x : Replica)
      {
        Mantisa_Vector.push_back(x);
      }

    for(unsigned long i = 2; i<=(Mantisa_Vector.size());i++)
      {
        replica += Mantisa_Vector[i-1];
      }

   IEEE754::v.Mantisa = replica;

   return IEEE754::v.Mantisa;
}

QString IEEE754::Finalizers::FinalVal()
{
    QString DoublePrecisionFormat = "";

    DoublePrecisionFormat = " " + IEEE754::v.ExponentBinary + " " + "1" + IEEE754::v.Mantisa + IEEE754::v.Binary_Dec;

    //qDebug() << "Final : " << DoublePrecisionFormat;

    return DoublePrecisionFormat;
}
