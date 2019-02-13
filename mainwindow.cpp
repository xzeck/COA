#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPlainTextEdit>
#include <QtDebug>
#include <QMessageBox>
#include "generatedoubleprecisionfloatingpoint.h"

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


void MainWindow::on_ValuePushButton_clicked()
{
  QString Value = ui->UserValue->text();

  QRegExp re("^[a-zA-Z]");
  if(re.exactMatch(Value))
    {
      QMessageBox ErrorBox;
      ErrorBox.critical(this, "Value Type Error", "Entered value is not an integer");
      ErrorBox.show();
    }
  else
    {
      DPFP::GenerateDoublePrecision(Value);
    }

}



