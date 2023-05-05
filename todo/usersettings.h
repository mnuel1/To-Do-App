#ifndef USERSETTINGS_H
#define USERSETTINGS_H

#include <QSettings>
#include <QSplitter>
#include <QMainWindow>
#include <QDebug>


class UserSettings
{
public:
    UserSettings(QMainWindow* mainwindow,QSplitter* splitter)
    {
        mysplitter = splitter;
        mywindow = mainwindow;
    }

    //for splitter settings/configs
    void saveSplitterSettings() { settings.setValue("splitterSizes",mysplitter->saveState()); }
    void readSplitterSettings() { mysplitter->restoreState(settings.value("splitterSizes").toByteArray()); }

    //for Window Settings/Configs
    void saveWindowSettings()
    {
        settings.setValue("geometry", mywindow->saveGeometry());
        settings.setValue("windowState", mywindow->saveState());
    }
    void readWindowSettings()
    {
        mywindow->restoreGeometry(settings.value("geometry").toByteArray());
        mywindow->restoreState(settings.value("windowState").toByteArray());
    }

    //save all settings
    void saveall()
    {
        // saveSplitterSettings();
         saveWindowSettings();
    }

    //read all settings
    void readall()
    {
        // readSplitterSettings();
         readWindowSettings();
    }

private:

    QSettings settings = QSettings("MyCompany","MyApp");
    QSplitter* mysplitter;
    QMainWindow* mywindow;
};

#endif // USERSETTINGS_H
