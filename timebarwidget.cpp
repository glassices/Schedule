#include "timebarwidget.h"
#include "scheduleview.h"
#include "newdialogbox.h"
#include <QPalette>
#include <QToolButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QDebug>

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
    newButton = new QToolButton;
    newButton->setText(QString("New"));
    newButton->setCheckable(true);
    newButton->setChecked(false);

    QButtonGroup *pointerModeGroup = new QButtonGroup;
    pointerModeGroup->setExclusive(true);
    pointerModeGroup->addButton(selectModeButton);
    pointerModeGroup->addButton(dragModeButton);

    schedule = new ScheduleView(this);

    buttonLayout = new QHBoxLayout;
    mainLayout = new QVBoxLayout;
    buttonLayout->addWidget(selectModeButton);
    buttonLayout->addWidget(dragModeButton);
    buttonLayout->addWidget(newButton);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(schedule);
    setLayout(mainLayout);

    connect(newButton, SIGNAL(clicked()), this, SLOT(showDialog()));
}
void TimeBarWidget::showDialog()
{
    qDebug() << 1 << endl;
    newDialogBox = new NewDialogBox;
    newButton->setChecked(false);


    newDialogBox->exec();

    delete newDialogBox;

}
