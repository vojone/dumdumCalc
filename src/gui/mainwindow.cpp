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
#include <QMessageBox>
#include <QClipboard>

#define SHOW_NUM 12
#define INF_COLOR "blue"
#define ERR_COLOR "red"


#define NUM2QSTR(num) (QString().setNum(num, 'g', SHOW_NUM)) /**< Converts num (int/double/float...) to QString */


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
 * @brief Overload which Edits the variable storing the operand value and updates the display
 * @param str QString which will be appended to the screen!
 */
void MainWindow::insert_to_screen(QString str){
    if(resultShown){
        resultShown = false;
        content = "";
        currentOperation = None;
    }
    content+=str;
    update_screen();
}

/**
 * @brief Updates the display content
 */
void MainWindow::update_screen(){
    if(currentOperation != None){
        if(!resultShown) {
            ui->textEdit->setHtml(NUM2QSTR(operand1) + currentOperationSymbol + "<h1 style='margin-top:-10px'>" + content + "</h1>");
        }
        else{
            if(currentOperation == Factorial) {
                ui->textEdit->setHtml(NUM2QSTR(operand1) + currentOperationSymbol + "=<h1 style='margin-top:-10px'>" + content + "</h1>");
            }
            else {
                QString op2str = NUM2QSTR(operand2);
                if(operand2 < 0)
                    op2str = "("+op2str+")";
                ui->textEdit->setHtml(NUM2QSTR(operand1) + currentOperationSymbol + op2str + "=<h1 style='margin-top:-10px'>" + content + "</h1>");
            }
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
        if(!resultShown) {
            ui->textEdit->setHtml(NUM2QSTR(operand1) + currentOperationSymbol + "<h1 style='margin-top:-10px'>" + content + "</h1>");
        }
        else{
            if(currentOperation == Factorial) {
                ui->textEdit->setHtml(NUM2QSTR(operand1) + currentOperationSymbol + "=<h1 style='margin-top:-10px'>" + content + "</h1>");
            }
            else {
                QString op2str = NUM2QSTR(operand2);
                if(operand2 < 0)
                    op2str = "("+op2str+")";
                ui->textEdit->setHtml(NUM2QSTR(operand1) + currentOperationSymbol + op2str + "=<h1 style='margin-top:-10px'>" + content + "</h1>");
            }
        }
    }
    else
        ui->textEdit->setPlainText(newContent);
}

/**
 * @brief Changes color of whole content of display
 * @note Color is set by default by calling update_screen()
 * @param new_color string which describes color (it excepts every format which excepts HTML)
 */
void MainWindow::change_color(QString new_color) {
    ui->textEdit->setHtml("<font color=\"" + new_color + "\">" + ui->textEdit->toHtml() + "<\font>");
}

/**
 * @brief Sets the operation type and appends the operation symbol to the display
 * @param op Operation type from the Operation Enum
 * @param symbol The symbol of the operation which will be appended to the display
 */
void MainWindow::set_operation(Operation op, QString symbol){
    //allows continous operation (starting another operation without hitting enter)
    if(operand1 && currentOperation != None && !resultShown){
        //resultShown = false;
        on_result_clicked();
    }
    operand1 = content.toDouble();
    currentOperation = op;
    currentOperationSymbol = symbol;

    resultShown = false;
    if(currentOperation != Factorial){
        content="";
        update_screen();
    }
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
 * @brief Solves, whether is number +/- infinity
 * @param number result which represents infinity
 */
void MainWindow::resIsInf(double number) {
    if(number < 0)
        content = "-Infinity";
    else
        content = "+Infinity";

    update_screen();

    change_color(INF_COLOR);
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
    //fprintf(stderr,"The current vals are: o1: %f, o2 %f, content %s\n", operand1, operand2, content.toStdString().c_str());
    if(!is_numeric(content) || content == "+Infinity" || content == "-Infinity"){
        resultShown = true;
        return;
    }
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
        change_color(ERR_COLOR);
    }
    else if(std::isinf(result)){
        resIsInf(result);
    }
    else{
        content = NUM2QSTR(result);
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
    if(resultShown)
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
 * @brief close_calc Closes calc window and all its children (help window)
 * @param ask flag that switch if you want to show question in question box
 */
void MainWindow::close_calc(bool ask = true) {
    if(ask) {
        QMessageBox::StandardButton choice;
        QString message = "Are you sure, you want to close dumdum Calculator app?\n";
        choice = QMessageBox::question(this, "Exit", message);

        if(choice == QMessageBox::No) {
            return;
        }
    }

    this->close();
}

/**
 * @brief is_numeric Checks if passed QString is a number
 * @param str The QString which is going to be checked for a number
 * @return returns true if the string is a numeric value, otherwise false
 */
bool MainWindow::is_numeric(QString str) {
    bool isNum = true;
    str.toDouble(&isNum);
    return isNum;
}

/**
 * @brief handles key press events at the main window
 * @param *event The event which will be checked if an important key was pressed
 */
void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->modifiers() && ev->modifiers() == Qt::ShiftModifier) { //key + shift
        switch (ev->key()) {
            case Qt::Key_Exclam:
                on_factiorial_clicked();
                return;
            case Qt::Key_Percent:
                on_modulo_clicked();
                return;
            case Qt::Key_BracketLeft:
                on_modulo_clicked();
                return;
        }
    }else if(ev->modifiers() && ev->modifiers() == Qt::ControlModifier) {
        switch (ev->key()) {
            case Qt::Key_V: //allows pasting numbers

                QString clipboardContent = QApplication::clipboard()->text();

                if(!is_numeric(clipboardContent))
                    return;
                insert_to_screen(clipboardContent);
        }
    }

    //key
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
        case Qt::Key_R:
            on_root_clicked();
            break;
        case Qt::Key_S:
            on_changeSign_clicked();
            break;
        case Qt::Key_P:
            on_power_clicked();
            break;
        case Qt::Key_Escape:
            close_calc(true);
            break;
        case Qt::Key_F1:
            show_help();
            break;
    }//switch()
}
