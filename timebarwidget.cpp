#include "timebarwidget.h"
#include "scheduleview.h"
#include <QPalette>
#include <QToolButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QButtonGroup>

TimeBarWidget::TimeBarWidget(QWidget *parent) :
    QFrame(parent)
{
    selectModeButton = new QToolButton;
    selectModeButton->setText(QString("Select"));
    selectModeButton->setCheckable(true);
    selectModeButton->setChecked(false);
    dragModeButton = new QToolButton;
    dragModeButton->setText(QString("Drag"));
    dragModeButton->setCheckable(true);
    dragModeButton->setChecked(false);

    QButtonGroup *pointerModeGroup = new QButtonGroup;
    pointerModeGroup->setExclusive(true);
    pointerModeGroup->addButton(selectModeButton);
    pointerModeGroup->addButton(dragModeButton);

    schedule = new ScheduleView(this);

    buttonLayout = new QHBoxLayout;
    mainLayout = new QVBoxLayout;
    buttonLayout->addWidget(selectModeButton);
    buttonLayout->addWidget(dragModeButton);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(schedule);
    setLayout(mainLayout);
}
