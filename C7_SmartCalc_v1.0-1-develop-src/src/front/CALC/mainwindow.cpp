#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  //    step = 0.1;
  //    x_begin = -3, x_end = 3 + step;

  //    ui->widget->xAxis->setRange(-4, 4);
  //    ui->widget->yAxis->setRange(0, 9);

  //    N = (x_end - x_begin)/step + 2;

  //    for(X = x_begin; X <= x_end; x+=step){
  //        x.push_back(X);
  //        y.push_back(X*X);
  //    }

  //    ui->widget->addGraph();
  //    ui->widget->graph(0)->addData(x,y);
  //    ui->widget->replot();

  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_x_num, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_sub, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_add, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_close_brack, SIGNAL(clicked()), this,
          SLOT(operations()));
  connect(ui->pushButton_op_brack, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this,
          SLOT(on_pushButton_trig()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this,
          SLOT(on_pushButton_trig()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this,
          SLOT(on_pushButton_trig()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this,
          SLOT(on_pushButton_trig()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this,
          SLOT(on_pushButton_trig()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this,
          SLOT(on_pushButton_trig()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this,
          SLOT(on_pushButton_trig()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this,
          SLOT(on_pushButton_trig()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this,
          SLOT(on_pushButton_trig()));
  connect(ui->pushButton_graph, SIGNAL(clicked()), this,
          SLOT(on_pushButton_graph_clicked()));
  connect(ui->pushButton_dif, SIGNAL(clicked()), this,
          SLOT(on_pushButton_dif_clicked()));
  connect(ui->pushButton_anuity, SIGNAL(clicked()), this,
          SLOT(on_pushButton_anuity_clicked()));
}

MainWindow::~MainWindow() { delete ui; }
void MainWindow::digits_numbers() {
  QPushButton *button = (QPushButton *)sender();

  QString all_numbers;

  all_numbers = (ui->result_show->text() + button->text());

  ui->result_show->setText(all_numbers);
}

void MainWindow::on_pushButton_dot_clicked() {
  ui->result_show->setText(ui->result_show->text() + ".");
}

void MainWindow::operations() {
  QPushButton *button = (QPushButton *)sender();

  if (button->text() == "-") {
    ui->result_show->setText(ui->result_show->text() + "-");
  } else if (button->text() == "+") {
    ui->result_show->setText(ui->result_show->text() + "+");
  } else if (button->text() == "*") {
    ui->result_show->setText(ui->result_show->text() + "*");
  } else if (button->text() == "/") {
    ui->result_show->setText(ui->result_show->text() + "/");
  } else if (button->text() == "^") {
    ui->result_show->setText(ui->result_show->text() + "^(");
  } else if (button->text() == "(") {
    ui->result_show->setText(ui->result_show->text() + "(");
  } else if (button->text() == ")") {
    ui->result_show->setText(ui->result_show->text() + ")");
  } else if (button->text() == "mod") {
    ui->result_show->setText(ui->result_show->text() + "mod");
  }
}

void MainWindow::on_pushButton_del_clicked() { ui->result_show->clear(); }

void MainWindow::on_pushButton_trig() {
  QPushButton *button = (QPushButton *)sender();

  if (button) {
    QString buttonText = button->text();
    ui->result_show->setText(ui->result_show->text() + buttonText + "(");
  }
}

void MainWindow::on_pushButton_result_show_clicked() {
  QPushButton *button = (QPushButton *)sender();
  double x_val = ui->doubleSpinBox->value();
  if (button->text() == "=") {
    QByteArray cppstr = ui->result_show->text().toUtf8();
    char *input_char = cppstr.data();
    int err_proccesing = OK;
    double result = 0;
    err_proccesing = connect_front_in_back(input_char, &result, x_val);
    qDebug() << input_char;
    if (err_proccesing == ERROR) {
      ui->result_show->clear();
      ui->result_show->setText("Error: Calculation failed");

    } else {
      ui->result_show->clear();
      QString resultText = QString::number(result);
      ui->result_show->setText(resultText);
    }
  }
}

void MainWindow::on_pushButton_graph_clicked() {
  ui->widget->clearGraphs();
  step = 0.1;
  x_begin = ui->doubleSpinBox_2->value();
  x_end = ui->doubleSpinBox_1->value() + step;
  int err_proccesing = OK;
  double result = 0;
  double x_val = 0;
  QByteArray cppstr = ui->result_show->text().toUtf8();
  char *input_char = cppstr.data();
  ui->widget->xAxis->setRange(ui->doubleSpinBox_2->value(),
                              ui->doubleSpinBox_1->value());
  ui->widget->yAxis->setRange(ui->doubleSpinBox_4->value(),
                              ui->doubleSpinBox_3->value());

  N = (x_end - x_begin) / step + 2;

  for (x_val = x_begin; x_val <= x_end; x_val += step) {
    err_proccesing = connect_front_in_back(input_char, &result, x_val);
    if (err_proccesing != ERROR) {
      x.push_back(x_val);
      y.push_back(result);
    }
  }
  ui->widget->addGraph();
  ui->widget->graph(0)->addData(x, y);
  ui->widget->replot();
  x.clear();
  y.clear();
}

void MainWindow::on_pushButton_dif_clicked() {
  ui->monthly_payment->clear();
  ui->overpayment_on_loan->clear();
  ui->total_payout->clear();
  double sum = ui->doubleSpinBox_amount->value(), finish_sum = 0,
         tmp = ui->doubleSpinBox_amount->value();
  int srok = ui->spinBox_srok->value();
  double proc = ui->doubleSpinBox_interest->value();
  double sd = 0;
  double sp = 0;
  if (srok != 0) {
    sd = sum / (double)srok;

    double first_mounth_paymant = 0, last_mounth_paymant = 0, paymant = 0;
    for (int month = 1; month <= srok; month++) {
      sp = ((sum * (proc * 0.01)) * ((double)365 / (double)12)) / (double)365;
      paymant = sp + sd;
      qDebug() << "paymant: " << paymant;
      finish_sum += paymant;
      if (month == 1) {
        first_mounth_paymant = paymant;
      } else if (month == srok) {
        last_mounth_paymant = paymant;
      }
      sum -= sd;
      qDebug() << "sum: " << sum;
    }
    if (finish_sum > 0) {
      double over_price = finish_sum - tmp;
      QString finish_sum_str = QString::number(finish_sum, 'g', 20);
      QString first_mounth_pay = QString::number(first_mounth_paymant, 'g', 20);
      QString last_mounth_paymant_str =
          QString::number(last_mounth_paymant, 'g', 20);
      QString over_price_str = QString::number(over_price, 'g', 7);
      ui->monthly_payment->setText(first_mounth_pay + " / " +
                                   last_mounth_paymant_str);
      ui->overpayment_on_loan->setText(over_price_str);
      ui->total_payout->setText(finish_sum_str);
    }
  } else {
    ui->monthly_payment->setText("Error: Calculation ERROR");
    ui->overpayment_on_loan->setText("Error: Calculation ERROR");
    ui->total_payout->setText("Error: Calculation ERROR");
  }
}

void MainWindow::on_pushButton_anuity_clicked() {
  ui->monthly_payment->clear();
  ui->overpayment_on_loan->clear();
  ui->total_payout->clear();

  double sum = ui->doubleSpinBox_amount->value();
  double srok = ui->spinBox_srok->value();
  double proc = ui->doubleSpinBox_interest->value();
  double month_proc_rate = proc / 12.0 / 100.0;
  double mon_pay =
      (sum * month_proc_rate) / (1 - pow((1 + month_proc_rate), -srok));
  qDebug() << "mon_pay: " << mon_pay;
  double over_p = (mon_pay * srok) - sum;
  double total_p = mon_pay * srok;
  QString total_pay_str = QString::number(total_p, 'g', 7);
  QString mon_pay_str = QString::number(mon_pay, 'g', 7);
  QString over_p_str = QString::number(over_p, 'g', 7);
  ui->monthly_payment->setText(mon_pay_str);
  ui->overpayment_on_loan->setText(over_p_str);
  ui->total_payout->setText(total_pay_str);
}
