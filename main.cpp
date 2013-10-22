#include "mainwindow.h"
#include <QApplication>
#include <QSettings>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setOrganizationName("IIIS");
    app.setOrganizationDomain("iiis.com");
    app.setApplicationName("Schedule");
    QSettings setting;
    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
