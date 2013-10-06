#include "finishedwidget.h"
#include <QPalette>

FinishedWidget::FinishedWidget(QWidget *parent) :
    QWidget(parent)
{
    /* This is for frame test */
    setAutoFillBackground(true);
    QPalette myPalette;
    myPalette.setBrush(backgroundRole(), QColor(0, 255, 0));
    setPalette(myPalette);
    /* This is for frame test */
}
