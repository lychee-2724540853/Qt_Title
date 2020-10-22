#include "title.h"

#include <QHBoxLayout>
#include <QDesktopWidget>
#include <QApplication>
Title::Title(QWidget *parent) : QWidget(parent)
{
    title_parent = parent;
    initButon();
    initConnect();
    setGeometry(0,0,parent->width(),28);
    //set the background color of the Tilte Bar
    //setStyleSheet("background-color: rgb(170, 250, 250)");
    setStyleSheet("background-color: rgb(255, 255, 255)");
}
/*******************initialize buttons and title content properties************/
void Title::initButon()
{
    CloseButton = new QPushButton(this);
    MaxButton = new QPushButton(this);
    MinButton = new QPushButton(this);

    TitleContent = new QLabel(this);
    TitleIcon = new QLabel(this);
    TitleContent->setText("标题");

    QHBoxLayout* mylayout = new QHBoxLayout(this);

    mylayout->addWidget(TitleIcon);
    mylayout->addWidget(TitleContent);
    mylayout->addWidget(MinButton);
    mylayout->addWidget(MaxButton);
    mylayout->addWidget(CloseButton);

    CloseButton->setFixedSize(QSize(ButtonWidth,ButtonHeight));
    MinButton->setFixedSize(QSize(ButtonWidth,ButtonHeight));
    MaxButton->setFixedSize(QSize(ButtonWidth,ButtonHeight));

    QPixmap titleIcon("../Img/title.jpg");
    TitleIcon->setPixmap(titleIcon.scaled(25,25));
    TitleIcon->setFixedSize(QSize(26,26));
    CloseButton->setIcon((QIcon)"../Img/Close.png");
    MaxButton->setIcon((QIcon)"../Img/Max0.png");
    MinButton->setIcon((QIcon)"../Img/Min.png");

    mylayout->setContentsMargins(5, 0, 0, 0);
    mylayout->setSpacing(0);
}
/******************************************************************************/

/************************initialize the connections of TitleBar****************/
void Title::initConnect()
{
    connect(CloseButton, &QPushButton::clicked, this, &Title::ButtonClose);
    connect(MinButton, &QPushButton::clicked, this, &Title::ButtonMin);
    connect(MaxButton, &QPushButton::clicked, this, &Title::ButtonMax);
    connect(this,&Title::signalWindowSizeChanged, this, &Title::setTitleSize);
}
/******************************************************************************/

/*****************************Connections**************************************/
void Title::ButtonClose()
{
    title_parent->close();
}
void Title::ButtonMin()
{
    title_parent->showMinimized();
}
void Title::ButtonMax()
{
    old_point = title_parent->pos();
    old_size = title_parent->size();
    title_parent->showMaximized();
    emit signalWindowSizeChanged();
}
void Title::setTitleSize()
{
    QRect desktopRect = QApplication::desktop()->availableGeometry();
    QRect FactRect = QRect(0, 0, desktopRect.width()-3, 28);
    this->setGeometry(FactRect);
}
