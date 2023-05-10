#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mainwindowheaders.h"
#include "hovereffect.h"
#include "newlist.h"
#include "JsonReaderWriter.h"
#include "pagecreator.h"
#include "windowctrl.h"
#include "usersettings.h"




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void startup();
    void eventFilterInstaller();

    //void createFiles(); installer
    void readOnDir();

    void initMap();

    void showHideMenuIcon(QWidget *widget,int state);
    void showOrHideMenu();

    void setUpOpacityGraphic();
    void stopMovie();

    void enableOrDisableChildrenOfParent(QObject* parent,bool state);

    virtual void keyPressEvent(QKeyEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void mousePressEvent(QMouseEvent *event);

    QString getFilename(QWidget* currentPage);

//    virtual void update() override;
private slots:

    void on_mini_btn_clicked();
    void on_maxi_btn_clicked();
    void on_exit_btn_clicked();

public slots:

    void hoverIn(QObject* object);
    void btnEffectsIn(int,QObject*);
    void hoverOut(QObject* object);
    void btnEffectsOut(int,QObject*);
    void clicked(QObject* object);
    void btnClicked(int,QObject*);

private:

    Ui::MainWindow *ui;
    ListForm* listform;
    PageCreator* page_creator;
    UserSettings* user_setts;

    HoverEffect* hoverEventFilter;
    QObject* prev_obj = nullptr;

    QGraphicsOpacityEffect* effect = nullptr;
    std::unordered_set<QObject*> done;
    QSettings settings = QSettings("MyCompany","MyApp");

    //edditable line edit
    QLineEdit* new_edit = nullptr;

    //menu icon
    QObject* menu;

    QString currentTask;

    QString currentListname;
    QString currentTaskname;
    QString currentStepname;


    //flags
    bool InThirdPanel = 0;

    int editType = -1;
    int view = -1;

    //animation
    QMovie* movie = nullptr;


    QString default_path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)
            + "/User Files";









};
#endif // MAINWINDOW_H
