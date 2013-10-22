#include "newdialogbox.h"
#include <QToolButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextBlock>
#include <QLabel>
#include <QLineEdit>

NewDialogBox::NewDialogBox(QWidget *parent) :
    QDialog(parent)
{
    nameLabel = new QLabel(QString("name"));
    nameEdit = new QLineEdit;
    nameLayout = new QHBoxLayout;
    nameLayout->addWidget(nameLabel);
    nameLayout->addWidget(nameEdit);

    yearLabel = new QLabel(QString("year"));
    yearEdit = new QLineEdit;
    monthLabel = new QLabel(QString("month"));
    monthEdit = new QLineEdit;
    dayLabel = new QLabel(QString("day"));
    dayEdit = new QLineEdit;
    dateLayout = new QHBoxLayout;
    dateLayout->addWidget(yearLabel);
    dateLayout->addWidget(yearEdit);
    dateLayout->addWidget(monthLabel);
    dateLayout->addWidget(monthEdit);
    dateLayout->addWidget(dayLabel);
    dateLayout->addWidget(dayEdit);

    hourLabel = new QLabel(QString("hour"));
    hourEdit = new QLineEdit;
    minuteLabel = new QLabel(QString("minute"));
    minuteEdit = new QLineEdit;
    timeLayout = new QHBoxLayout;
    timeLayout->addWidget(hourLabel);
    timeLayout->addWidget(hourEdit);
    timeLayout->addWidget(minuteLabel);
    timeLayout->addWidget(minuteEdit);

    checkYes = new QToolButton(this);
    checkYes->setText(QString("yes"));
    checkYes->setCheckable(true);
    checkYes->setChecked(false);
    checkNo = new QToolButton(this);
    checkNo->setText(QString("no"));
    checkNo->setCheckable(true);
    checkNo->setChecked(false);

    buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(checkYes);
    buttonLayout->addWidget(checkNo);

    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(nameLayout);
    mainLayout->addLayout(dateLayout);
    mainLayout->addLayout(timeLayout);
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);

    connect(checkYes, SIGNAL(clicked()), this, SLOT(accept()));
    connect(checkNo, SIGNAL(clicked()), this, SLOT(reject()));
}
