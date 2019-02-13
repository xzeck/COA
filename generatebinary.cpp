#include "generatebinary.h"
#include <QtGlobal>
#include <QDebug>

void BIN::GenerateBinaryWholePart(qint64 WholePart)
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
  qDebug() << "Steps" << steps;
}

void BIN::GenerateBinaryDecimalPart(qint64)
{

}



