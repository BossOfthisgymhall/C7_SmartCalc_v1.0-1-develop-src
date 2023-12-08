#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#ifdef __cplusplus
extern "C" {
#endif
#include "../../s21_smart_calc.h"

#ifdef __cplusplus
}
#endif
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  double x_begin, x_end, step, x_graph;
  int N;

  QVector<double> x, y;

 private slots:
  void digits_numbers();
  void on_pushButton_dot_clicked();
  void on_pushButton_result_show_clicked();
  void operations();
  void on_pushButton_del_clicked();
  void on_pushButton_trig();
  void on_pushButton_graph_clicked();
  void on_pushButton_dif_clicked();
  void on_pushButton_anuity_clicked();
};

#endif  // MAINWINDOW_H
