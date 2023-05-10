#include "jsonReaderWriter.h"

JsonReaderWriter::JsonReaderWriter()
{

}

//file creator
void JsonReaderWriter::fileCreator(QString name)
{

    QFile file(default_path + name + ".json");

    if(!(file.exists()) &&
       file.open(QIODevice::WriteOnly | QIODevice::Text)){

        file.close();
    }

}

//search and get the specific data in the json
QJsonObject JsonReaderWriter::getTaskInfo(const QString filename, const QString taskname)
{
    QJsonDocument doc = read(filename + ".json");

    QJsonObject obj = doc.object();

    QJsonArray tasks = obj["tasks"].toArray();

    for(auto task : tasks){
        QJsonObject taskObj = task.toObject();

        if(taskObj["task_name"].toString() == taskname){
            return taskObj;
        }
    }

    return QJsonObject();

}

//read the file
QJsonDocument JsonReaderWriter::read(const QString &filename)
{

    QFile file(default_path + filename);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        // handle error
        qDebug() << "Error";
        return QJsonDocument();
    }

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());

    return doc;

}

//write in the file
void JsonReaderWriter::write(const QString filename,QJsonObject obj)
{
    QFile file(default_path + filename + ".json");

    // Open file for writing
    if (file.open(QIODevice::WriteOnly)) {
        // Write JSON data to file
        QJsonDocument jsonDoc(obj);
        file.write(jsonDoc.toJson());
        file.close();
    }
}

void JsonReaderWriter::createList(const QString name)
{
    //create the file because it will be a new list
    fileCreator(name);

    QJsonObject list;
    list["title"]          = name;          //initialize the title
    list["icon"]           = "";            //icon will be default
    list["theme"]          = "";            //theme will be default

    QJsonArray tasks;                       //create the tasks array but empty

    list["tasks"]          = tasks;

    //'name' of the new list will be the name of the file
    write(name,list);
}
void JsonReaderWriter::editList(const QString filename, const QString key, const QString value)
{
    QJsonDocument doc = read(filename + ".json");

    QJsonObject obj = doc.object();

    obj[key] = value;
    write(filename,obj);

    //in changing the list name/title, rename the file too
    if(key == "title"){
        //rename the file
        QFile file(default_path + filename + ".json");

        QString newname = default_path + value + ".json";
        file.rename(newname);

        //!! add a error handler?

    }


}

void JsonReaderWriter::writeTask(const QString filename,const QString name)
{
    //get the list
    QJsonDocument doc = read(filename + ".json");

    QJsonObject obj = doc.object();

    //get the tasks
    QJsonArray tasks = obj["tasks"].toArray();

    // Create JSON data
    // leave everything to default except the task name
    QJsonObject task;
    task["task_id"]        = 1;
    task["task_name"]      = name;
    task["done"]           = false;

    QJsonArray steps;
    task["steps"]          = steps;

    task["important"]      = false;
    task["add_to_today"]   = false;
    task["remind"]         = false;
    task["due_date"]       = "";
    task["repeat"]         = false;

    QJsonArray files;
    task["files"]          = files;
    task["note"]           = "";

    tasks.append(task);         // append the new task

    obj.insert("tasks",tasks);  //update the file

    write(filename,obj);

}
void JsonReaderWriter::editTaskName(const QString filename,const QString taskname,const QString newname)
{
    QJsonDocument doc = read(filename + ".json");

    QJsonObject obj = doc.object();

    QJsonArray tasks = obj["tasks"].toArray();      // Access the tasks array

    for (int i = 0; i < tasks.size(); ++i) {
        QJsonObject taskObj = tasks[i].toObject();

        if(taskObj["task_name"].toString() == taskname){

            taskObj["task_name"] = newname;         //replace the name
            tasks.replace(i,taskObj);               //replace the object
            break;
        }
    }
    obj["tasks"] = tasks;                           //update the task

    write(filename,obj);                            //update the json file

}
void JsonReaderWriter::editImportantTaskName(const QString filename, const QString taskname, const bool isImportant)
{
    //get the json
    QJsonDocument doc = read(filename + ".json");

    QJsonObject obj = doc.object();

    //get the tasks
    QJsonArray tasks = obj["tasks"].toArray();

    for (int i = 0; i < tasks.size(); ++i) {
        QJsonObject taskitem = tasks[i].toObject();
        taskitem["important"] = isImportant;
        tasks.replace(i,taskitem);
        break;

    }

    obj["tasks"] = tasks;

    write(filename,obj);

}
void JsonReaderWriter::delTask(const QString filename,const QString name)
{
    QJsonDocument doc = read(filename + ".json");

    QJsonObject obj = doc.object();

    QJsonArray tasks = obj["tasks"].toArray();      // Access the tasks array

    for(int i = 0; i < tasks.size();i++){           // Find the task object you want to delete
        QJsonObject task = tasks.at(i).toObject();

        if(task["task_name"].toString() == name){   // checks if match
            tasks.removeAt(i);                      //remove the task
            obj["tasks"] = tasks;                   //update the task
            break;
        }
    }

    write(filename,obj);                            //update the json file
}

void JsonReaderWriter::writeStep(const QString filename,const QString taskname,const QString stepname)
{
    //get the json
    QJsonDocument doc = read(filename + ".json");

    QJsonObject obj = doc.object();

    //get the tasks
    QJsonArray tasks = obj["tasks"].toArray();

    for(auto task : tasks){
        QJsonObject taskitem = task.toObject();

        if(taskitem["task_name"].toString() == taskname){
            QJsonArray steps = taskitem["steps"].toArray(); //get the steps array

            QJsonObject newstep;                            //create the new step

            newstep.insert("step",stepname);
            newstep.insert("done",false);

            steps.append(newstep);                          //add the newstep in steps

            taskitem.insert("steps",steps);                 //update the tasks array
            //tasks.replace(i,taskitem);
            break;
        }
    }

    obj.insert("tasks",tasks);                              //update the file

    write(filename,obj);

}
void JsonReaderWriter::editStepName(const QString filename, const QString taskname, const QString stepname, const QString newname)
{
    //get the json
    QJsonDocument doc = read(filename + ".json");

    QJsonObject obj = doc.object();

    //get the tasks
    QJsonArray tasks = obj["tasks"].toArray();

    for (int i = 0; i < tasks.size(); ++i) {
        QJsonObject taskitem = tasks[i].toObject();

        if (taskitem["task_name"].toString() == taskname) {
            QJsonArray steps = taskitem["steps"].toArray();

            for (int j = 0; j < steps.size(); ++j) {
                QJsonObject stepObj = steps[j].toObject();

                if (stepObj["step"].toString() == stepname) {
                    stepObj["step"] = newname;      //update the name
                    steps.replace(j, stepObj);      //replace the specific index in the steps
                    taskitem["steps"] = steps;      //update the item task[steps]
                    tasks.replace(i, taskitem);     //replace the specific index in the tasks

                    // Task and step found and updated
                    goto done;
                }
            }
        }
    }
    done:
    obj["tasks"] = tasks;

    write(filename,obj);

}
void JsonReaderWriter::editDoneStep(const QString filename, const QString taskname, const QString stepname, const bool isdone)
{
    //get the json
    QJsonDocument doc = read(filename + ".json");

    QJsonObject obj = doc.object();

    //get the tasks
    QJsonArray tasks = obj["tasks"].toArray();

    for (int i = 0; i < tasks.size(); ++i) {
        QJsonObject taskitem = tasks[i].toObject();

        if (taskitem["task_name"].toString() == taskname) {
            QJsonArray steps = taskitem["steps"].toArray();

            for (int j = 0; j < steps.size(); ++j) {
                QJsonObject stepObj = steps[j].toObject();

                if (stepObj["step"].toString() == stepname) {
                    stepObj["done"] = isdone;
                    steps.replace(j, stepObj);
                    taskitem["steps"] = steps;
                    tasks.replace(i, taskitem);

                    // Task and step found and updated
                    goto done;
                }
            }
        }
    }
    done:
    obj["tasks"] = tasks;

    write(filename,obj);

}
void JsonReaderWriter::delStep(const QString filename, const QString taskname, const QString stepname)
{
    //get the json
    QJsonDocument doc = read(filename + ".json");

    QJsonObject obj = doc.object();

    //get the tasks
    QJsonArray tasks = obj["tasks"].toArray();

    int done = 0;

    for(auto task : tasks){
        QJsonObject taskitem = task.toObject();

        if(taskitem["task_name"].toString() == taskname){
            QJsonArray steps = taskitem["steps"].toArray(); //get the steps array
            // find the step that will gonna be editted
            for(int i = 0; i < steps.size(); i++){
                QJsonObject stepObj = steps.at(i).toObject();

                if(stepObj["step"].toString() == stepname){
                    steps.removeAt(i);
                    done = 1;
                    break;
                }
            }
        }
        if(done) break;
    }

    obj["tasks"] = tasks;

    write(filename,obj);

}

void JsonReaderWriter::saveInToday(const QJsonObject task)
{
    write("Today",task); // if the task is assigned in "Today" save it in today file

}

void JsonReaderWriter::saveInImportant(const QJsonObject task)
{
    write("Important",task); // if the task is important save it in today file
}

void JsonReaderWriter::saveInPlanned(const QJsonObject task)
{
    write("Planned",task); // if the task have date save it in today file
}
