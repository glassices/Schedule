#include "mainwindow.h"
#include <QSettings>
#include <QPoint>
#include <QSize>
#include <QCloseEvent>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mainWidget = new MainWidget(this);
    finishedWidget = new QTableWidget(200, 2, mainWidget);
    failedWidget = new QTableWidget(200, 2, mainWidget);
    finishedWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    finishedWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Date"));
    failedWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    failedWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Date"));
    tot_finished = tot_failed = 0;
    timeBarWidget = new TimeBarWidget(mainWidget);

    /* Set the layout */
    bottomLayout = new QHBoxLayout();
    mainLayout = new QVBoxLayout();
    bottomLayout->addWidget(finishedWidget);
    bottomLayout->addWidget(failedWidget);
    mainLayout->addWidget(timeBarWidget);
    mainLayout->addLayout(bottomLayout);
    mainWidget->setLayout(mainLayout);

    /* Set the mainwindow */
    setCentralWidget(mainWidget);
    setWindowTitle("Schedule");
    //resize(gls::INITIAL_MAINWINDOW_WIDTH, gls::INITIAL_MAINWINDOW_HEIGHT);
    setMinimumWidth(gls::MINIMUM_MAINWINDOW_WIDTH);
    setMinimumHeight(gls::MINIMUM_MAINWINDOW_HEIGHT);
    readSettings();
}
MainWindow::~MainWindow()
{

}
void MainWindow::receiveItem(QDateTime datetime, QString name)
{
    failedWidget->setItem(tot_failed, 0, new QTableWidgetItem(name));
    failedWidget->setItem(tot_failed, 1, new QTableWidgetItem(datetime.toString()));
    tot_failed++;
}
void MainWindow::readSettings()
{
    QSettings settings;
    QPoint pos = settings.value("pos",
                                QPoint(gls::INITIAL_MAINWINDOW_POS_X,
                                       gls::INITIAL_MAINWINDOW_POS_Y)).toPoint();
    QSize size = settings.value("size",
                                QSize(gls::INITIAL_MAINWINDOW_WIDTH,
                                      gls::INITIAL_MAINWINDOW_HEIGHT)).toSize();
    resize(size);
    move(pos);
}
void MainWindow::writeSettings()
{
    QSettings settings;
    settings.setValue("pos", pos());
    settings.setValue("size", size());
}
void MainWindow::closeEvent(QCloseEvent *event)
{
    writeSettings();
    event->accept();
}
