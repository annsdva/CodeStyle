#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
#define PI 3.14159265
double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_split, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_cor, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_step, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_tg, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_ctg, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_fac, SIGNAL(clicked()), this, SLOT(operations()));


    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_mult->setCheckable(true);
    ui->pushButton_split->setCheckable(true);
    ui->pushButton_cor->setCheckable(true);
    ui->pushButton_step->setCheckable(true);
    ui->pushButton_sin->setCheckable(true);
    ui->pushButton_cos->setCheckable(true);
    ui->pushButton_tg->setCheckable(true);
    ui->pushButton_ctg->setCheckable(true);
    ui->pushButton_log->setCheckable(true);
    ui->pushButton_ln->setCheckable(true);
    ui->pushButton_fac->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;

    if(ui->label->text().contains(".") && button->text() == "0"){
        new_label = ui->label->text() + button->text();
    }else {

        all_numbers = (ui->label->text() + button->text()).toDouble();
        new_label = QString::number(all_numbers, 'g', 15);
    }

    ui->label->setText(new_label);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->label->text().contains('.')))
        ui->label->setText(ui->label->text() + ".");
}

void MainWindow::operations()
{
    QPushButton *button = (QPushButton *)sender();

    num_first = ui->label->text().toDouble();
    button->setChecked(true);
    ui->label->setText("");


}

double fact(int N)
{
    if(N < 0)
        return 0;
    if (N == 0)
        return 1;
    else
        return N * fact(N - 1);
}

void MainWindow::on_pushButton_equal_clicked()
{
    double labelNumber, num_second;
    int step;
    QString new_label;

    num_second = ui->label->text().toDouble();
    step = ui->label->text().toInt();

    if(ui->pushButton_plus->isChecked()){
        labelNumber = num_first + num_second;
        new_label = QString::number(labelNumber, 'g', 15);

        ui->label->setText(new_label);
        ui->pushButton_plus->setChecked(false);

    }else if(ui->pushButton_minus->isChecked()){
        labelNumber = num_first - num_second;
        new_label = QString::number(labelNumber, 'g', 15);

        ui->label->setText(new_label);
        ui->pushButton_minus->setChecked(false);

    }else if(ui->pushButton_mult->isChecked()){
        labelNumber = num_first * num_second;
        new_label = QString::number(labelNumber, 'g', 15);

        ui->label->setText(new_label);
        ui->pushButton_mult->setChecked(false);

    }else if(ui->pushButton_split->isChecked()){
        if(num_second == 0){
            ui->label->setText("0");
        }else{
            labelNumber = num_first / num_second;
            new_label = QString::number(labelNumber, 'g', 15);

            ui->label->setText(new_label);
        }
        ui->pushButton_split->setChecked(false);

    }else if(ui->pushButton_cor->isChecked()){
        labelNumber = sqrt(num_first);
        new_label = QString::number(labelNumber, 'g', 15);

        ui->label->setText(new_label);
        ui->pushButton_cor->setChecked(false);

    }else if(ui->pushButton_step->isChecked()){
        labelNumber = pow(num_first, step);
        new_label = QString::number(labelNumber, 'g', 15);

        ui->label->setText(new_label);
        ui->pushButton_step->setChecked(false);

    }else if(ui->pushButton_cos->isChecked()){
        labelNumber = cos(num_first*PI/180);
        new_label = QString::number(labelNumber, 'g', 15);

        ui->label->setText(new_label);
        ui->pushButton_cos->setChecked(false);

    }else if(ui->pushButton_sin->isChecked()){
        labelNumber = sin(num_first*PI/180);
        new_label = QString::number(labelNumber, 'g', 15);

        ui->label->setText(new_label);
        ui->pushButton_sin->setChecked(false);

    }else if(ui->pushButton_ln->isChecked()){
        labelNumber = log(num_first);
        new_label = QString::number(labelNumber, 'g', 15);

        ui->label->setText(new_label);
        ui->pushButton_ln->setChecked(false);

    }else if(ui->pushButton_tg->isChecked()){
        labelNumber = tan(num_first*PI/180);
        new_label = QString::number(labelNumber, 'g', 15);

        ui->label->setText(new_label);
        ui->pushButton_tg->setChecked(false);

    }else if(ui->pushButton_ctg->isChecked()){
        labelNumber = 1/tan(num_first*PI/180);
        new_label = QString::number(labelNumber, 'g', 15);

        ui->label->setText(new_label);
        ui->pushButton_ctg->setChecked(false);

    }else if(ui->pushButton_fac->isChecked()){
        labelNumber = fact(num_first);
        new_label = QString::number(labelNumber, 'g', 15);

        ui->label->setText(new_label);
        ui->pushButton_fac->setChecked(false);

    }else if(ui->pushButton_log->isChecked()){
        labelNumber = log(num_first)/log(num_second);
        new_label = QString::number(labelNumber, 'g', 15);

        ui->label->setText(new_label);
        ui->pushButton_log->setChecked(false);
    }

}



void MainWindow::on_pushButton_AC_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_mult->setChecked(false);
    ui->pushButton_split->setChecked(false);
    ui->pushButton_cor->setChecked(false);
    ui->pushButton_step->setChecked(false);
    ui->pushButton_cos->setChecked(false);
    ui->pushButton_sin->setChecked(false);
    ui->pushButton_ln->setChecked(false);
    ui->pushButton_tg->setChecked(false);
    ui->pushButton_ctg->setChecked(false);
    ui->pushButton_fac->setChecked(false);
    ui->pushButton_log->setChecked(false);
    ui->label->setText("0");

}

void MainWindow::on_pushButton_last_clicked()
{
    ui->label->setText("0");
}

void MainWindow::on_pushButton_ln_clicked()
{

}

void MainWindow::on_pushButton_cor_clicked()
{

}

void MainWindow::on_pushButton_sin_clicked()
{

}

void MainWindow::on_pushButton_cos_clicked()
{

}

void MainWindow::on_pushButton_tg_clicked()
{

}

void MainWindow::on_pushButton_ctg_clicked()
{

}

void MainWindow::on_pushButton_left_clicked()
{
    ui->label->setText(ui->label->text() + "(");
}

void MainWindow::on_pushButton_right_clicked()
{
    ui->label->setText(ui->label->text() + ")");
}
