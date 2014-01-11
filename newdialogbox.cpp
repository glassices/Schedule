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
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);

    connect(checkYes, SIGNAL(clicked()), this, SLOT(accept()));
    connect(checkNo, SIGNAL(clicked()), this, SLOT(reject()));
}
