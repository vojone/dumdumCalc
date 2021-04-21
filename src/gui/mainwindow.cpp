/******************************************************************************
 *                            dumdumCalculator
 *                              mainwindow.cpp
 *
 *          Purpose: Implementation of the main window of GUI
 *
 *        Authors: Radek Marek, Vojtech Dvorak, Tomas Dvorak, Juraj Dedic
 *                       Last change: 21. 4. 2021
 *
 * ***************************************************************************/

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
#include <cmath>
#include <QKeyEvent>

/**
 * @brief MainWindow::~MainWindow MainWindow ctor
 */
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

/**
 * @brief MainWindow::~MainWindow MainWindow dtor
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief Edits the variable storing the operand value and updates the display
 * @param digit The digit which will be appended to the display
 */
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

/**
 * @brief Updates the display content
 */
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

/**
 * @brief Updates the display content with passed string
 * @param string that will be displayed in the main part of the screen
 */
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

/**
 * @brief Sets the operation type and appends the operation symbol to the display
 * @param op Operation type from the Operation Enum
 * @param symbol The symbol of the operation which will be appended to the display
 */
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

/**
 * @brief Opens the Help window
 */
void MainWindow::show_help()
{
    helpWindow = new HelpWindow(this);
    helpWindow->setWindowFlag(Qt::WindowContextHelpButtonHint, false);
    helpWindow->show();
}

/**
 * @brief Writes 0
 */
void MainWindow::on_digit0_clicked()
{
    if(content != "0")
        insert_to_screen('0');
}

/**
 * @brief Writes 1
 */
void MainWindow::on_digit1_clicked()
{
    insert_to_screen('1');
}

/**
 * @brief Writes 2
 */
void MainWindow::on_digit2_clicked()
{
    insert_to_screen('2');
}

/**
 * @brief Writes 3
 */
void MainWindow::on_digit3_clicked()
{
    insert_to_screen('3');
}

/**
 * @brief Writes 4
 */
void MainWindow::on_digit4_clicked()
{
    insert_to_screen('4');
}

/**
 * @brief Writes 5
 */
void MainWindow::on_digit5_clicked()
{
    insert_to_screen('5');
}

/**
 * @brief Writes 6
 */
void MainWindow::on_digit6_clicked()
{
    insert_to_screen('6');
}

/**
 * @brief Writes 7
 */
void MainWindow::on_digit7_clicked()
{
    insert_to_screen('7');
}

/**
 * @brief Writes 8
 */
void MainWindow::on_digit8_clicked()
{
    insert_to_screen('8');
}

/**
 * @brief Writes 9
 */
void MainWindow::on_digit9_clicked()
{
    insert_to_screen('9');
}

/**
 * @brief Adds the decimal point
 */
void MainWindow::on_point_clicked()
{
    if(!content.contains("."))
        insert_to_screen('.');
}

/**
 * @brief tryCompute tries to compute given function and return error or result
 * @param op pointer to operation to be done withc operands
 * @param op1 first operand
 * @param op2 second operand
 * @param[out] msg pointer to string that should be filled with err. msg
 * @param customMsg custom message to be returned in msg parameter if there will be an error
 * @return results of calculation or zero
 */
double tryCompute(double (*op)(double,double),
                double op1, double op2,
                QString *msg, QString customMsg = QString()) {

    double result = 0.0;

    try {
        result = op(op1, op2);
    } catch(std::runtime_error errMsg) {
        if(customMsg.isNull())
            *msg = QString(errMsg.what());
        else
            *msg = customMsg;
    }

    return result;
}

/**
 * @brief tryCompute tries to compute given function and return error or result
 * @note overloads tryCompute
 * @param op pointer to operation with one operand
 * @param op1 oparend which will be passed to the given function
 * @param[out] msg pointer to string that should be filled with err. msg
 * @param customMsg custom message to be returned in msg parameter if there will be an error
 * @return results of calculation or zero (if there will be an error)
 */
double tryCompute(double (*op)(double), double op1,
                QString *msg, QString customMsg = QString()) {

    double result = 0.0;

    try {
        result = op(op1);
    } catch(std::runtime_error errMsg) {
        if(customMsg.isNull())
            *msg = QString(errMsg.what());
        else
            *msg = customMsg;
    }

    return result;
}

/**
 * @brief Calls functions from the Math Library and shows the result
 */
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
            result = tryCompute(div, operand1, operand2, &content, "Division By 0!");
            break;
        case Power:
            result = tryCompute(f_pow, operand1, operand2, &content);
            break;
        case Root:
            result = tryCompute(root, operand1, operand2, &content);
            break;
        case Factorial:
            result = tryCompute(fact, operand1, &content);
            break;
        case Modulo:
            result = tryCompute(modulo, operand1, operand2, &content, "Modulo By 0!");
            break;
        case None:
            return;
    }
    resultShown = true;
    if(!content.isEmpty()) {
        update_screen();
    }
    else if(std::isinf(result)){
        content = "";
        update_screen("Infinity");
    }
    else{
        QString resQString = QString::number(result);
        content = resQString;
        update_screen();
    }
}

/**
 * @brief Sets the operation the addition
 */
void MainWindow::on_addition_clicked()
{
    set_operation(Addition, "+");
}

/**
 * @brief Sets the operation to substraction
 */
void MainWindow::on_substraction_clicked()
{
    set_operation(Substraction, "-");
}

/**
 * @brief Sets the operation to multiplication
 */
void MainWindow::on_multiplication_clicked()
{
    set_operation(Multiplication, "×");
}

/**
 * @brief Sets the operation to division
 */
void MainWindow::on_division_clicked()
{
    set_operation(Division,"÷");
}

/**
 * @brief Sets the operation to power
 */
void MainWindow::on_power_clicked()
{
    set_operation(Power,"^");
}

/**
 * @brief Sets the operation to factorial
 */
void MainWindow::on_factiorial_clicked()
{
    set_operation(Factorial,"!");
    on_result_clicked();
}

/**
 * @brief Sets the operation to modulo
 */
void MainWindow::on_modulo_clicked()
{
    set_operation(Modulo,"mod ");
}

/**
 * @brief Sets the operation to root
 */
void MainWindow::on_root_clicked()
{
    set_operation(Root, "√");
}

/**
 * @brief Clears the entry
 */
void MainWindow::on_clearEntry_clicked()
{
    content = "";
    update_screen();
}


/**
 * @brief Clears the input
 */
void MainWindow::on_clear_clicked()
{
    content = "";
    operand1 = 0;
    operand2 = 0;
    currentOperation = None;
    ui->textEdit->setPlainText(content);
}

/**
 * @brief Removes the last digit
 */
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

/**
 * @brief Changes the signature
 */
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

/**
 * @brief handles key press events at the main window
 * @param *event The event which will be checked if an important key was pressed
 */
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
