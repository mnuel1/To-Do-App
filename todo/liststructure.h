#ifndef LISTSTRUCTURE_H
#define LISTSTRUCTURE_H


typedef struct List{

    QString title;
    QIcon icon;
    QString theme_name;

    typedef struct task{

        QString task_name;
        QString due_date;
        QString note;

        int task_id;
        int step_num;
        int finish_step;
        int file_num;

        bool is_done;
        bool is_important;
        bool add_to_today;
        bool is_remind;        
        bool is_repeat;

    }task;

}List;


#endif // LISTSTRUCTURE_H
