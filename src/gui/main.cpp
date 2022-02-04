/******************************************************************************
 *                            dumdumCalculator
 *                                main.cpp
 *
 *             Purpose: Implementation of main function of app
 *
 *        Authors: Radek Marek, Vojtech Dvorak, Tomas Dvorak, Juraj Dedic
 *                       Last change: 21. 4. 2021
 *
 * ***************************************************************************/

/**
 * @file main.cpp
 *
 * @brief Implementation of main function of app
 * @authors Radek Marek, Vojtech Dvorak, Tomas Dvorak, Juraj Dedic
 */


#define ICON_PATH "/usr/share/icons/dumdumcalc_small.png" /**< Path to icon (when is app installed) */

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowIcon(QIcon(ICON_PATH));
    w.show();
    return a.exec();
}
