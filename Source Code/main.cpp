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
