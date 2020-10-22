#include "mmenubar.h"

MMenuBar::MMenuBar(QWidget *parent) : QMenuBar(parent)
{
    setStyleSheet("background-color: rgb(200, 200, 200)");
    setGeometry(QRect(0,30,parent->width(),28));
}
