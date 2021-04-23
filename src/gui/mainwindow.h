/******************************************************************************
 *                            dumdumCalculator
 *                              mainwindow.h
 *
 *             Purpose: Header file for the main window of the GUI
 *
 *        Authors: Radek Marek, Vojtech Dvorak, Tomas Dvorak, Juraj Dedic
 *                       Last change: 21. 4. 2021
 *
 * ***************************************************************************/

/**
 * @file mainwindow.h
 *
 * @brief Header file for the main window of the GUI
 * @authors Radek Marek, Vojtech Dvorak, Tomas Dvorak, Juraj Dedic
 */

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
    /**
     * @brief Opens the Help window
     */
    void show_help();

    /**
     * @brief Clears the input
     */
    void on_clear_clicked();

    /**
     * @brief Writes 0
     */
    void on_digit0_clicked();

    /**
     * @brief Writes 1
     */
    void on_digit1_clicked();

    /**
     * @brief Writes 2
     */
    void on_digit2_clicked();

    /**
     * @brief Writes 3
     */
    void on_digit3_clicked();

    /**
     * @brief Writes 4
     */
    void on_digit4_clicked();

    /**
     * @brief Writes 5
     */
    void on_digit5_clicked();

    /**
     * @brief Writes 6
     */
    void on_digit6_clicked();

    /**
     * @brief Writes 7
     */
    void on_digit7_clicked();

    /**
     * @brief Writes 8
     */
    void on_digit8_clicked();

    /**
     * @brief Writes 9
     */
    void on_digit9_clicked();

    /**
     * @brief Sets the operation the addition
     */
    void on_addition_clicked();

    /**
     * @brief Sets the operation to substraction
     */
    void on_substraction_clicked();

    /**
     * @brief Sets the operation to multiplication
     */
    void on_multiplication_clicked();

    /**
     * @brief Sets the operation to division
     */
    void on_division_clicked();

    /**
     * @brief Sets the operation to power
     */
    void on_power_clicked();

    /**
     * @brief Sets the operation to factorial
     */
    void on_factiorial_clicked();

    /**
     * @brief Sets the operation to modulo
     */
    void on_modulo_clicked();

    /**
     * @brief Clears the entry
     */
    void on_clearEntry_clicked();

    /**
     * @brief Adds the decimal point
     */
    void on_point_clicked();

    /**
     * @brief Removes the last digit
     */
    void on_backspace_clicked();

    /**
     * @brief Sets the operation to root
     */
    void on_root_clicked();

    /**
     * @brief Changes the signature
     */
    void on_changeSign_clicked();

    /**
     * @brief Calls functions from the Math Library and shows the result
     */
    void on_result_clicked();

private:
    Ui::MainWindow *ui;
    HelpWindow *helpWindow;
    /** \brief Defines the various operations that can be performed on this calculator */
    enum Operation {None, Addition, Substraction, Multiplication, Division, Root, Power, Factorial,  Modulo};

    /** \brief The current selected operation */
    Operation currentOperation;

    /** \brief The current selected operation symbol */
    QString currentOperationSymbol;

    /** \brief Operand 1 */
    double operand1;

    /** \brief Integer 2 */
    double operand2;

    /** \brief Main content of the display */
    QString content;

    /** \brief If the result is on the display this variable will be true */
    bool resultShown;

    /**
     * @brief handles key press events at the main window
     * @param *event The event which will be checked if an important key was pressed
     */
    void keyPressEvent(QKeyEvent *event);

    /**
     * @brief Edits the variable storing the operand value and updates the display
     * @param digit The digit which will be appended to the display
     */
    void insert_to_screen(char digit);

    /**
     * @brief Sets the operation type and appends the operation symbol to the display
     * @param op Operation type from the Operation Enum
     * @param symbol The symbol of the operation which will be appended to the display
     */
    void set_operation(Operation op, QString symbol);

    /**
     * @brief Updates the display content
     */
    void update_screen();

    /**
     * @brief Updates the display content with passed string
     * @param string that will be displayed in the main part of the screen
     */
    void update_screen(QString newContent);

    /**
     * @brief Changes color of whole content of display
     * @note Color is set by default by calling update_screen()
     * @param new_color string which describes color (it excepts every format which excepts HTML)
     */
    void change_color(QString new_color);

    /**
     * @brief Solves, whether is number +/- infinity and then shows it on the display
     * @param number result which represents infinity
     */
    void resIsInf(double number);

    /**
     * @brief close_calc Closes calc window and all its children (help window)
     * @param ask flag that switch if you want to show message in question box
     */
    void close_calc(bool ask);
};
#endif // MAINWINDOW_H
