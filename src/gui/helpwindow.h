/******************************************************************************
 *                            dumdumCalculator
 *                              helpwindow.h
 *
 *             Purpose: Header file for the help window of the GUI
 *
 *        Authors: Radek Marek, Vojtech Dvorak, Tomas Dvorak, Juraj Dedic
 *                       Last change: 21. 4. 2021
 *
 * ***************************************************************************/


/**
 * @file helpwindow.h
 *
 * @brief Header file for the help window of the GUI
 * @authors Radek Marek, Vojtech Dvorak, Tomas Dvorak, Juraj Dedic
 */

#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QDialog>

namespace Ui {
class HelpWindow;
}

/**
 * @brief The HelpWindow class with help information
 */
class HelpWindow : public QDialog
{
    Q_OBJECT

public:
    explicit HelpWindow(QWidget *parent = nullptr);
    ~HelpWindow();

private:
    Ui::HelpWindow *ui;
};

#endif // HELPWINDOW_H
