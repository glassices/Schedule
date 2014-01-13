#ifndef TIMEBARWIDGET_H
#define TIMEBARWIDGET_H

#include <QFrame>
#include <QWidget>
#include <QDateTime>
#include "sdk.h"

class ScheduleView;
class QToolButton;
class QHBoxLayout;
class QVBoxLayout;
class QButtonGroup;
class NewDialogBox;

class TimeBarWidget : public QFrame
{
    Q_OBJECT

public:
    explicit TimeBarWidget(QWidget *parent = 0);
    QList<gls::Record> *showItems();
private slots:
    void showDialog();
private:
    ScheduleView *schedule;
    QToolButton *selectModeButton;
    QToolButton *dragModeButton;
    QToolButton *newButton;
    QHBoxLayout *buttonLayout;
    QVBoxLayout *mainLayout;
    QButtonGroup *pointerModeGroup;
    NewDialogBox *newDialogBox;
    QList<gls::Record> items;

    void readItems();
    void writeItems();
};

#endif // TIMEBARWIDGET_H
