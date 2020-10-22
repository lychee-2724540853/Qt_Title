#ifndef TITLE_H
#define TITLE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

#define ButtonHeight 26
#define ButtonWidth 45

class Title : public QWidget
{
    Q_OBJECT
    QWidget * title_parent;
    QSize old_size;
    QPoint old_point;
public:
    explicit Title(QWidget *parent = nullptr);
    void initButon();
    void initConnect();

    QPushButton * MinButton;
    QPushButton * MaxButton;
    QPushButton * CloseButton;

    QLabel * TitleContent;
    QLabel * TitleIcon;

private:
    void ButtonClose();
    void ButtonMin();
    void ButtonMax();
    void setTitleSize();
    void saveWindowPosInfo();

signals:
    void signalWindowSizeChanged();

};

#endif // TITLE_H
