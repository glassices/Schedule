#ifndef TIMEBARWIDGET_H
#define TIMEBARWIDGET_H

#include <QFrame>
#include <QWidget>

class ScheduleView;
class QToolButton;
class QHBoxLayout;
class QVBoxLayout;
class QButtonGroup;

class TimeBarWidget : public QFrame
{
    Q_OBJECT

public:
    explicit TimeBarWidget(QWidget *parent = 0);
private:
    ScheduleView *schedule;
    QToolButton *selectModeButton;
    QToolButton *dragModeButton;
    QHBoxLayout *buttonLayout;
    QVBoxLayout *mainLayout;
    QButtonGroup *pointerModeGroup;
};

#endif // TIMEBARWIDGET_H
