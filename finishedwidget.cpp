#include "finishedwidget.h"
#include "sdk.h"
#include <QPalette>

FinishedWidget::FinishedWidget(QWidget *parent) :
    QWidget(parent)
{
    setMinimumHeight(gls::MINIMUM_UNDER_WIDGET);
    /* This is for frame test */
    setAutoFillBackground(true);
    QPalette myPalette;
    myPalette.setBrush(backgroundRole(), QColor(0, 255, 0));
    setPalette(myPalette);
    /* This is for frame test */
}
