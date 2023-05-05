#include "hovereffect.h"

HoverEffect::HoverEffect(QObject *parent)
    : QObject{parent}
{

}


bool HoverEffect::eventFilter(QObject *watched, QEvent *event)
{

    QEvent::Type t = event->type();

    switch(t){
    case QEvent::Enter:
        emit HoverIn(watched);
        break;
    case QEvent::Leave:
        emit HoverOut(watched);
        break;
    case QEvent::MouseButtonPress:
        emit Clicked(watched);
        break;
    case QEvent::MouseButtonDblClick:
        emit DoubleClicked(watched);
        break;
    default:
        return false;
    }

    return true;
}
