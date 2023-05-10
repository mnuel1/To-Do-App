#include "pagecreator.h"

PageCreator::PageCreator(QWidget *parent)
{
    hoverEventFilter = new HoverEffect(parent);

    connect(hoverEventFilter, SIGNAL(HoverIn(QObject*)), parent, SLOT(hoverIn(QObject*)));
    connect(hoverEventFilter, SIGNAL(HoverOut(QObject*)), parent, SLOT(hoverOut(QObject*)));
    connect(hoverEventFilter, SIGNAL(Clicked(QObject*)), parent, SLOT(clicked(QObject*)));
}

PageCreator::~PageCreator()
{
    delete hoverEventFilter;
}


void PageCreator::get_tasks(QVBoxLayout* layout)
{
    //place all the todays task on 'today'
    for (auto it = tasks_list.begin(); it != tasks_list.end(); ++it) {
        QDate currentDate = QDate::currentDate();
        QString dateNow = currentDate.toString("yyyy-MM-dd");
        QString date = it->first;
        QFrame* frame = it->second;
        if (date == dateNow) {
            layout->insertWidget(0,frame);
        }
    }

}

QPushButton* PageCreator::create_button(
        QString name,
        QString text,
        QIcon icon,
        QSize size,
        QFont font
        )
{
    QPushButton* button = new QPushButton(icon,text);

    button->setObjectName(name);
    button->setText(text);
    button->setIconSize(size);
    button->setFont(font);

    //install a effect filter
    button->installEventFilter(hoverEventFilter);

    return button;

}

QLabel* PageCreator::create_label(
        QString text,
        QFont font)

{
    QLabel* label = new QLabel(text);
    label->setFont(font);

    return label;

}



void PageCreator::create_page_comp(QJsonObject obj)
{
    //main vertical layout of page
    QVBoxLayout* verti_layout = new QVBoxLayout;

    verti_layout->setContentsMargins(9,0,9,9);

    //create a header
    verti_layout->addWidget(create_header_form(obj["title"].toString()),0);
    //create a line
    verti_layout->addWidget(create_line_form(),0);

    //create a content
    verti_layout->addWidget(create_content_form("tasks",
                                                obj),2);


    verti_layout->setContentsMargins(9,9,9,9);

    // main qwidget in stack
    page->setLayout(verti_layout);
}


QFrame* PageCreator::create_header_form(QString name)
{
    //header form frame
    QFrame* title_frame = new QFrame;
    title_frame->setObjectName("header_" + name);
    QFrame* title_comp_holder = new QFrame;

    QVBoxLayout* title_comp_holder_layout = new QVBoxLayout;

    title_comp_holder_layout->setContentsMargins(0,0,0,0);
    title_comp_holder_layout->setSpacing(0);

    QFrame* title_holder = new QFrame;

    QHBoxLayout* title_holder_layout = new QHBoxLayout;

    title_holder_layout->setContentsMargins(0,0,0,0);
    title_holder_layout->setSpacing(0);

    //form components
    QPushButton* icon = new QPushButton;
    icon->setText("");
    icon->setCursor(Qt::PointingHandCursor);
    icon->setObjectName("ico11_" + name);
    icon->setIconSize(defaultFile.size);
    icon->setStyleSheet("border-radius:5; padding:10px;");
    icon->installEventFilter(hoverEventFilter); // if clicked, pop up a box of icons
    icon->hide(); //hide it since there is no icon


    //title text
    QLineEdit* text_edit = new QLineEdit;
    text_edit->setObjectName("ted15_" + name);
    text_edit->setCursor(Qt::IBeamCursor);
    text_edit->setText(name);
    text_edit->setFont(defaultFile.header_font);
    text_edit->setStyleSheet("padding:6px;border-radius:2;");
    text_edit->setReadOnly(true);
    text_edit->installEventFilter(hoverEventFilter);

    title_holder_layout->addWidget(icon);
    title_holder_layout->addWidget(text_edit);

    title_holder->setLayout(title_holder_layout);

    QPushButton* menu = create_button("men0_" + name, "",defaultFile.menu_icon,QSize(20,20),QFont());
    menu->setCursor(Qt::PointingHandCursor);
    menu->setStyleSheet("border-radius: 5; padding: 5px;");

    title_comp_holder_layout->addWidget(menu);
    title_comp_holder_layout->addWidget(title_holder);

    QLayoutItem *item = title_comp_holder_layout->itemAt(0);
    item->setAlignment(Qt::AlignLeft);

    title_comp_holder->setLayout(title_comp_holder_layout);

    //create setting button
    QPushButton* settings_btn = create_button("set3_" + name,
                                              "",
                                              defaultFile.more_icon,
                                              defaultFile.size,
                                              QFont());
    settings_btn->setStyleSheet("border-radius: 5px;  padding: 3px;\n");
    settings_btn->setCursor(Qt::PointingHandCursor);

    //horizontal layout for the header form(title spacer button)
    QHBoxLayout* hori_layout = new QHBoxLayout;

    hori_layout->addWidget(title_comp_holder);
    hori_layout->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding));
    hori_layout->addWidget(settings_btn);

    //set the layout in the title frame/header form
    title_frame->setLayout(hori_layout);

    return title_frame;
}
QFrame* PageCreator::create_line_form()
{
    QFrame* line = new QFrame;
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    return line;

}

QFrame* PageCreator::create_content_form(
        QString name,
        QJsonObject obj )
{
    //content form
    QFrame* content_frame = new QFrame;
    content_frame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //content form v layout
    QVBoxLayout* content_frame_v_layout = new QVBoxLayout;

    //scroll area
    QScrollArea* scroll_area = new QScrollArea;
    scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scroll_area->setStyleSheet("QScrollArea{border:0px}");

    //scroll area widgets content
    QWidget* scroll_area_widgets = new QWidget;

    //scroll area v layout
    QVBoxLayout* scroll_v_layout = new QVBoxLayout;
    scroll_v_layout->setContentsMargins(0,0,0,0);

    //widgets holder frame
    QFrame* content_widget_frame = new QFrame;

    //layout for content_widget_frame
    QVBoxLayout* content_widget_frame_v_layout = new QVBoxLayout;
    content_widget_frame_v_layout->setContentsMargins(0,0,0,0);
    content_widget_frame_v_layout->setSpacing(9);

    //perform to add the contents
    QJsonArray arr = obj[name].toArray(); //extract the array in the obj
    widget_adder(arr, content_widget_frame_v_layout);

    //create a spacer and add it in layout
    content_widget_frame_v_layout->addItem(new QSpacerItem(20, 40, QSizePolicy::Expanding,QSizePolicy::Expanding));

    //set the layout for content widget frame
    content_widget_frame->setLayout(content_widget_frame_v_layout);

    //add the content widget frame || widgets holder
    scroll_v_layout->addWidget(content_widget_frame);

    //setting layout of scroll area widgets
    scroll_area_widgets->setLayout(scroll_v_layout);

    //set the scroll area widget
    scroll_area->setWidgetResizable(true);
    scroll_area->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    scroll_area->setWidget(scroll_area_widgets);

    //add the content widget frame
    content_frame_v_layout->addWidget(scroll_area);

    //add a add task btn in content frame v layout
    QFrame* addtask_btn = create_addtaskbtn(name);

    addtask_btn->setStyleSheet("text-align:left;padding:10px;border-radius:5px;background:white;color:black;");
    addtask_btn->setCursor(Qt::PointingHandCursor);

    content_frame_v_layout->addWidget(addtask_btn);

    //set the layout of content frame
    content_frame->setLayout(content_frame_v_layout);

    return content_frame;
}

QFrame* PageCreator::create_addtaskbtn(QString name)
{
    QFrame* add_btn = new QFrame;
    add_btn->setObjectName("add10_" + name);
    add_btn->setStyleSheet("text-align:left;padding:10px;border-radius:5px;background:white;color:black;;");
    add_btn->installEventFilter(hoverEventFilter);
    add_btn->setCursor(Qt::PointingHandCursor);

    QHBoxLayout* add_btn_l = new QHBoxLayout;
    add_btn_l->setContentsMargins(9,0,9,0);

    QPushButton* icon = new QPushButton;
    icon->setStyleSheet("border-radius:15;padding: 1px;");

    icon->setIcon(defaultFile.add_b_icon);
    icon->setIconSize(defaultFile.size2);

    QLineEdit* text = new QLineEdit;
    text->setPlaceholderText("Add Task");
    text->setCursor(Qt::PointingHandCursor);
    text->setStyleSheet("border-radius:15;\npadding:5px;\ntext-align:left;\n");
    text->setFont(defaultFile.btn_font);

    add_btn_l->addWidget(icon,0);
    add_btn_l->addWidget(text,1);

    add_btn->setLayout(add_btn_l);

    return add_btn;
}

QFrame* PageCreator::create_widget_btn(List::task tasks)
{
    //to edit the widget task
    //access the widget_btn_frame
    //should be access by its name
    //main widget frame

    QFrame* widget_btn_frame = new QFrame;
    widget_btn_frame->setCursor(Qt::PointingHandCursor);
    widget_btn_frame->setStyleSheet("background:white;color:black;border-radius:5;");
    widget_btn_frame->setObjectName("wid4_" + tasks.task_name);

    widget_btn_frame->installEventFilter(hoverEventFilter);

    //main widget frame layout
    QHBoxLayout* comp_widget_frame_hlayout = new QHBoxLayout;
    comp_widget_frame_hlayout->setContentsMargins(9,9,9,9);

    //create the circle check box
    QPushButton* circle_btn = create_button("cir5_" + tasks.task_name,
                                            "",
                                            tasks.is_done ? defaultFile.dcircle_icon : defaultFile.circle_icon,
                                            QSize(20,20),
                                            QFont());
    circle_btn->setStyleSheet("border:0px");

    //text comp frame
    QFrame* comp_text_frame = new QFrame;

    //text comp frame layout
    QVBoxLayout* comp_text_frame_vlayout = new QVBoxLayout;
    comp_text_frame_vlayout->setContentsMargins(5,5,5,5);

    //title task name label
    QLabel* title_label = new QLabel;
    title_label->setText(tasks.task_name);
    title_label->setFont(defaultFile.label_font);

    //etc text frame
    QFrame* etc_text_frame = new QFrame;
    etc_text_frame->setFont(defaultFile.sub_font);

    // etc text frame layout
    QHBoxLayout* etc_text_frame_hlayout = new QHBoxLayout;
    etc_text_frame_hlayout->setContentsMargins(5,5,5,5);
    etc_text_frame_hlayout->setSpacing(9);

    //convert the date
    QDateTime dateTime = QDateTime::fromString(tasks.due_date, Qt::ISODateWithMs);
    QString due_date = dateTime.toString("ddd, MMM, d yyyy");


    //add the text label
    etc_text_frame_hlayout->addWidget(new QLabel(QString::number(tasks.finish_step) + " of " + QString::number(tasks.step_num)));
    etc_text_frame_hlayout->addWidget(new QLabel(due_date));


    //change name and add a bullet style? or any stlye in displaying these icons
    if(tasks.add_to_today) etc_text_frame_hlayout->addWidget(create_button("aTh","",defaultFile.home_icon,QSize(10,10),QFont()));
    if(tasks.is_important) etc_text_frame_hlayout->addWidget(create_button("imp","",defaultFile.bell_icon,QSize(10,10),QFont()));
    if(tasks.is_remind)    etc_text_frame_hlayout->addWidget(create_button("rem","",defaultFile.remind_icon,QSize(10,10),QFont()));
    if(tasks.is_repeat)    etc_text_frame_hlayout->addWidget(create_button("rep","",defaultFile.repeat_icon,QSize(10,10),QFont()));
    if(!tasks.note.isEmpty()) etc_text_frame_hlayout->addWidget(create_button("not","",defaultFile.note_icon,QSize(10,10),QFont()));
    if(tasks.file_num != 0) etc_text_frame_hlayout->addWidget(create_button("fil","",defaultFile.file_icon,QSize(10,10),QFont()));
    etc_text_frame_hlayout->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding));

    //sets the layout for the etc text frame
    etc_text_frame->setLayout(etc_text_frame_hlayout);

    //add the text widgets
    comp_text_frame_vlayout->addWidget(title_label);
    comp_text_frame_vlayout->addWidget(etc_text_frame);


    //create the favorite button
    QPushButton* star_btn = create_button("sta6_" + tasks.task_name,
                                          "",
                                          tasks.is_important? defaultFile.mstar_icon :defaultFile.star_icon,
                                          defaultFile.size,
                                          QFont());

    //add the components in the main layout
    comp_widget_frame_hlayout->addWidget(circle_btn,0);
    comp_widget_frame_hlayout->addWidget(comp_text_frame,2);
    comp_widget_frame_hlayout->addWidget(star_btn,0);

    //sets the layout of text comp frame
    comp_text_frame->setLayout(comp_text_frame_vlayout);

    //sets the layout of main widget frame
    widget_btn_frame->setLayout(comp_widget_frame_hlayout);

    tasks_list.emplace(std::make_pair(dateTime.toString("yyyy-MM-dd"),widget_btn_frame));
    return widget_btn_frame;
}

//task adder
void PageCreator::widget_adder(QJsonArray tasks,
                               QVBoxLayout* layout)
{

    for (const auto& taskItem : tasks) {
        QJsonObject taskObj = taskItem.toObject();

        QJsonArray steps    = taskObj["steps"].toArray();
        QJsonArray files    = taskObj["attached_files"].toArray();

        List::task tasks;

        tasks.task_id       = taskObj["task_id"].toInt();
        tasks.task_name     = taskObj["task_name"].toString();
        tasks.is_important  = taskObj["important"].toBool();
        tasks.add_to_today  = taskObj["add_to_today"].toBool();
        tasks.is_remind     = taskObj["remind"].toBool();
        tasks.is_repeat     = taskObj["repeat"].toBool();
        tasks.is_done       = taskObj["done"].toBool();

        tasks.due_date      = taskObj["due_date"].toString();
        tasks.note          = taskObj["note"].toString();

        tasks.finish_step   = 0;
        tasks.step_num      = steps.size();
        tasks.file_num      = files.size();

        //create the widget btn
        //add it in the layout
        layout->insertWidget(0,create_widget_btn(tasks));


        //add a error handler

    }
}
//steps adder
void PageCreator::steps_adder(QJsonArray steps,                           
                              QVBoxLayout *layout)
{

    for (const auto& stepItem : steps) {
        QJsonObject stepObj = stepItem.toObject();

        QString stepName = stepObj["step"].toString();

        layout->addWidget(create_step(stepName,0,stepObj["done"].toBool(),false));

    }
}
//files adder
void PageCreator::files_adder(QJsonArray files,
                              QVBoxLayout * layout)
{
    for (const auto& fileItem : files) {
        QJsonObject fileObj = fileItem.toObject();

        QString fileName = fileObj["file"].toString();

        layout->addWidget(new QLabel(fileName));

    }

}

QFrame* PageCreator::create_step(QString text,bool is_mainstep,bool is_done, bool is_imp)
{
    QFrame* step = new QFrame;
    step->setObjectName("step16_" + text);
    step->installEventFilter(hoverEventFilter);
    step->setStyleSheet("padding:6px;border-radius:2;");
    step->setCursor(Qt::PointingHandCursor);

    QHBoxLayout* step_l = new QHBoxLayout;

    if(!is_mainstep){
        step_l->setContentsMargins(12,9,12,9);
        step->setObjectName("step12_" + text);
    }

    QSize size = is_mainstep ? defaultFile.size1 : defaultFile.size2;
    QFont font = is_mainstep ? defaultFile.para_font : defaultFile.sub_font;
    QString name = is_mainstep ? "fav6_" : "del9_";

    QPushButton* check_box = new QPushButton;
    check_box->setObjectName("che5_" + text);
    check_box->installEventFilter(hoverEventFilter);
    check_box->setStyleSheet("border:0px;");
    check_box->setCursor(Qt::PointingHandCursor);
    if(is_done){
        check_box->setIcon(defaultFile.dcircle_icon);
    }else check_box->setIcon(defaultFile.circle_icon);

    check_box->setIconSize(size);

    QLineEdit* step_text = new QLineEdit;
    step_text->setObjectName("tex12_" + text);
    step_text->setStyleSheet("text-align:left;padding:2px;border-radius:2;");
    step_text->setFont(font);
    step_text->setText(text);
    step_text->setReadOnly(true);

    QPushButton* fav_btn = new QPushButton;
    fav_btn->setObjectName(name + text );
    fav_btn->installEventFilter(hoverEventFilter);
    fav_btn->setStyleSheet("border:0px;");
    fav_btn->setCursor(Qt::PointingHandCursor);

    if(is_imp && is_mainstep){
        fav_btn->setIcon(defaultFile.mstar_icon);
    }else if(!is_imp && is_mainstep){
        fav_btn->setIcon(defaultFile.star_icon);
    }else {
        fav_btn->setIcon(defaultFile.del_icon);
    }

    fav_btn->setIconSize(size);

    step_l->addWidget(check_box);
    step_l->addWidget(step_text);
    step_l->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding));
    step_l->addWidget(fav_btn);

    step->setLayout(step_l);

    return step;

}
QFrame* PageCreator::create_addstepbtn(QString name)
{
    QFrame* add_btn = new QFrame;
    add_btn->setObjectName("add14_" + name);
    add_btn->setStyleSheet("border-radius:4px;background:white;color:black;text-align:left;");
    add_btn->installEventFilter(hoverEventFilter);
    add_btn->setCursor(Qt::PointingHandCursor);

    QHBoxLayout* add_btn_l = new QHBoxLayout;
    add_btn_l->setContentsMargins(12,9,9,9);

    QPushButton* icon = new QPushButton;
    icon->setStyleSheet("border:0px");

    icon->setIcon(defaultFile.add_b_icon);
    icon->setIconSize(defaultFile.size2);

    QLabel* text = new QLabel;
    text->setCursor(Qt::IBeamCursor);
    text->setStyleSheet("text-align:left");
    text->setText("Add Step");
    text->setFont(defaultFile.sub_font);

    add_btn_l->addWidget(icon,0);
    add_btn_l->addWidget(text,1);

    add_btn->setLayout(add_btn_l);

    return add_btn;
}
QFrame* PageCreator::create_addtoday(bool is_add, QString name)
{
    QFrame* addtoday = new QFrame;
    addtoday->setStyleSheet("background-color:#dee2e6;padding:2px;border-radius:2px;color:black;");
    addtoday->setCursor(Qt::PointingHandCursor);


    QHBoxLayout* addtoday_l = new QHBoxLayout;

    QPushButton* icon = new QPushButton;
    icon->setIcon(defaultFile.home_icon);
    icon->setIconSize(defaultFile.size1);

    QLabel* text = new QLabel;
    text->setText((is_add ? "Added To Today" : "Add to Today"));
    text->setStyleSheet("text-align:left");
    text->setFont(defaultFile.para_font);


    addtoday_l->addWidget(icon,0);
    addtoday_l->addWidget(text,1);


    if(is_add){
        QPushButton* del_icon = new QPushButton;

        del_icon->setObjectName("del9_" + name);
        del_icon->setIcon(defaultFile.del_icon);
        del_icon->setIconSize(defaultFile.size1);
        del_icon->setStyleSheet("border:0px");
        del_icon->installEventFilter(hoverEventFilter);
        del_icon->setCursor(Qt::PointingHandCursor);

        addtoday_l->addWidget(del_icon);
    }else addtoday_l->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding));

    addtoday->setLayout(addtoday_l);

    return addtoday;

}
QFrame* PageCreator::create_rem(bool is_rem, QString name)
{
    QFrame* rem = new QFrame;
    rem->setStyleSheet("padding:2px;border-radius:2px;color:black;");
    rem->setCursor(Qt::PointingHandCursor);


    QHBoxLayout* rem_l = new QHBoxLayout;

    QPushButton* icon = new QPushButton;
    icon->setIcon(defaultFile.remind_icon);
    icon->setIconSize(defaultFile.size1);

    QLabel* text = new QLabel;
    text->setText((is_rem ? "Remind me on" : "Remind me")); // + date
    text->setStyleSheet("text-align:left");
    text->setFont(defaultFile.para_font);

    rem_l->addWidget(icon,0);
    rem_l->addWidget(text,1);

    if(is_rem){

        QPushButton* del_icon = new QPushButton;
        del_icon->setObjectName("del9_" + name);
        del_icon->setIcon(defaultFile.del_icon);
        del_icon->setIconSize(defaultFile.size1);
        del_icon->installEventFilter(hoverEventFilter);
        del_icon->setStyleSheet("border:0px");
        del_icon->setCursor(Qt::PointingHandCursor);
        rem_l->addWidget(del_icon);

    }else rem_l->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding));

    rem->setLayout(rem_l);

    return rem;

}
QFrame* PageCreator::create_due(QString date, QString name)
{
    QFrame* due = new QFrame;
    due->setStyleSheet("padding:2px;border-radius:2px;color:black;");
    due->setCursor(Qt::PointingHandCursor);


    QHBoxLayout* due_l = new QHBoxLayout;

    QPushButton* icon = new QPushButton;
    icon->setIcon(defaultFile.due_icon);
    icon->setIconSize(defaultFile.size1);

    QLabel* text = new QLabel;
    text->setText((!date.isEmpty() ? "Due + " : "Add Due Date")); // + date
    text->setStyleSheet("text-align:left");
    text->setFont(defaultFile.para_font);

    due_l->addWidget(icon,0);
    due_l->addWidget(text,1);

    if(!date.isEmpty()){
        QPushButton* del_icon = new QPushButton;
        del_icon->setObjectName("del9_" + name);
        del_icon->setIcon(defaultFile.del_icon);
        del_icon->setIconSize(defaultFile.size1);
        del_icon->setStyleSheet("border:0px");
        del_icon->installEventFilter(hoverEventFilter);
        del_icon->setCursor(Qt::PointingHandCursor);
        due_l->addWidget(del_icon);
    }else due_l->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding));

    due->setLayout(due_l);

    return due;

}
QFrame* PageCreator::create_rep(bool is_rep, QString name)
{
    QFrame* rep = new QFrame;
    rep->setStyleSheet("padding:2px;border-radius:2px;color:black;");
    rep->setCursor(Qt::PointingHandCursor);


    QHBoxLayout* rep_l = new QHBoxLayout;

    QPushButton* icon = new QPushButton;
    icon->setIcon(defaultFile.repeat_icon);
    icon->setIconSize(defaultFile.size1);

    QLabel* text = new QLabel;
    text->setText((is_rep ? "what repeat" : "Repeat")); // + date
    text->setStyleSheet("text-align:left");
    text->setFont(defaultFile.para_font);

    rep_l->addWidget(icon,0);
    rep_l->addWidget(text,1);

    if(is_rep){
        QPushButton* del_icon = new QPushButton;
        del_icon->setObjectName("del9_" + name);
        del_icon->setIcon(defaultFile.del_icon);
        del_icon->setIconSize(defaultFile.size1);
        del_icon->setStyleSheet("border:0px");
        del_icon->installEventFilter(hoverEventFilter);
        del_icon->setCursor(Qt::PointingHandCursor);
        rep_l->addWidget(del_icon);
    }else rep_l->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding));

    rep->setLayout(rep_l);

    return rep;

}
QFrame* PageCreator::create_remduerep(bool is_rem, QString date, bool is_rep, QString name)
{
    QFrame* frame = new QFrame;
    frame->setStyleSheet("background-color:#dee2e6;padding:2px;border-radius:2px;color:black;");

    QVBoxLayout* frame_l = new QVBoxLayout;

    frame_l->setContentsMargins(0,0,0,0);

    frame_l->addWidget(create_rem(is_rem,name));
    frame_l->addWidget(create_due(date,name));
    frame_l->addWidget(create_rep(is_rep,name));

    frame->setLayout(frame_l);

    return frame;


}
QFrame* PageCreator::create_file(QJsonArray arr, QString name)
{
    QFrame* file = new QFrame;
    file->setStyleSheet("background-color:#dee2e6;padding:2px;border-radius:2px;color:black;");

    QVBoxLayout* file_l = new QVBoxLayout;
    file_l->setContentsMargins(12,9,9,9);

    files_adder(arr,file_l);

    QFrame* addfile = new QFrame;
    addfile->setObjectName("add14_" + name);
    addfile->installEventFilter(hoverEventFilter);
    QHBoxLayout* addfile_l = new QHBoxLayout;

    QPushButton* icon = new QPushButton;
    icon->setIcon(defaultFile.link_icon);
    icon->setIconSize(defaultFile.size1);

    QLabel* text = new QLabel;
    text->setText("Add File");
    text->setFont(defaultFile.sub_font);

    addfile_l->addWidget(icon,0);
    addfile_l->addWidget(text,1);

    addfile->setLayout(addfile_l);

    file_l->addWidget(addfile);

    file->setLayout(file_l);

    return file;


}
QFrame* PageCreator::create_botinfo(QString name)
{

    QFrame* bot_info = new QFrame;
    QHBoxLayout* bot_info_layout = new QHBoxLayout;

    bot_info->setStyleSheet("border-radius:2;background:#343a40;padding:2px;border:1px solid");
    bot_info->setObjectName("bot_info");

    QPushButton* close_btn = new QPushButton;
    close_btn->setObjectName("clo7_" + name);
    close_btn->setIcon(defaultFile.close_icon);
    close_btn->setIconSize(defaultFile.size1);
    close_btn->setCursor(Qt::PointingHandCursor);
    close_btn->installEventFilter(hoverEventFilter);
    close_btn->setStyleSheet("border:0px;");

    QLabel* text = new QLabel;
    text->setText("Created d,mmm, d,yyyy");//date
    text->setFont(defaultFile.para_font);

    QPushButton* del_btn = new QPushButton;
    del_btn->setObjectName("del9_" + name);
    del_btn->setIcon(defaultFile.trash_icon);
    del_btn->setIconSize(defaultFile.size1);
    del_btn->setStyleSheet("border:0px;");
    del_btn->installEventFilter(hoverEventFilter);
    del_btn->setCursor(Qt::PointingHandCursor);

    bot_info_layout->addWidget(close_btn);
    bot_info_layout->addWidget(text);
    bot_info_layout->addWidget(del_btn,1);

    bot_info->setLayout(bot_info_layout);

    return bot_info;

}

void PageCreator::parseTask(QJsonObject obj,List::task *tasks)
{
    QJsonArray steps    = obj["steps"].toArray();
    QJsonArray files    = obj["attached_files"].toArray();

    tasks->task_id       = obj["task_id"].toInt();
    tasks->task_name     = obj["task_name"].toString();
    tasks->is_done       = obj["done"].toBool();
    tasks->is_important  = obj["important"].toBool();
    tasks->add_to_today  = obj["add_to_today"].toBool();
    tasks->is_remind     = obj["remind"].toBool();
    tasks->is_repeat     = obj["repeat"].toBool();
    tasks->due_date      = obj["due_date"].toString();
    tasks->note          = obj["note"].toString();
    tasks->finish_step   = 0;
    tasks->step_num      = steps.size();
    tasks->file_num      = files.size();

}
QFrame* PageCreator::create_task_panel(QJsonObject obj)
{  
    //modify the names for this buttons

    //main frame for the third panel
    //displaying the task info
    List::task tasks;

    QFrame* task_panel = new QFrame;
    parseTask(obj, &tasks);

    task_panel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    task_panel->setObjectName("wid4_" + tasks.task_name);

    QVBoxLayout* task_panel_layout = new QVBoxLayout;
    task_panel_layout->setContentsMargins(5,5,5,5);
    task_panel_layout->setSpacing(5);

    //add a steps holder
    QFrame* steps_holder = new QFrame;
    steps_holder->setStyleSheet("background-color:#dee2e6;padding:2px;border-radius:2px;color:black;");

    QVBoxLayout* steps_holder_layout = new QVBoxLayout;
    steps_holder_layout->setContentsMargins(6,6,6,6);
    steps_holder_layout->setSpacing(0);

    //create a mainstep
    steps_holder_layout->addWidget(create_step(tasks.task_name,1,tasks.is_done,tasks.is_important));

    QJsonArray arr = obj["steps"].toArray(); //extract the array in the obj
    //add the sub steps
    steps_adder(arr,steps_holder_layout);

    //add the addbtn
    steps_holder_layout->addWidget(create_addstepbtn(tasks.task_name));

    steps_holder->setLayout(steps_holder_layout);

    //steps
    task_panel_layout->addWidget(steps_holder);

    //add a add to today btn
    task_panel_layout->addWidget(create_addtoday(tasks.add_to_today,tasks.task_name));

    //add remduerep
    task_panel_layout->addWidget(create_remduerep(tasks.is_remind,tasks.due_date,tasks.is_repeat,tasks.task_name));

    //add files
    QJsonArray arr1 = obj["files"].toArray();
    task_panel_layout->addWidget(create_file(arr1,tasks.task_name));

    //add notes
    QTextEdit* note = new QTextEdit;
    note->setStyleSheet("background-color:#dee2e6;padding:2px;border-radius:2px;color:black;");
    note->setPlaceholderText("Add Note");
    task_panel_layout->addWidget(note);

    task_panel_layout->addWidget(create_botinfo(tasks.task_name));

    //set the layout
    task_panel->setLayout(task_panel_layout);

    return task_panel;
}



QWidget* PageCreator::createPage(
    QJsonObject obj,
    QVBoxLayout *list_cont_layout,
    bool isnew)
{

    List list;

    //get the name and icon in obj
    list.title = obj["title"].toString();
    list.icon.addFile(obj["icon"].toString(),QSize(30,30));

    QFrame* menu_btn_holder = new QFrame;
    menu_btn_holder->setCursor(Qt::PointingHandCursor);
    menu_btn_holder->setStyleSheet("border-radius:4;padding: 10px;");
    menu_btn_holder->setObjectName("men1_" + list.title);

    menu_btn_holder->installEventFilter(hoverEventFilter);

    QHBoxLayout* menu_btn_holder_layout = new QHBoxLayout;

    menu_btn_holder_layout->setContentsMargins(9,0,9,0);

    QPushButton* menu_btn_icon = create_button("ico_" + list.title,
                                               "",
                                               list.icon,
                                               QSize(20,20),
                                               QFont());
    menu_btn_icon->setStyleSheet("border-radius:15;padding: 1px;");

    QPushButton* menu_btn = create_button("btn_" + list.title,
                                          list.title,
                                          QIcon(),
                                          QSize(),
                                          defaultFile.btn_font);

    menu_btn->setStyleSheet("border-radius:15;\npadding:1px;\ntext-align:left;\n");

    menu_btn_holder_layout->addWidget(menu_btn_icon,0);
    menu_btn_holder_layout->addWidget(menu_btn,1);

    menu_btn_holder->setLayout(menu_btn_holder_layout);

    //insert the menu btn in the menu layout
    list_cont_layout->insertWidget(0,menu_btn_holder);

    //create a page, and set a name on it
    page = new QWidget;
    page->setObjectName("men1_" + list.title + "_page");


    create_page_comp(obj);

    //if new create a new file to save the task config
    if(isnew){
        //create a new file to store the data of new created list
        JsonReaderWriter writer;

        //create a file and a list because its new
        writer.createList(list.title);

    }
    return page;

}



