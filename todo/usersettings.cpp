#include "usersettings.h"

UserSettings::UserSettings(QMainWindow* mainwindow, QSplitter* splitter)
{
    mysplitter = splitter;
    mywindow = mainwindow;
}


void UserSettings::readSplitterSettings()
{

    mysplitter->restoreState(settings.value("splitterSizes").toByteArray());

}

void UserSettings::saveSplitterSettings()
{

    settings.setValue("splitterSizes",mysplitter->saveState());

}

void UserSettings::readWindowSettings()
{
    mywindow->restoreGeometry(settings.value("geometry").toByteArray());
    mywindow->restoreState(settings.value("windowState").toByteArray());
}

void UserSettings::saveWindowSettings()
{

    qDebug() << mywindow->geometry();

    settings.setValue("geometry", mywindow->saveGeometry());

    settings.setValue("windowState", mywindow->saveState());

}

void UserSettings::saveall()
{
   // saveSplitterSettings();
    saveWindowSettings();
}

void UserSettings::readall()
{
   // readSplitterSettings();
    readWindowSettings();
}
