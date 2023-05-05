#ifndef DEFAULTFILES_H
#define DEFAULTFILES_H

#include <QIcon>


class DefaultFiles{


public:

    //default fonts

    QFont def_font      = QFont(":/f/resources/fonts/Roboto-Regular.ttf",9);
    QFont sub_font      = QFont(":/f/resources/fonts/Roboto-Regular.ttf",11);
    QFont para_font     = QFont(":/f/resources/fonts/Roboto-Regular.ttf",13);
    QFont bold_font     = QFont(":/f/resources/fonts/Roboto-Bold.ttf",14);
    QFont label_font    = QFont(":/f/resources/fonts/Roboto-Regular.ttf",16);
    QFont header_font   = QFont(":/f/resources/fonts/Roboto-Regular.ttf",24);
    QFont btn_font      = QFont(":/f/resources/fonts/Roboto-Regular.ttf",18);

    QFont menu_font     = QFont(":/f/resources/fonts/Roboto-Bold.ttf",18);
    QFont title_font    = QFont(":/f/resources/fonts/Roboto-Bold.ttf",36);


    //default icons
    const QIcon circle_icon   = QIcon(":/i/resources/icons/circle.png");
    const QIcon dcircle_icon  = QIcon(":/i/resources/icons/circle-checked.png");
    const QIcon star_icon     = QIcon(":/i/resources/icons/star.png");
    const QIcon mstar_icon    = QIcon(":/i/resources/icons/star_fill.png");
    const QIcon more_icon     = QIcon(":/i/resources/icons/more-horizontal.png");
    const QIcon more1_icon    = QIcon(":/i/resources/icons/more-vertical.png");
    const QIcon add_b_icon    = QIcon(":/i/resources/icons/plus.png");
    const QIcon add_w_icon    = QIcon(":/i/resources/icons/add.png");
    const QIcon del_icon      = QIcon(":/i/resources/icons/cross_mark.png");
    const QIcon close_icon    = QIcon(":/i/resources/icons/chevron-right.png");
    const QIcon trash_icon    = QIcon(":/i/resources/icons/trash.png");
    const QIcon menu_icon     = QIcon(":/i/resources/icons/menu.png");
    const QIcon link_icon     = QIcon(":/i/resources/icons/link.png");

    const QIcon home_icon     = QIcon(":/i/resources/icons/sun.png");
    const QIcon bell_icon     = QIcon(":/i/resources/icons/bell.png");
    const QIcon file_icon     = QIcon(":/i/resources/icons/file.png");
    const QIcon repeat_icon   = QIcon(":/i/resources/icons/refresh-cw.png");
    const QIcon note_icon     = QIcon(":/i/resources/icons/note.png");
    const QIcon remind_icon   = QIcon(":/i/resources/icons/alarm.png");
    const QIcon due_icon      = QIcon(":/i/resources/icons/calendar-dates.png");

    //default icon size
    const QSize size           = QSize(30,30);
    const QSize size1          = QSize(25,25);
    const QSize size2          = QSize(20,20);
    const QSize size3          = QSize(15,15);
    const QSize size4          = QSize(10,10);


};

#endif // DEFAULTFILES_H
