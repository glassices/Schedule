#include "timebarwidget.h"
#include "scheduleview.h"
#include "newdialogbox.h"
#include <QPalette>
#include <QToolButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QDebug>
#include <QLineEdit>
#include <QDateTime>
#include <QDate>
#include <QTime>
#include <QSettings>

TimeBarWidget::TimeBarWidget(QWidget *parent) :
    QFrame(parent)
{
    readItems();

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
void TimeBarWidget::readItems()
{
    items.clear();
    QSettings settings;
    int size = settings.beginReadArray("items");
    for (int i = 0; i < size; i++) {
        settings.setArrayIndex(i);
        Record record;
        record.dateTime = settings.value("dateTime").toDateTime();
        record.itemName = settings.value("itemName").toString();
        items.append(record);
    }
    settings.endArray();
    qDebug() << items.size() << endl;
}
void TimeBarWidget::writeItems()
{
    QSettings settings;
    settings.beginWriteArray("items");
    for (int i = 0; i < items.size(); i++) {
        settings.setArrayIndex(i);
        settings.setValue("dateTime", items.at(i).dateTime);
        settings.setValue("itemName", items.at(i).itemName);
    }
    settings.endArray();
}
void TimeBarWidget::showDialog()
{
    newDialogBox = new NewDialogBox;
    newButton->setChecked(false);


    newDialogBox->exec();
    if (newDialogBox->result() == QDialog::Accepted) {
        qDebug() << newDialogBox->nameEdit->text() << endl;
        QDateTime datetime(QDate(newDialogBox->yearEdit->text().toInt(), 0, 0), QTime(0, 0, 0));

        Record record;
        record.dateTime = datetime;
        record.itemName = newDialogBox->nameEdit->text();
        items.append(record);
        writeItems();

        schedule->insertTask(newDialogBox->nameEdit->text(), datetime);
    }

    delete newDialogBox;
}
