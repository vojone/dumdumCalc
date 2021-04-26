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
#include <QDesktopServices>


/**
 * @brief HelpWindow ctor
 * @param parent parent element of created window with help
 */
HelpWindow::HelpWindow(QWidget *parent) :
    ui(new Ui::HelpWindow)
{
    ui->setupUi(this);
    ui->textBrowser_2->setOpenLinks(false);
}

/**
 * @brief HelpWindow dtor
 */
HelpWindow::~HelpWindow()
{
    delete ui;
}

/**
 * @brief HelpWindow::on_textBrowser_2_anchorClicked opens user url in external app
 * @param arg1 url which will be opened
 */
void HelpWindow::on_textBrowser_2_anchorClicked(const QUrl &arg1)
{
    QDesktopServices::openUrl(arg1);
}
