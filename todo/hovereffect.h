#ifndef HOVEREFFECT_H
#define HOVEREFFECT_H

#include <QObject>
#include <QEvent>

class HoverEffect : public QObject
{
    Q_OBJECT
public:
    explicit HoverEffect(QObject *parent = nullptr);

signals:
    void HoverIn(QObject *);
    void HoverOut(QObject *);

    void Clicked(QObject *);
    void DoubleClicked(QObject *);
protected:
    bool eventFilter(QObject *watched, QEvent *event);
};

#endif // HOVEREFFECT_H
