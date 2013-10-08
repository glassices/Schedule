#include "failedwidget.h"
#include <QPalette>

FailedWidget::FailedWidget(QWidget *parent) :
    QWidget(parent)
{
    /* This is for frame test */
    setAutoFillBackground(true);
    QPalette myPalette;
    myPalette.setBrush(backgroundRole(), QColor(0, 0, 255));
    setPalette(myPalette);
    /* This is for frame test */
}
