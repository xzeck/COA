#include "ieee754doubleprecision.h"
#include <QtGlobal>
#include <QDebug>
#include <vector>
#include <algorithm>


qint64 steps;
QString Binary_Whole;
QString Binary_Dec;
QString Mantisa;
QString ExponentBinary;
QString Binary_Final;

void Initializer()
{
   steps = 0;
   Binary_Whole = "";
   Binary_Dec  = "";
   Mantisa = "";
   ExponentBinary = "";
   Binary_Final = "";
}


QString Generation::GenerateDoublePrecision(QString Value) //Generates double precision value
{
    Binary Bin;
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

    Binary_Final = Binary;

    return Binary_Final;
}


QString Binary::GenerateBinaryWholePart(qint64 WholePart)
{
    steps = 0;
    std::vector<QString> RevBinWhole;
    QString RevString;
    Binary_Whole = "";

    //Generates binary value of the whole part and counts the number of steps
    while(WholePart != 0)
      {
        int Remainder = WholePart % 2;

        WholePart /=2;

        Binary_Whole += QString::number(Remainder);

        steps++;
      }

    //Push the value to a vector
    for( auto x : Binary_Whole)
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
    Binary_Whole = RevString;

    //qDebug() << "BinWholeRev" << Binary_Whole;

    return Binary_Whole;
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
      Binary_Dec = Binary_Dec + QString::number(IntegerPart);

    }
  //qDebug() << "Binary_Dec" << Binary_Dec;

  return Binary_Dec;
}

QString Finalizers::GiveExponentBinary()
{
  Binary Bin;
  qint64 Exponent = 1023 + (steps - 1);

  //qDebug() << "Steps : " << IEEE754::steps;

  ExponentBinary = Bin.GenerateBinaryWholePart(Exponent);

  //qDebug() << "Exponent Binary = " << ExponentBinary;
  return ExponentBinary;
}

QString Finalizers::GiveMantisa(QString Value)
{
    Binary Bin;
    Mantisa = "";
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

   Mantisa = replica;

   return Mantisa;
}

QString Finalizers::FinalVal()
{
    QString DoublePrecisionFormat = "";

    DoublePrecisionFormat = " " + ExponentBinary + " " + "1" + Mantisa + Binary_Dec;

    //qDebug() << "Final : " << DoublePrecisionFormat;

    return DoublePrecisionFormat;
}
