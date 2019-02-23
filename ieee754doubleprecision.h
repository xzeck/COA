#ifndef IEE754DOUBLEPRECISION_H
#define IEE754DOUBLEPRECISION_H

#endif // IEE754DOUBLEPRECISION_H

#include <QtGlobal>
#include <QString>


  extern qint64 steps;
  extern QString Binary_Whole;
  extern QString Binary_Dec;
  extern QString Mantisa;
  extern QString ExponentBinary;
  extern QString Binary_Final;


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


