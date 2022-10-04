#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digits_numbers();
    void on_pushButton_dot_clicked();
    void operations();
    void on_pushButton_equal_clicked();
    void on_pushButton_AC_clicked();
    void on_pushButton_last_clicked();
    void on_pushButton_ln_clicked();
    void on_pushButton_cor_clicked();
    void on_pushButton_sin_clicked();
    void on_pushButton_cos_clicked();
    void on_pushButton_tg_clicked();
    void on_pushButton_ctg_clicked();
    void on_pushButton_left_clicked();
    void on_pushButton_right_clicked();
};
#endif // MAINWINDOW_H
