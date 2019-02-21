#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPlainTextEdit>
#include <QtDebug>
#include <QMessageBox>
#include "ieee754doubleprecision.h"


MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

//Called if the Evaluate button is clicked
void MainWindow::on_ValuePushButton_clicked()
{
  QString Value = ui->UserValue->text(); //Get text from UserValue LineEdit
  QString sign = "0";

  QRegExp re("^[a-zA-Z]"); //Regular Expression pattern, pattern checks for alphabets

  //Checking if the input string is numerical
  if(re.exactMatch(Value))
    {
      //Show error if the pattern matches, which means that there's alphabet in the given string
      QMessageBox ErrorBox;
      ErrorBox.critical(this, "Value Type Error", "Entered value is not an integer");
      ErrorBox.show();
    }
  else
    {
      IEEE754::Generation Gen; //Object of the class
      if(Value.toDouble() < 1)
        {
          sign = "1";
          ui->SignDisplayLbl->setText("1");
        }else
        {
          sign = "0";
          ui->SignDisplayLbl->setText("0");
        }

      QString Bin = Gen.GenerateDoublePrecision(Value); //Getting the binary value

      double BinVal = Bin.toDouble();

      QString Exponent = IEEE754::GiveExponentBinary();
      QString ExpString = Exponent;


      qDebug() << "Bin Val :" << BinVal;

      QString Mantisa = IEEE754::GiveMantisa(Value);
      QString Final = IEEE754::FinalVal();

      ui->BinaryDisplayLabel->setText(Bin); //Displaying the Binary Value

      ui->ExponentDisplaylbl->setText(ExpString);

      ui->MantisaDisplayLbl->setText(Mantisa+IEEE754::Binary_Dec);

      ui->IEEE754DisplayLbl->setText(sign + " " + Final);

      qDebug() << "Mantisa :" <<Mantisa;
    }

}



