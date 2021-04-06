#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "helpwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionHelp_triggered();

    void on_digit0_clicked();

    void on_clear_clicked();

    void on_digit1_clicked();

    void on_digit2_clicked();

    void on_result_clicked();

    void on_addition_clicked();

    void on_digit3_clicked();

    void on_digit4_clicked();

    void on_digit5_clicked();

    void on_digit6_clicked();

    void on_digit7_clicked();

    void on_digit8_clicked();

    void on_digit9_clicked();

    void on_substraction_clicked();

    void on_multiplication_clicked();

    void on_division_clicked();

    void on_power_clicked();

    void on_factiorial_clicked();

    void on_modulo_clicked();

    void on_clearEntry_clicked();

    void on_point_clicked();

private:
    Ui::MainWindow *ui;
    HelpWindow *helpWindow;
    enum Operation {Addition, Substraction, Multiplication, Division, Root, Power, Factorial,  Modulo};
    Operation currentOperation;
    double operand1;
    double operand2;
    QString content;
    bool resultShown;

    void insert_to_screen(char digit);
    void set_operation(Operation op, QString symbol);
};
#endif // MAINWINDOW_H
