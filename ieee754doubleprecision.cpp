#include "ieee754doubleprecision.h"

#include <QtGlobal>
#include <QDebug>
#include <vector>
#include <algorithm>


qint64  Steps;
QString Value;
QString BinaryWhole;
QString BinaryDec;
QString Mantisa;
QString ExponentBinary;
QString BinaryFinal;
bool    Sign;

void Initializer()
{
   Steps = 0;
   Sign  = 0;

   BinaryWhole    = "";
   BinaryDec      = "";
   Mantisa        = "";
   ExponentBinary = "";
   BinaryFinal    = "";
   Value          = "";

}


QString Generation::GenerateDoublePrecision(QString Value) //Generates double precision value
{
    Binary Bin;
    double RawValue = Value.toDouble(); //Get the Raw from QString and convert to Double
    qint64 RawValIntPart = static_cast<qint64>(RawValue); //Static cast RawValue to Int, to get the Integer part and remove decimal value
    double RawValueDecPart = RawValue - RawValIntPart; // Subtracting Int part from Raw value to get decimal value

    //qDebug() << RawValIntPart << " " <<RawValueDecPart; // for debugging purposes

    QString Whole = Bin.GenerateBinaryWholePart(RawValIntPart); //Generate Binary of the Whole part
    QString Dec = Bin.GenerateBinaryDecimalPart(RawValueDecPart); //Generate Binary of the Decimal Part

    //Formatting stuff ( If Decimal is zero, then there's no need to display)
    if(Dec == nullptr)
      BinaryFinal = Whole;
    else
      BinaryFinal = Whole + "." + Dec;

    return BinaryFinal;
}


QString Binary::GenerateBinaryWholePart(qint64 WholePart)
{
    Steps = 0;
    std::vector<QString> RevBinWhole;
    QString RevString;
    BinaryWhole = "";

    //Generates binary value of the whole part and counts the number of steps
    while(WholePart != 0)
      {
        int Remainder = WholePart % 2;

        WholePart /=2;

        BinaryWhole += QString::number(Remainder);

        Steps++;
      }

    //Push the value to a vector
    for( auto x : BinaryWhole)
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
    BinaryWhole = RevString;

    //qDebug() << "BinWholeRev" << Binary_Whole;

    return BinaryWhole;
}


QString Binary::GenerateBinaryDecimalPart(double DecimalPart)
{
  double temp;
  qint64 IntegerPart;
  temp = DecimalPart;

  for(int i =0; i<=15; i++)
    {

      temp = temp * 2;
      IntegerPart = static_cast<qint64>(temp);

      temp = temp - IntegerPart;
      BinaryDec = BinaryDec + QString::number(IntegerPart);

    }
  //qDebug() << "Binary_Dec" << Binary_Dec;

  return BinaryDec;
}


QString Finalizers::GiveExponentBinary()
{
  Binary Bin;
  qint64 Exponent = 1023 + (Steps - 1);

  //qDebug() << "Steps : " << IEEE754::steps;

  ExponentBinary = Bin.GenerateBinaryWholePart(Exponent);

  //qDebug() << "Exponent Binary = " << ExponentBinary;
  return ExponentBinary;
}


QString Finalizers::GiveMantisa(QString Value)
{
    Binary  Bin;
    QString Replica;

    double temp        = Value.toDouble();
    qint64 IntegerPart = static_cast<qint64>(temp);

    std::vector<QString> Mantisa_Vector;

    Mantisa = "";


    Replica= Bin.GenerateBinaryWholePart(IntegerPart);

    for( auto x : Replica)
      {
        Mantisa_Vector.push_back(x);
      }

    Replica = "";

    for(unsigned long i = 2; i<=(Mantisa_Vector.size());i++)
      {
        Replica += Mantisa_Vector[i-1];
      }

   Mantisa = Replica;

   return Mantisa;
}


QString Finalizers::FinalVal()
{
    QString DoublePrecisionFormat = "";

    DoublePrecisionFormat = " " + ExponentBinary + " " + "1" + Mantisa + BinaryDec;

    //qDebug() << "Final : " << DoublePrecisionFormat;

    return DoublePrecisionFormat;
}
