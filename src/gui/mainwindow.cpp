/**
 * @file mainwindow.cpp
 *
 * @brief Implementation of the main window of GUI
 * @authors Radek Marek, Vojtech Dvorak, Tomas Dvorak, Juraj Dedic
 */
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "../math_lib.h"
#include <iostream>
#include <string.h>
#include <QKeyEvent>


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
    currentOperation = None;

    connect(ui->menuMenu, SIGNAL(aboutToShow()), this, SLOT(show_help()));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::insert_to_screen(char digit){
    if(resultShown){
        resultShown = false;
        content = "";
        currentOperation = None;
    }
    content+=digit;
    //ui->textEdit->setPlainText(content);
    update_screen();
}

void MainWindow::update_screen(){
    if(currentOperation != None){
        if(!resultShown)
            ui->textEdit->setHtml(QString::number(operand1)+currentOperationSymbol+"<h1 style='margin-top:-10px'>"+content+"</h1>");
        else{
            QString op2str = QString::number(operand2);
            if(operand2 < 0)
                op2str = "("+op2str+")";
            ui->textEdit->setHtml(QString::number(operand1)+currentOperationSymbol+op2str+"=<h1 style='margin-top:-10px'>"+content+"</h1>");
        }
    }
    else
        ui->textEdit->setPlainText(content);
}
void MainWindow::update_screen(QString newContent){
    if(currentOperation != None){
        if(!resultShown)
            ui->textEdit->setHtml(QString::number(operand1)+currentOperationSymbol+"<h1 style='margin-top:-10px'>"+newContent+"</h1>");
        else{
            QString op2str = QString::number(operand2);
            if(operand2 < 0)
                op2str = "("+op2str+")";
            ui->textEdit->setHtml(QString::number(operand1)+currentOperationSymbol+op2str+"=<h1 style='margin-top:-10px'>"+newContent+"</h1>");
        }
    }else
        ui->textEdit->setPlainText(newContent);
}
void MainWindow::set_operation(Operation op, QString symbol){
    if(operand1 && currentOperation != None && !resultShown){
        //resultShown = false;
        on_result_clicked();
    }
    operand1 = content.toDouble();
    currentOperation = op;
    currentOperationSymbol = symbol;
    content="";

    resultShown = false;
    update_screen();
}

void MainWindow::show_help()
{
    helpWindow = new HelpWindow(this);
    helpWindow->setWindowFlag(Qt::WindowContextHelpButtonHint, false);
    helpWindow->show();
}

void MainWindow::on_digit0_clicked()
{
    if(content != "0")
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
    if(!content.contains("."))
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
                update_screen();
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
    resultShown = true;
    if(isnan(result)){
        content = "";
        update_screen("Not a number");
    }else if(isinf(result)){
        content = "";
        update_screen("Infinity");
    }else{
        QString resQString = QString::number(result);
        content = resQString;
        update_screen();
    }


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
    update_screen();
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
    if(len == 0 )
        return;
    char toBeRemoved = content.toStdString().at(len-1);
    if(!isdigit(toBeRemoved) && toBeRemoved != '.')
        return;
    content = content.left(len-1);
    update_screen();
}

void MainWindow::on_changeSign_clicked()
{
    if(content.toDouble() > 0){
        content = "-"+content;
    }else if(content.toDouble() < 0){
        //content[0]='+';
        content = content.remove(0,1);
    }
    update_screen();
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    switch (ev->key()) {
        case Qt::Key_0:
            on_digit0_clicked();
            break;
        case Qt::Key_1:
            on_digit1_clicked();
            break;
        case Qt::Key_2:
            on_digit2_clicked();
            break;
        case Qt::Key_3:
            on_digit3_clicked();
            break;
        case Qt::Key_4:
            on_digit4_clicked();
            break;
        case Qt::Key_5:
            on_digit5_clicked();
            break;
        case Qt::Key_6:
            on_digit6_clicked();
            break;
        case Qt::Key_7:
            on_digit7_clicked();
            break;
        case Qt::Key_8:
            on_digit8_clicked();
            break;
        case Qt::Key_9:
            on_digit9_clicked();
            break;
        case Qt::Key_Plus:
            on_addition_clicked();
            break;
        case Qt::Key_Minus:
            on_substraction_clicked();
            break;
        case Qt::Key_Asterisk:
        case Qt::Key_multiply:
            on_multiplication_clicked();
            break;
        case Qt::Key_Slash:
        case Qt::Key_division:
            on_division_clicked();
            break;
        case Qt::Key_Backspace:
            on_backspace_clicked();
            break;
        case Qt::Key_Enter:
        case Qt::Key_Return:
        case Qt::Key_Equal:
            on_result_clicked();
            break;
        case Qt::Key_C:
            on_clear_clicked();
            break;
        case Qt::Key_Comma:
        case Qt::Key_Period:
            on_point_clicked();
            break;
    }
}
