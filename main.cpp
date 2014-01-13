#include "mainwindow.h"
#include <QApplication>
<<<<<<< HEAD
#include<QStyle>
#include<QFile>
#include<QTextStream>
=======
#include <QSettings>
#include <QDebug>

>>>>>>> origin/Glassices
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setOrganizationName("IIIS");
    app.setOrganizationDomain("iiis.com");
    app.setApplicationName("Schedule");
    QSettings setting;
    MainWindow mainWindow;
    mainWindow.show();
    QFile file(":/qss/Qstylesheet.qss");
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    app.setStyleSheet(stylesheet);
    app.setStyle("macintosh");
    return app.exec();
}
