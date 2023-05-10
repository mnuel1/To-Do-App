#ifndef JSONREADERWRITER_H
#define JSONREADERWRITER_H

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStandardPaths>
#include <QJsonArray>
#include <QFileInfo>

class JsonReaderWriter
{
public:
    JsonReaderWriter();

    void fileCreator(QString name);

    QJsonObject getTaskInfo(const QString filename, const QString taskname);

    QJsonDocument read(const QString &filename);
    void write(const QString filename,const QJsonObject obj);

    void createList(const QString name);
    void editList(const QString filename, const QString key, const QString value);

    void writeTask(const QString filename,const QString name);
    void editTaskName(const QString filename,const QString taskname,const QString newname);
    void editImportantTaskName(const QString filename,const QString taskname,const bool isImportant);
    void delTask(const QString filename,const QString name);

    void writeStep(const QString filename,const QString taskname,const QString stepname);
    void editStepName(const QString filename,const QString taskname, const QString stepname, const QString newname);
    void editDoneStep(const QString filename,const QString taskname,const QString stepname, const bool isdone);
    void delStep(const QString filename,const QString taskname,const QString stepname);

    void editAddToToday();
    void editReminder();
    void editDueDate();
    void editRepeat();

    void writeFile();
    void editFile();
    void delFile();

    void saveInToday(const QJsonObject task);
    void saveInPlanned(const QJsonObject task);
    void saveInImportant(const QJsonObject task);



private:

    QString default_path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)
            + "/User Files/";

};

#endif // JSONREADER_H
