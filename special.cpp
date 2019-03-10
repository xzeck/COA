#include "special.h"
#include "ui_special.h"
#include "mainwindow.h"

special::special(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::special)
{
  ui->setupUi(this);
}

special::~special()
{
  delete ui;
}



void special::on_posZero_clicked()
{


}
