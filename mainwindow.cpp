#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mainWidget = new MainWidget(this);
    timeBarWidget = new TimeBarWidget(mainWidget);
    finishedWidget = new FinishedWidget(mainWidget);
    failedWidget = new FailedWidget(mainWidget);

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
    resize(gls::INITIAL_MAINWINDOW_WIDTH, gls::INITIAL_MAINWINDOW_HEIGHT);
    setMinimumWidth(gls::MINIMUM_MAINWINDOW_WIDTH);
    setMinimumHeight(gls::MINIMUM_MAINWINDOW_HEIGHT);
}

MainWindow::~MainWindow()
{

}
