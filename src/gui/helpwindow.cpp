/******************************************************************************
 *                            dumdumCalculator
 *                              helpwindow.cpp
 *
 *             Purpose: Implementation of the help window of GUI
 *
 *        Authors: Radek Marek, Vojtech Dvorak, Tomas Dvorak, Juraj Dedic
 *                       Last change: 21. 4. 2021
 *
 * ***************************************************************************/

/**
 * @file helpwindow.cpp
 *
 * @brief Implementation of the help window of GUI
 * @authors Radek Marek, Vojtech Dvorak, Tomas Dvorak, Juraj Dedic
 */

#include "helpwindow.h"
#include "ui_helpwindow.h"

/**
 * @brief HelpWindow ctor
 * @param parent parent element of created window with help
 */
HelpWindow::HelpWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpWindow)
{
    ui->setupUi(this);
}

/**
 * @brief HelpWindow dtor
 */
HelpWindow::~HelpWindow()
{
    delete ui;
}
