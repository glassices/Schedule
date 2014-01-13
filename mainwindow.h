#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mainwidget.h>
#include <timebarwidget.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTableWidget>
#include <sdk.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void receiveItem(QDateTime, QString);

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void closeEvent(QCloseEvent *event);
private:
    MainWidget *mainWidget;
    TimeBarWidget *timeBarWidget;
    QTableWidget *finishedWidget;
    QTableWidget *failedWidget;
    QHBoxLayout *bottomLayout;
    QVBoxLayout *mainLayout;
    int tot_finished;
    int tot_failed;

    void readSettings();
    void writeSettings();
};

#endif // MAINWINDOW_H
