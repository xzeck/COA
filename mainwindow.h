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

  void on_UserValue_editingFinished();

  void on_actionFile_triggered();

private:
  Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
