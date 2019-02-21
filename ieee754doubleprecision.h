#ifndef IEE754DOUBLEPRECISION_H
#define IEE754DOUBLEPRECISION_H

#endif // IEE754DOUBLEPRECISION_H

#include <QtGlobal>
#include <QString>

namespace IEEE754
{
   static qint64 steps;// = 0;
   static QString Binary_Whole;// = "";
   static QString Binary_Dec;// = "";
   static QString Mantisa;
   static QString ExponentBinary;

  QString GiveExponentBinary();
  QString GiveMantisa(QString);
  QString FinalVal();

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
