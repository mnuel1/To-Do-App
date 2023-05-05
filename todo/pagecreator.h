#ifndef PAGECREATOR_H
#define PAGECREATOR_H

#include "pagecreatorlib.h"

#include "hovereffect.h"
#include "jsonReaderWriter.h"
#include "liststructure.h"
#include "defaultfiles.h"

#include <QLayoutItem>
#include <QMetaObject>

class PageCreator : public QObject
{
    Q_OBJECT
public:
    PageCreator(QWidget *parent = nullptr);
    ~PageCreator();


    void create_page_comp(QJsonObject);

    void widget_adder(QJsonArray,
                      QVBoxLayout*);

    void steps_adder(QJsonArray,                     
                     QVBoxLayout*);
    void files_adder(QJsonArray,
                     QVBoxLayout*);

    void getJsonFile();

    void get_tasks(QVBoxLayout* layout);

    QPushButton* create_button(QString name,
                               QString text,
                               QIcon icon,
                               QSize size,
                               QFont font);
    QLabel* create_label(QString text,
                         QFont font);
    QFrame* create_addtaskbtn(QString name);
    QFrame* create_step(QString text,
                        bool is_mainstep,
                        bool is_done,
                        bool is_imp);
    QFrame* create_addstepbtn(QString name);

    QFrame* create_addtoday(bool is_add,QString name);

    QFrame* create_remduerep(bool is_rem, QString date, bool is_rep,QString name);
    QFrame* create_rem(bool is_rem,QString name);
    QFrame* create_due(QString date,QString name);
    QFrame* create_rep(bool is_rep,QString name);

    QFrame* create_file(QJsonArray arr,QString name);
    QFrame* create_botinfo(QString name);

    QFrame* create_task_panel(QJsonObject);
    QFrame* create_task_comp(QString name,
                             QString text,
                             QString f_btn_name,
                             QIcon f_icon,
                             QSize f_size_icon,
                             QString s_btn_name,
                             QIcon s_icon,
                             QSize s_size_icon,
                             QFont font);

    QFrame* create_header_form(QString name);
    QFrame* create_line_form();
    QFrame* create_content_form(QString name,
                                QJsonObject
                                );

    void parseTask(QJsonObject obj,List::task *tasks);
    QFrame* create_widget_btn(List::task tasks);

    QWidget* createPage(QJsonObject,
                        QVBoxLayout *,
                        bool);

private:

    QWidget* page;

    HoverEffect* hoverEventFilter;
    QObject* prev_obj = nullptr;
    DefaultFiles defaultFile;
    QVBoxLayout* third_panel_layout;

    std::unordered_set<QFrame*> task_panels;
    std::unordered_map<QString, QFrame*> tasks_list;

    ////need this if the button is clicked
    //    //add the task panel in the third panel
    //    third_panel_layout->addWidget(task_panel);








};

#endif // PAGECREATOR_H
