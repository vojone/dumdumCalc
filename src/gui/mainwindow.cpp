#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "../math_lib.h"
#include <iostream>
#include <string.h>
#include <cmath>
#include <limits>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resultShown = false;
    ui->textEdit->setAlignment(Qt::AlignRight);
    ui->textEdit->alignment();
    ui->textEdit->setFontPointSize(32);
    ui->textEdit->setReadOnly(true);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::insert_to_screen(char digit){
    if(resultShown){
        resultShown = false;
        content = "";
    }
    content+=digit;
    ui->textEdit->setPlainText(content);
}

void MainWindow::set_operation(Operation op, QString symbol){
    currentOperation = op;
    //ui->textEdit->insertPlainText(symbol);
    operand1 = content.toDouble();
    content+=symbol;
    ui->textEdit->setPlainText(content);
    content="";
}

void MainWindow::on_actionHelp_triggered()
{
    helpWindow = new HelpWindow(this);
    helpWindow->show();
}

void MainWindow::on_digit0_clicked()
{
    insert_to_screen('0');
}

void MainWindow::on_digit1_clicked()
{
    insert_to_screen('1');
}



void MainWindow::on_digit2_clicked()
{
    insert_to_screen('2');
}

void MainWindow::on_digit3_clicked()
{
    insert_to_screen('3');
}

void MainWindow::on_digit4_clicked()
{
    insert_to_screen('4');
}


void MainWindow::on_digit5_clicked()
{
    insert_to_screen('5');
}

void MainWindow::on_digit6_clicked()
{
    insert_to_screen('6');
}

void MainWindow::on_digit7_clicked()
{
    insert_to_screen('7');
}


void MainWindow::on_digit8_clicked()
{
    insert_to_screen('8');
}

void MainWindow::on_digit9_clicked()
{
    insert_to_screen('9');
}

void MainWindow::on_point_clicked()
{
    insert_to_screen('.');
}

void MainWindow::on_result_clicked()
{
    if(!currentOperation)
        return;

    //fix for repeated operation
    if(!resultShown)
        operand2 = content.toDouble();
    else
        operand1 = content.toDouble();
    content = "";
    double result = 0;
    switch (currentOperation) {
        case Addition:
            result = add(operand1, operand2);
            //fprintf(stderr,"Result is %f of (%f & %f)\n",result,operand1, operand2);
            break;
        case Substraction:
            result = sub(operand1, operand2);
            break;
        case Multiplication:
            result = mult(operand1, operand2);
            break;
        case Division:
            if(operand2 == 0){
                content = "Cannot divide by 0";
                ui->textEdit->setPlainText(content);
                content="";
                resultShown = true;
                return;
            }
            result = div(operand1, operand2);
            break;
        case Power:
            result = f_pow(operand1, operand2);
            break;
        case Root:
            result = root(operand1, operand2);
            break;
        case Factorial:
            result = fact(operand1);
            break;
        case Modulo:
            result = modulo(operand1, operand2);
            break;
        case None:
            return;
    }

    if(isnan(result)){
        content = "";
        ui->textEdit->setPlainText("Not a number");
    }else if(isinf(result)){
        content = "";
        ui->textEdit->setPlainText("Infinity");
    }else{
        QString resQString = QString::number(result);
        content = resQString;
        ui->textEdit->setPlainText(resQString);
    }

    resultShown = true;
}

void MainWindow::on_addition_clicked()
{
    set_operation(Addition, "+");
}

void MainWindow::on_substraction_clicked()
{
    set_operation(Substraction, "-");
}

void MainWindow::on_multiplication_clicked()
{
    set_operation(Multiplication, "×");
}

void MainWindow::on_division_clicked()
{
    set_operation(Division,"÷");
}

void MainWindow::on_power_clicked()
{
    set_operation(Power,"^");
}

void MainWindow::on_factiorial_clicked()
{
    set_operation(Factorial,"!");
    on_result_clicked();
}

void MainWindow::on_modulo_clicked()
{
    set_operation(Modulo,"mod ");
}

void MainWindow::on_root_clicked()
{
    set_operation(Root, "√");
}

void MainWindow::on_clearEntry_clicked()
{
    content = "";
    ui->textEdit->setPlainText(content);
}



void MainWindow::on_clear_clicked()
{
    content = "";
    operand1 = 0;
    operand2 = 0;
    currentOperation = None;
    ui->textEdit->setPlainText(content);
}

void MainWindow::on_backspace_clicked()
{
    int len = content.length();
    if(len == 0 || !isdigit(content.toStdString().at(len-1)))
        return;
    content = content.left(len-1);
    ui->textEdit->setPlainText(content);
}

void MainWindow::on_changeSign_clicked()
{
    if(content.toDouble() > 0){
        content = "-"+content;
        ui->textEdit->setPlainText(content);
    }else if(content.toDouble() < 0){
        //content[0]='+';
        content = content.remove(0,1);
        ui->textEdit->setPlainText(content);
    }
}
