#ifndef IEE754DOUBLEPRECISION_H
#define IEE754DOUBLEPRECISION_H

#endif // IEE754DOUBLEPRECISION_H

#include <QtGlobal>

namespace IEEE754
{

  class ReturnStruct{
  public :
  static qint64 WholePart;
  static qint64 DecPart;

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
    qint64 GenerateBinaryWholePart(qint64);

    qint64 GenerateBinaryDecimalPart(double);

  };

}
