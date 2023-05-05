#ifndef WINDOWCTRL_H
#define WINDOWCTRL_H

#include <QObject>
#include <QMouseEvent>
#include <QPoint>
#include <QMainWindow>

class WindowCtrl : public QWidget
{
    Q_OBJECT
public:

    explicit WindowCtrl(QWidget *parent = nullptr);
    ~WindowCtrl();

protected:


    QPoint cur_pos;
    QPoint new_pos;
    bool isTitleClicked = false;
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event) ;


private:
    QWidget* parent = nullptr;
    QMainWindow *mainWindow;
};

#endif // WINDOWCTRL_H
