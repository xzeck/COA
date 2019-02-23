#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ieee754doubleprecision.h"

#include <QPlainTextEdit>
#include <QtDebug>
#include <QMessageBox>
#include <QString>


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

  Initializer();

  Finalizers Fin;
  QString Value, Bin, Exponent, ExpString, Mantisa, Final, Decimal;
  QString sign = "0";
  QRegExp re("^[a-zA-Z]"); //Regular Expression pattern, pattern checks for alphabets


  Value = ui->UserValue->text(); //Get text from UserValue LineEdit

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
      Generation Gen; //Object of the class
      if(Value.toDouble() < 1)
         {
          sign = "1";
          Value = Value.split("-")[1];
         }
      else
          sign = "0";

      Bin = Gen.GenerateDoublePrecision(Value); //Getting the binary value
      Decimal = Bin.split(".")[1];


      Exponent = Fin.GiveExponentBinary();
      ExpString = Exponent;


      Mantisa = Fin.GiveMantisa(Value);
      Final = Fin.FinalVal();


      ui->SignDisplayLbl->setText(sign);

      ui->BinaryDisplayLabel->setText(Binary_Final); //Displaying the Binary Value

      ui->ExponentDisplaylbl->setText(ExponentBinary);

      ui->MantisaDisplayLbl->setText(Mantisa+Binary_Dec);

      ui->IEEE754DisplayLbl->setText(sign + " " + Final);

      //qDebug() << "Mantisa :" <<Mantisa;
    }

}



