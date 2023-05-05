#include "windowctrl.h"

WindowCtrl::WindowCtrl(QWidget *parent)
    : QWidget(parent)
{

    setMouseTracking(true);
    parent = parent;

    mainWindow = qobject_cast<QMainWindow *>(parent);
}


WindowCtrl::~WindowCtrl()
{


}


void WindowCtrl::mouseMoveEvent(QMouseEvent *event)
{

    if (isTitleClicked) {
        new_pos = QPoint(event->globalPosition().toPoint() - cur_pos);
        move(x() + new_pos.x(), y() + new_pos.y());
        cur_pos = event->globalPosition().toPoint();
    }

}

void WindowCtrl::mousePressEvent(QMouseEvent *event)
{

    if(event->button() == Qt::LeftButton && mainWindow){

        QPoint mousePos = QCursor::pos();
        QPoint localPos = parent->mapFromGlobal(mousePos);
        if (localPos.y() >= 0 && localPos.y() <= 40) {
            isTitleClicked = true;
            cur_pos = event->globalPosition().toPoint();
        }else isTitleClicked = false;

    }

}
