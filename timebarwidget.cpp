#include "timebarwidget.h"
#include <QPalette>

TimeBarWidget::TimeBarWidget(QWidget *parent) :
    QWidget(parent)
{
    /* This is for frame test */
    setAutoFillBackground(true);
    QPalette myPalette;
    myPalette.setBrush(backgroundRole(), QColor(255, 0, 0));
    setPalette(myPalette);
    /* This is for frame test */
}
