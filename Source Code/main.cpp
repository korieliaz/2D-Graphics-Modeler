/*!
 * \brief   Main CPP File - Team Mittens USA
 * \authors Kori Eliaz          <korieliaz@outlook.com>
 * \authors Trevor Dunham       <trevor_d@outlook.com>
 * \authors Michael Sinclair    <masinclair2@gmail.com>
 * \authors Brian Ferguson      <bferguson@gmail.com>
 * \authors Mariah Harris       <mariahh2017@gmail.com>
 * \authors Ali Bingol          <mythologyali@gmail.com>
 * \authors Peter Win           <peterzin@gmail.com>
 * \authors Braden Wurlitzer    <wurlitzerb@gmail.com>
 * \date    Fall 2018
 * \copyright Team Mittens USA
 * \copyright CS1C w/ Professor John Kath
 * \copyright Saddleback College
*/

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    /*! \brief Opens the application */
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /*! \brief Loops the application until a close event occurs */
    return a.exec();
}
