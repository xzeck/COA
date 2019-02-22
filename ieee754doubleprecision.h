#ifndef IEE754DOUBLEPRECISION_H
#define IEE754DOUBLEPRECISION_H

#endif // IEE754DOUBLEPRECISION_H

#include <QtGlobal>
#include <QString>

namespace IEEE754
{
  static class vars
  {
  public :

    qint64 steps;
    QString Binary_Whole;
    QString Binary_Dec;
    QString Mantisa;
    QString ExponentBinary;
  }v;


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

}
