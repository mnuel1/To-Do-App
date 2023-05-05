#ifndef NEWLIST_H
#define NEWLIST_H

#include <QVBoxLayout>
#include <QKeyEvent>
#include <QWidget>
#include <QLineEdit>

#include "hovereffect.h"

#include "pagecreator.h"
#include "defaultfiles.h"


class ListForm : public QObject
{
    Q_OBJECT

public:
    explicit ListForm(QWidget *parent)
    {
        hoverEventFilter = new HoverEffect(parent);
        connect(hoverEventFilter, SIGNAL(HoverIn(QObject*)), parent, SLOT(hoverIn(QObject*)));
        connect(hoverEventFilter, SIGNAL(HoverOut(QObject*)), parent, SLOT(hoverOut(QObject*)));
        connect(hoverEventFilter, SIGNAL(Clicked(QObject*)), parent, SLOT(clicked(QObject*)));

    }
    ~ListForm()
    {

    }
    //create the edditable new list
    QFrame* create_newlist(){
        QMargins margins(9, 0, 9, 0);
        return create_newbtn("addlist",
                             "background-color:#33393E;color:white;border-radius:4;padding: 10px",
                             0,
                             "border-radius:15;padding: 1px;",
                             "border-radius:15;\npadding:1px;\ntext-align:left;\n",
                             "New List",
                             file.size2,file.btn_font,margins);
    }
    //create the edditable add task
    QFrame* create_addtask(){
        QMargins margins(9, 0, 9, 0);
        return create_newbtn("addtask",
                             "text-align:left;padding:10px;border-radius:5px;background:white;color:black;",
                             1,
                             "border-radius:15;padding: 1px;",
                             "border-radius:15;\npadding:5px;\ntext-align:left;\n",
                             "Add Task",
                             file.size2,file.btn_font,margins);
    }

    //create the edditable add step
    QFrame* create_addstep(){
        QMargins margins(12, 9, 9, 9);
        return create_newbtn("addstep",
                             "border-radius:4px;background:white;color:black;text-align:left;",
                             1,
                             "border:0px",
                             "text-align:left",
                             "Add Step",file.size2,file.sub_font,margins);

    }



private:
    HoverEffect* hoverEventFilter;
    DefaultFiles file;

    QFrame* create_newbtn(QString frame_name,
                          QString frame_stylesheet,
                          int icontype,
                          QString add_btn_stylesheet,
                          QString linedit_stylesheet,
                          QString lineedit_text,
                          QSize size,
                          QFont font,
                          QMargins margin)
    {

        QFrame* frame = new QFrame;
        frame->installEventFilter(hoverEventFilter);
        frame->setObjectName(frame_name);
        frame->setStyleSheet(frame_stylesheet);
        QHBoxLayout* layout = new QHBoxLayout;
        layout->setContentsMargins(margin);

        QPushButton* add_btn = new QPushButton;
        add_btn->setStyleSheet(add_btn_stylesheet);
        add_btn->setIcon(icontype ? file.add_b_icon : file.add_w_icon);
        add_btn->setIconSize(size);

        QLineEdit* line = new QLineEdit;
        line->setCursor(Qt::IBeamCursor);
        line->setStyleSheet(linedit_stylesheet);
        line->setPlaceholderText(lineedit_text);
        line->setFont(font);

        layout->addWidget(add_btn,0);
        layout->addWidget(line,1);
        frame->setLayout(layout);
        return frame;
    }




};




#endif // NEWLIST_H
