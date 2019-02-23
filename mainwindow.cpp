#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ieee754doubleprecision.h"

#include <QPlainTextEdit>
#include <QtDebug>
#include <QMessageBox>
#include <QString>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  this->setStyleSheet("QLabel{border:2px solid #009688}; border-radius:10px");
  ui->UserValue->setStyleSheet("border:3px solid #009688; border-radius:10px");
  ui->ValuePushButton->setStyleSheet("border:2px solid #009688; border-radius:10px");
}

MainWindow::~MainWindow()
{
  delete ui;

}

bool CheckValueAndAssignSign()
{
  QRegExp re("[+-]?([0-9]*[.])?[0-9]+");

  if(!re.exactMatch(Value))
    {
      return false;
    }
  else
    {
      if(Value.toDouble() < 0)
        {
          Sign = 1;
          Value = Value.split("-")[1];
        }
      else
        {
          Sign = 0;
        }
    }

  return true;
}
//Called if the Evaluate button is clicked
void MainWindow::on_ValuePushButton_clicked()
{

  Initializer();

  Finalizers Fin;
  QString    Bin,Final;
  QRegExp    re("^[a-zA-Z]"); //Regular Expression pattern, pattern checks for alphabets


  Value = ui->UserValue->text(); //Get text from UserValue LineEdit

  //Checking if the input string is numerical
  if(false == CheckValueAndAssignSign())
    {
      //Show error if the pattern matches, which means that there's alphabet in the given string
      /*QMessageBox ErrorBox;
      ErrorBox.critical(this, "Value Type Error", "Entered value is not an integer");
      ErrorBox.show();*/

      ui->UserValue->setStyleSheet("border:3px solid #E91E63; border-radius:10px");

    }
  else
    {
      Generation Gen; //Object of the class

      Bin = Gen.GenerateDoublePrecision(Value); //Getting the binary value


      Fin.GiveExponentBinary(); //Gives the exponent binary
      Fin.GiveMantisa(Value); //Gives Mantisa Value
      Final = Fin.FinalVal(); //Gives the combined result of the Final value


      ui->SignDisplayLbl->setText(QString::number(Sign)); //Displays the sign to the label

      ui->BinaryDisplayLabel->setText(Binary_Final); //Displaying the Binary value on the label

      ui->ExponentDisplaylbl->setText(ExponentBinary); //Displays the Exponent value on the label

      ui->MantisaDisplayLbl->setText(Mantisa+BinaryDec); //Displays the Mantisa value on the label

      ui->IEEE754DisplayLbl->setText(QString::number(Sign)+ " " + ExponentBinary + " 1 " + Mantisa + BinaryDec); //Displays the entire string of value on the label

      //qDebug() << "Mantisa :" <<Mantisa;
    }

}



