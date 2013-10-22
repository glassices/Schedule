/*
 * This head file is for utility parameters or functions definition.
 * You can define your own parameters and functions here, but prefer to
 * define in your own namespace to avoid conflict.
 */

#ifndef SDK_H
#define SDK_H

/* Namespace for glassices */

namespace gls
{
    const int MINIMUM_MAINWINDOW_WIDTH = 300;
    const int MINIMUM_MAINWINDOW_HEIGHT = 500;
    const int INITIAL_MAINWINDOW_WIDTH = 900;
    const int INITIAL_MAINWINDOW_HEIGHT = 700;
    const int INITIAL_MAINWINDOW_POS_X = 100;
    const int INITIAL_MAINWINDOW_POS_Y = 100;
    const qreal TIMER_SHAFT_WIDTH = 710;
    const qreal TIMER_SHAFT_HEIGHT = 50;
    const int TIMER_SHAFT_LENGTH = 700;
    const int MINIMUM_UNDER_WIDGET = 400;
    const int TIMER_SHAFT_DELTA = 30;
}
namespace wang
{
    const qreal TASK_ITEM_HEIGHT=20;
}

#endif // SDK_H
