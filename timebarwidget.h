#ifndef TIMEBARWIDGET_H
#define TIMEBARWIDGET_H

#include <QFrame>
#include <QWidget>

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
};

#endif // TIMEBARWIDGET_H
