#ifndef TIMEBARWIDGET_H
#define TIMEBARWIDGET_H

#include <QFrame>
#include <QWidget>

class ScheduleView;
<<<<<<< HEAD
class QToolButton;
class QHBoxLayout;
class QVBoxLayout;
class QButtonGroup;

class TimeBarWidget : public QFrame
=======

class TimeBarWidget : public QWidget
>>>>>>> develop
{
    Q_OBJECT

public:
    explicit TimeBarWidget(QWidget *parent = 0);
private:
    ScheduleView *schedule;
<<<<<<< HEAD
    QToolButton *selectModeButton;
    QToolButton *dragModeButton;
    QHBoxLayout *buttonLayout;
    QVBoxLayout *mainLayout;
    QButtonGroup *pointerModeGroup;
=======
>>>>>>> develop
};

#endif // TIMEBARWIDGET_H
