#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mainwidget.h>
#include <timebarwidget.h>
#include <finishedwidget.h>
#include <failedwidget.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <sdk.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void closeEvent(QCloseEvent *event);
private:
    MainWidget *mainWidget;
    TimeBarWidget *timeBarWidget;
    FinishedWidget *finishedWidget;
    FailedWidget *failedWidget;
    QHBoxLayout *bottomLayout;
    QVBoxLayout *mainLayout;

    void readSettings();
    void writeSettings();
};

#endif // MAINWINDOW_H
