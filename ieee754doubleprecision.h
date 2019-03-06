#ifndef IEE754DOUBLEPRECISION_H
#define IEE754DOUBLEPRECISION_H

#endif // IEE754DOUBLEPRECISION_H

#include <QtGlobal>
#include <QString>


  extern qint64 Steps;
  extern QString Value;
  extern QString BinaryWhole;
  extern QString BinaryDec;
  extern QString Mantisa;
  extern QString ExponentBinary;
  extern QString BinaryFinal;
  extern bool    Sign;

   void Initializer();

   class Finalizers
   {
   public :

     QString GiveExponentBinary();
     QString GiveMantisa(QString);
     QString FinalVal();
   };



  class Generation
  {
  public :

    QString GenerateDoublePrecision(QString);

    void GenerateSinglePrecision(QString);
  };

  class Binary
  {
  public :

    QString GenerateBinaryWholePart(qint64);

    QString GenerateBinaryDecimalPart(double);
  };


