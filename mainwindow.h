#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void on_ValuePushButton_clicked();

  void on_actionAbout_triggered();

  void on_actionQuit_triggered();

  void on_actionAjay_Nair_triggered();

  void on_actionHrishikesh_Nair_triggered();

  void on_DarkModeCheckBox_stateChanged(int arg1);

private:
  Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
