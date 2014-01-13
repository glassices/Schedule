#include "mainwindow.h"
#include <QApplication>
#include<QStyle>
#include<QFile>
#include<QTextStream>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setOrganizationName("IIIS");
    app.setOrganizationDomain("iiis.com");
    app.setApplicationName("Schedule");
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
