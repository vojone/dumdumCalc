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
#include <QMessageBox>
#include <QUrl>
#include <QFileInfo>

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
    if(arg1.isLocalFile() && QFileInfo::exists(arg1.toLocalFile())) {
        QDesktopServices::openUrl(arg1);
    }
    else if(arg1.toString().contains(QRegExp("https://|http://|www|@"))) {
        QDesktopServices::openUrl(arg1);
    }
    else {
        QString message = "Sorry, but we can't open hyperlink...\n";
        message.append("Maybe calculator it's not installed properly.\n");
        message.append("You can also try to manually find:\n" + arg1.toString());
        QMessageBox::warning(this, "Can't open link", message);
    }

}
