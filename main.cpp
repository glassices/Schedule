#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setOrganizationName("IIIS");
    app.setOrganizationDomain("iiis.com");
    app.setApplicationName("Schedule");
    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
