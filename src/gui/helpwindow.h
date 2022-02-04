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
 * @brief Window with brief help in app
 * @param parent parent element of created window with help
 */
class HelpWindow : public QDialog
{
    Q_OBJECT

public:
    explicit HelpWindow(QWidget *parent = nullptr);
    ~HelpWindow();

private slots:
    void on_textBrowser_2_anchorClicked(const QUrl &arg1);

private:
    Ui::HelpWindow *ui;
};

#endif // HELPWINDOW_H
