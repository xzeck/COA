#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ieee754doubleprecision.h"

#include <QPlainTextEdit>
#include <QtDebug>
#include <QMessageBox>
#include <QString>
#include <QRegularExpression>
#include <QDesktopServices>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  this->setStyleSheet("background-color: #ffffff;");
  this->setStyleSheet("QLabel{border:2px solid #009688}; border-radius:10px;");
  ui->UserValue->setStyleSheet("border:3px solid #009688; border-radius:10px;");
  ui->ValuePushButton->setStyleSheet("border:2px solid #009688; border-radius:10px;");
  ui->DarkModeCheckBox->setCheckState(Qt::CheckState::Checked);

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

      ui->UserValue->setStyleSheet("border:3px solid #E91E63; border-radius:10px");
      ui->ValuePushButton->setStyleSheet("border:3px solid #E91E63; border-radius:10px");
      ui->UserValue->clear();
    }
  else
    {
      ui->ValuePushButton->setStyleSheet("border:3px solid #673AB7; border-radius:10px");
      ui->UserValue->setStyleSheet("border:3px solid #009688; border-radius:10px");

      Generation Gen; //Object of the class

      Bin = Gen.GenerateDoublePrecision(Value); //Getting the binary value


      Fin.GiveExponentBinary(); //Gives the exponent binary
      Fin.GiveMantisa(Value); //Gives Mantisa Value
      Final = Fin.FinalVal(); //Gives the combined result of the Final value


      ui->SignDisplayLbl->setText(QString::number(Sign)); //Displays the sign to the label

      ui->BinaryDisplayLabel->setText(BinaryFinal); //Displaying the Binary value on the label

      ui->ExponentDisplaylbl->setText(ExponentBinary); //Displays the Exponent value on the label

      ui->MantisaDisplayLbl->setText(Mantisa+BinaryDec); //Displays the Mantisa value on the label

      ui->IEEE754DisplayLbl->setText(QString::number(Sign)+ " " + ExponentBinary + " 1 " + Mantisa + BinaryDec); //Displays the entire string of value on the label

      //qDebug() << "Mantisa :" <<Mantisa;
    }
}




void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(2 == arg1)
      {

        this->setStyleSheet("background-color: #2C3539;");
        this->setStyleSheet("QLabel{border:2px solid #009688}; border-radius:10px;");
        ui->UserValue->setStyleSheet("border:3px solid #009688; border-radius:10px;");
        ui->ValuePushButton->setStyleSheet("border:2px solid #009688; border-radius:10px;");
      }
    else if (0 == arg1)
      {
        this->setStyleSheet("background-color: #EDF1E7;color : black");

      }
}

void MainWindow::on_actionAbout_triggered()
{

  QMessageBox Message;
  QRect  Geo = MainWindow::geometry();
  int MboxWidth = Geo.width()/4;
  int MBoxHeight = Geo.height()/4;

  int X = Geo.x() + Geo.width()/2 - (MboxWidth/2);
  int Y = Geo.y() + Geo.height()/2 - (MBoxHeight/2);
  Message.setGeometry(X,Y,MboxWidth, MBoxHeight);
  Message.setInformativeText("Project : Converting given input to IEEE 754 Double Precision Format\n\nAjay Nair : 402");
  Message.setIcon(Message.Information);
  Message.button(Message.Ok);
  Message.exec();
}

void MainWindow::on_actionGitHub_triggered()
{

  if(!QDesktopServices::openUrl(QUrl("https://github.com/xzeck/",QUrl::TolerantMode)))
    {
      QMessageBox Message;
      QRect  Geo = MainWindow::geometry();
      int MboxWidth = Geo.width()/4;
      int MBoxHeight = Geo.height()/4;

      int X = Geo.x() + Geo.width()/2 - (MboxWidth/2);
      int Y = Geo.y() + Geo.height()/2 - (MBoxHeight/2);
      Message.setGeometry(X,Y,MboxWidth, MBoxHeight);
      Message.setInformativeText("Sorry the URL cannot be opened at this instance because a browswer"\
                                 "cannot be found.\nYou can view the profile at \nhttps://github.com/xzeck/");
      Message.setIcon(Message.Information);
      Message.button(Message.Ok);
      Message.exec();
    }
}

void MainWindow::on_actionQuit_triggered()
{
    SLOT(quit());
}
