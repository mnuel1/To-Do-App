#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    this->hoverEventFilter = new HoverEffect(this);
    connect(this->hoverEventFilter, SIGNAL(HoverIn(QObject*)),  this, SLOT(hoverIn(QObject*)));
    connect(this->hoverEventFilter, SIGNAL(HoverOut(QObject*)), this, SLOT(hoverOut(QObject*)));
    connect(this->hoverEventFilter, SIGNAL(Clicked(QObject*)),  this, SLOT(clicked(QObject*)));

    listform = new ListForm(this);
    user_setts = new UserSettings(this,ui->splitter);
    startup();

    //this->setWindowFlags(Qt::WindowType::FramelessWindowHint);

    QDate date = QDate::currentDate();
    ui->day_date->setText(date.toString("ddd, MMM d, yyyy"));

    //just hides the menu icons needed for the mobile view
    showHideMenuIcon(ui->content_widgets->widget(ui->content_widgets->currentIndex()),3);

    //setup splitter not collabsible
    ui->splitter->setCollapsible(0,false);
    ui->splitter->setCollapsible(1,false);
    ui->splitter->setCollapsible(2,false);

    ui->content_widgets->setCurrentIndex(0);

}

MainWindow::~MainWindow()
{
    delete hoverEventFilter;
    delete user_setts;
    delete listform;
    delete ui;

}

void MainWindow::startup()
{
    user_setts->readall();
    readOnDir();
    eventFilterInstaller();
    setUpOpacityGraphic();

}

void MainWindow::stopMovie()
{
    if(movie != nullptr && movie->state() == QMovie::Running){
        movie->stop();
        delete movie;
        movie = nullptr;
    }
}

void MainWindow::showHideMenuIcon(QWidget *widget,int state)
{
    // get and hide the menu icon
    QObject* header = widget->children().at(1);
    QObject* comp   = header->children().at(1);
    menu            = comp->children().at(1);

    if(state == 1){
        qobject_cast<QWidget*>(menu)->hide();
        ui->men0_nav_btn->show();
    }else if (state == 2){
        qobject_cast<QWidget*>(menu)->show();
        ui->men0_nav_btn->hide();
    }else{
        qobject_cast<QWidget*>(menu)->hide();
        ui->men0_nav_btn->hide();
    }
}

void MainWindow::setUpOpacityGraphic()
{
    if(!effect){
        effect = new QGraphicsOpacityEffect;
    }

    effect->setOpacity(0.1);
    ui->splitter->widget(1)->setGraphicsEffect(effect);
    effect->setEnabled(false);
}

void MainWindow::enableOrDisableChildrenOfParent(QObject *parent,bool state)
{
    // iterate over all the children of the parent
    for (auto child : parent->children()){

        // disable the child if its not layout
        if(qobject_cast<QLayout*>(child) == nullptr)
           ((QWidget*)child)->setEnabled(state);


        // disable the children of their child
        if (child->children().size() > 0){
            enableOrDisableChildrenOfParent(child,state);
        }
    }
}

void MainWindow::showOrHideMenu()
{
    //get the current page
    int currentPageIndex = ui->content_widgets->currentIndex();
    QWidget* currentPage = ui->content_widgets->widget(currentPageIndex);

    //checks if width is minimum
    //change to mobile view
    //every frame will occupy the space
    /// 0 = mobile view, 1 = tablet view, 2 = pc or laptop view
    if(view == 0){
        if(ui->splitter->widget(0)->isHidden()){                            // check if menu frame is hidden
            ui->splitter->widget(0)->show();                                // show the menu if hidden
            ui->splitter->widget(1)->hide();                                // hide the content
            showHideMenuIcon(currentPage,1);
        }else{
            ui->splitter->widget(0)->hide();                                // hide if not
            ui->splitter->widget(1)->show();                                //show the content
            showHideMenuIcon(currentPage,2);

        }
    }else if(view == 1){
        if(ui->splitter->widget(0)->isHidden()){                            // check if menu frame is hidden
            ui->splitter->widget(0)->show();                                // show if hidden
            enableOrDisableChildrenOfParent(ui->splitter->widget(1),false); // disable the content
            if (effect) effect->setEnabled(true);                           // enable the opacity
            showHideMenuIcon(currentPage,1);
        }else{
            ui->splitter->widget(0)->hide();                                // hide if not
            enableOrDisableChildrenOfParent(ui->splitter->widget(1),true ); // enable the content
            if (effect) effect->setEnabled(false);                          // disable the opacity
            showHideMenuIcon(currentPage,2);


        }
    }else showHideMenuIcon(currentPage,3);
}

QString MainWindow::getFilename(QWidget *currentPage)
{
    //get the filename
    currentPage = ui->content_widgets->currentWidget();
    QString filename = currentPage->objectName();
    QStringList list = filename.split("_");
    filename = list.at(1);

    return filename;

}

void MainWindow::readOnDir()
{
    QDir dir(default_path);
    JsonReaderWriter reader;

    page_creator = new PageCreator(this);

    if(dir.exists()){

        QFileInfoList fileList = dir.entryInfoList(QStringList() << "*.json", QDir::NoDotAndDotDot | QDir::Files);

        for (int i = 0; i < fileList.size(); i++){

            QFileInfo fileInfo = fileList.at(i);
            QString fileName = fileInfo.fileName();
            QJsonDocument doc = reader.read(fileName);

            QJsonObject obj  = doc.object();

            QJsonArray arr = obj["tasks"].toArray();
            if(fileName == "Today.json"){
                page_creator->widget_adder(arr,ui->today_layout);
            }else if(fileName == "Important.json"){
                page_creator->widget_adder(arr,ui->important_layout);
            }else if(fileName == "Planned.json"){
                page_creator->widget_adder(arr,ui->planned_layout);
            }else{
                QWidget* page = page_creator->createPage(obj,
                                                         ui->list_cont_layout,  //add in the menu
                                                         0);
                ui->content_widgets->addWidget(page);   //add in the content
            }
        }
    }
}

void MainWindow::eventFilterInstaller()
{
    //menu icons
    ui->men0_nav_btn->installEventFilter(this->hoverEventFilter);
    ui->men0_btn->installEventFilter(this->hoverEventFilter);
    ui->men0_Important->installEventFilter(this->hoverEventFilter);
    ui->men0_Planned->installEventFilter(this->hoverEventFilter);

    //header btns
    ui->men1_Today->installEventFilter(this->hoverEventFilter);
    ui->men1_Important->installEventFilter(this->hoverEventFilter);
    ui->men1_Planned->installEventFilter(this->hoverEventFilter);
    ui->men2_newlist_btn->installEventFilter(this->hoverEventFilter);

    //settings btns
    ui->set3_Today->installEventFilter(this->hoverEventFilter);
    ui->set3_Important->installEventFilter(this->hoverEventFilter);
    ui->set3_Planned->installEventFilter(this->hoverEventFilter);

    //add btn
    ui->add10_Today->installEventFilter(this->hoverEventFilter);
    ui->add10_Important->installEventFilter(this->hoverEventFilter);
    ui->add10_Planned->installEventFilter(this->hoverEventFilter);

    //ticket btn
    ui->tic13_btn->installEventFilter(this->hoverEventFilter);

    ui->third_panel->installEventFilter(this->hoverEventFilter);
}

void MainWindow::btnEffectsIn(int val,QObject *object)
{

    switch(val)
    {
        case 0: {   //menu icon
                    ((QWidget*)object)->setStyleSheet("border-radius: 5; padding: 5px;background: white");
                    break;
                }
        case 1: {   //menu btn
                    ((QWidget*)object)->setStyleSheet(
                    "background-color: #33393E;"
                    "color: white;"
                    "border-radius:4;"
                    "padding: 10px;"
                    );break;
                }
        case 2: {   //editable newlist btn
                    ((QWidget*)object)->setStyleSheet(
                    "border-radius:4;padding: 10px;"
                    "background-color: #33393E;"
                    "color: white;"
                    ); break;
                }
        case 3: {   //setting btn
                    ((QWidget*)object)->setStyleSheet( "border-radius: 5px;  padding: 3px; background: white"); break;
                }
        case 4: {   //widget
                    ((QWidget*)object)->setStyleSheet("background:#e9ecef;color:black;border-radius:5;"); break;
                }
        case 5: {   //circle checkbox

                    auto it = done.find(object);

                    if(movie == nullptr && it == done.end()){
                        movie = new QMovie(":/i/resources/icons/circle_fill.gif", QByteArray(), this);
                        connect(movie, &QMovie::frameChanged, this, [=]() {
                            ((QPushButton*)object)->setIcon(movie->currentPixmap());
                        });
                        movie->start();
                    }
                    break;
                }
        case 6: {   //star
                    auto it = done.find(object);

                    if(movie == nullptr && it == done.end()){
                        movie = new QMovie(":/i/resources/icons/star_fill.gif", QByteArray(), this);
                        connect(movie, &QMovie::frameChanged, this, [=]() {
                            ((QPushButton*)object)->setIcon(movie->currentPixmap());
                        });
                        movie->start();
                    }
                    break;
                }
        case 7: {   //close
                    ((QWidget*)object)->setStyleSheet("border:0px; border-radius:4px; background:#e9ecef;");break;
                }
        case 9: {   //del
                    ((QWidget*)object)->setStyleSheet("border:0px; border-radius:4px; background:#e9ecef;");break;
                }
        case 10:{   //addtask
                    ((QWidget*)object)->setStyleSheet("text-align:left;padding:10px;border-radius:5px;background:#e9ecef;color:black;");
                    break;
                }       
        case 11:{   //icon edit
                    QPushButton* icon_edit = qobject_cast<QPushButton*>(object);

                    if(icon_edit) {
                        icon_edit->setStyleSheet("background:#e9ecef;border-radius:5; padding:10px;");
                    }
                    break;
                }
        case 15:    //textedit listname
        case 16:    //textedot taskname
        case 12:{   //textedit stepname
                    ((QWidget*)object)->setStyleSheet("background:#e9ecef;padding:6px;border-radius:2;");
                    break;
                }
        case 13:{   //ticket
                    ((QWidget*)object)->setStyleSheet( "background: qradialgradient(cx: 0.5, cy: 0.1, fx: 0.5, fy: 0.1, "
                                                    "radius: 1.5, stop: 0 #000000, stop: 1 #ffffff); border-bottom-left-radius:10px;"
                                                    "border-bottom-right-radius:10px; height: 15px;width: 100px;");
                    break;
                }
        case 14:{   //addstep
                    ((QWidget*)object)->setStyleSheet("border-radius:4px;background:#e9ecef;color:black;text-align:left;");
                    break;
                }
        default: break;
    }
}

void MainWindow::btnEffectsOut(int val,QObject *object)
{

    switch(val)
    {
        case 0: {   //menu icon
                    ((QWidget*)object)->setStyleSheet("border-radius: 5; padding: 5px;"); break;
                }
        case 1: {   // menu btns
                    ((QWidget*)object)->setStyleSheet(
                                           "background-color:#212529;"
                                           "color: #E7E9E2;"
                                           "border-radius:4;"
                                           "padding: 10px;"
                                           ); break;
                }
        case 2: {   // editable newlist btn
                    ((QWidget*)object)->setStyleSheet(
                                           "border-radius:4;padding: 10px;"
                                           "background-color: #212529;"
                                           "color: white;"
                                           );
                    break;
                }
        case 3: {    //setting btn
                    ((QWidget*)object)->setStyleSheet( "border-radius: 5px;  padding: 3px;"); break;
                }
        case 4: {   //widget
                    ((QWidget*)object)->setStyleSheet("background:white;color:black;border-radius:5;"); break;
                }
        case 5: {   //circle checkbox
                    stopMovie();

                    ((QPushButton*)object)->setIcon(QIcon(":/i/resources/icons/circle.png"));
                    break;
                }
        case 6: {   //star
                    stopMovie();

                    ((QPushButton*)object)->setIcon(QIcon(":/i/resources/icons/star.png"));
                    break;
                }
        case 7: {   //close btn
                    ((QWidget*)object)->setStyleSheet("border:0px;");break;
                }
        case 9: {   //del btn
                    ((QWidget*)object)->setStyleSheet("border:0px;");break;
                }
        case 10:{   //add btn
                    ((QWidget*)object)->setStyleSheet("text-align:left;padding:10px;border-radius:5px;background:white;color:black;");
                    break;
                }
        case 11:{   //icon edit
                    QPushButton* icon_edit = qobject_cast<QPushButton*>(object);

                    if(icon_edit) {
                        icon_edit->setStyleSheet("border-radius:5; padding:10px;");
                    }
                    break;
                }
        case 15:    //textedit listname
        case 16:    //textedot taskname
        case 12:{   //textedit stepname
                    ((QWidget*)object)->setStyleSheet("padding:6px;border-radius:2;");
                    break;
                }
        case 13:{   //ticket
                    ((QWidget*)object)->setStyleSheet( "background: qradialgradient(cx: 0.5, cy: 0.1, fx: 0.5, fy: 0.1, "
                                                       "radius: 1.5,  stop: 0 #ffffff, stop: 1 #000000); border-bottom-left-radius:10px;"
                                                       "border-bottom-right-radius:10px; height: 15px;width: 100px;");
                    break;
                }
        case 14:{   //addstep
                    ((QWidget*)object)->setStyleSheet("border-radius:4px;background:white;color:black;text-align:left;");
                    break;
                }
        default: break;


    }
}

void MainWindow::btnClicked(int val, QObject* object)
{
    JsonReaderWriter json;
    btnEffectsIn(val,object);
    switch(val)
    {
        case 0: {   //menu icon
                    btnEffectsOut(val,object); //after clicking the menuicon, remove its effect
                    showOrHideMenu();
                    break;
                }
        case 1: {   //menu btn

                    if(prev_obj != nullptr) btnEffectsOut(1,prev_obj);
                    QWidget *widget = ui->content_widgets->findChild<QWidget*>(object->objectName() + "_page");

                    int index = ui->content_widgets->indexOf(widget);

                    ui->content_widgets->setCurrentIndex(index);
                    showOrHideMenu();
                    break;
                }
        case 2: {   //list btn

                    // if there is pending text edit
                    if (new_edit != nullptr) {
                        keyPressEvent(new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Enter, Qt::NoModifier));

                    }else {

                        // add new list
                        new_edit = object->findChild<QLineEdit*>();

                        if(new_edit){
                            new_edit->setReadOnly(false);
                            new_edit->setFocus();
                            editType = 0;
                        }
                    }

                    break;
                }
        case 3: {   //settings btn !!todo
                    btnEffectsOut(val,object);      //after clicking the settings btn just remove the effect
                    break;
                }
        case 4: {   //widget btn

                    bool isHidden = ui->splitter->widget(2)->isHidden();
                    bool isEmpty =  ui->third_panel_layout->count() == 0 ? true : false;

                    //get the taskname
                    QObject* li = object->findChild<QFrame*>();
                    QObject* taskn = li->findChild<QLabel*>();

                    QString taskname = ((QLabel*)taskn)->text();

                    QString filename = getFilename(ui->content_widgets->currentWidget());

                    QJsonObject obj = json.getTaskInfo(filename, taskname);

                    QFrame* tPanel = page_creator->create_task_panel(obj);
                    ui->splitter->widget(2)->show();

                    if(isHidden) ui->splitter->widget(2)->show();

                    if(object == prev_obj && !isHidden) ui->splitter->widget(2)->hide();

                    if(isEmpty){
                        ui->third_panel_layout->addWidget(tPanel);
                    }else{
                        QWidget* widget = ui->third_panel_layout->takeAt(0)->widget();
                        delete widget;
                        ui->third_panel_layout->addWidget(tPanel);

                    }

                    currentTask = taskname;

                    int width_m = qRound(ui->splitter->widget(0)->size().toSizeF().width());
                    int width_c = qRound(ui->splitter->widget(1)->size().toSizeF().width());

                    ui->splitter->setSizes({width_m,width_c,270});

                    break;
                }
        case 5: {   //circle
                    stopMovie();

                    auto it = done.find(object);

                    QString filename = getFilename(ui->content_widgets->currentWidget());

                    QStringList sList = object->objectName().split("_");
                    QString stepname = sList.last();

                    if(currentTask != ""){

                        if(it == done.end()){
                            done.emplace(object);

                            ((QPushButton*)object)->setIcon(QIcon(":/i/resources/icons/circle-checked.png"));
                            json.editDoneStep(filename,currentTask,stepname,true);
                        }else{

                            json.editDoneStep(filename,currentTask,stepname,false);
                            btnEffectsOut(5,object);
                            done.erase(it);
                        }
                    }

                    break;

                }
        case 6: {   //star
                    stopMovie();

                    auto it = done.find(object);

                    QString filename = getFilename(ui->content_widgets->currentWidget());

                    if(currentTask != ""){
                        if(it == done.end()){
                            done.emplace(object);
                            ((QPushButton*)object)->setIcon(QIcon(":/i/resources/icons/star_fill.png"));
                            json.editImportantTaskName(filename,currentTask,true);

                        }else{
                            json.editImportantTaskName(filename,currentTask,false);
                            btnEffectsOut(6,object);
                            done.erase(it);
                        }
                    }

                    break;
                }
        case 7: {   //close btn
                    ui->splitter->widget(2)->hide();
                    break;
                }
        case 9: {   //del btn !!todo
                    break;
                }
        case 10:{   //task btn

                    // if there is pending text edit
                    if (new_edit != nullptr) {
                        keyPressEvent(new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Enter, Qt::NoModifier));
                    }else {

                        //add new task
                        new_edit = object->findChild<QLineEdit*>();

                        if(new_edit){
                            new_edit->setReadOnly(false);
                            new_edit->setFocus();
                            editType = 1;
                        }
                    }


                    break;
                }
        case 11:{   //icon list edit !!todo !!add pop up option

                    btnEffectsOut(11,object);
                    QPushButton* icon = qobject_cast<QPushButton*>(object);

                    if(icon) {

                        QString filename = getFilename(ui->content_widgets->currentWidget());

                        json.editList(filename,"icon",":/i/resources/icons/alarm-minus.png");
                    }

                    break;
                }
        case 12:{   //textedit step

                    // if there is pending text edit
                    if (new_edit != nullptr) {
                        keyPressEvent(new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Enter, Qt::NoModifier));
                    }else {

                        // edit step name
                        new_edit = object->findChild<QLineEdit*>();

                        if(new_edit){
                            currentStepname = new_edit->text();
                            new_edit->setReadOnly(false);
                            new_edit->setFocus();
                            new_edit->selectAll();
                            editType = 3;
                        }
                    }
                    break;
                }
        case 13:{   //ticket !!todo
                    break;
                }
        case 14:{   //step btn

                    // if there is pending text edit
                    if (new_edit != nullptr) {
                        keyPressEvent(new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Enter, Qt::NoModifier));
                    }else {
                        //add new step
                        new_edit = object->findChild<QLineEdit*>();

                        if(new_edit){
                            new_edit->setReadOnly(false);
                            new_edit->setFocus();
                            editType = 2;
                        }

                    }
                    break;
                }
        case 15:{   //text edit list name

                    // if there is pending text edit
                    if (new_edit != nullptr) {
                        keyPressEvent(new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Enter, Qt::NoModifier));
                    }else {

                        // edit list name
                        new_edit = qobject_cast<QLineEdit*>(object);

                        if(new_edit){
                            currentListname = new_edit->text();
                            new_edit->setReadOnly(false);
                            new_edit->setFocus();
                            new_edit->selectAll();
                            editType = 4;
                        }
                    }
                    break;
                }
        case 16:{   //text edit task name

                    // if there is pending text edit
                    if (new_edit != nullptr) {
                        keyPressEvent(new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Enter, Qt::NoModifier));
                    }else {

                        // edit list name
                        new_edit = object->findChild<QLineEdit*>();

                        if(new_edit){
                            currentTaskname = new_edit->text();
                            new_edit->setReadOnly(false);
                            new_edit->setFocus();
                            new_edit->selectAll();
                            editType = 5;
                        }
                    }
                    break;
                }
        default: break;
    }
}

void MainWindow::hoverIn(QObject *object)
{

    if(object != prev_obj && ((QWidget*)object)->isEnabled()){

        if(object->objectName() == "third_panel"){
            InThirdPanel = true;
        }else{
            //extract the int in the string
            //the int in string identify the object type
            std::string str = object->objectName().toStdString();
            std::regex rx("\\d+");
            std::smatch match;
            int val;

            if (std::regex_search(str, match, rx)) {
                val = std::stoi(match[0]);

            }

            btnEffectsIn(val,object);
        }
    }

}

void MainWindow::hoverOut(QObject *object)
{

    if(object != prev_obj && ((QWidget*)object)->isEnabled()){

        if(object->objectName() == "third_panel") {
            InThirdPanel = false;

        }else{

            //extract the int in the string
            //the int in string identify the object type
            std::string str = object->objectName().toStdString();
            std::regex rx("\\d+");
            std::smatch match;
            int val;

            if (std::regex_search(str, match, rx)) {
                val = std::stoi(match[0]);

            }
            btnEffectsOut(val,object);
        }

    }



}

void MainWindow::clicked(QObject *object)
{

    if(((QWidget*)object)->isEnabled() && object->objectName() != "third_panel"){

        //extract the int in the string
        //the int in string identify the object type
        std::string str = object->objectName().toStdString();
        std::regex rx("\\d+");
        std::smatch match;
        int val;

        if (std::regex_search(str, match, rx)) {
            val = std::stoi(match[0]);
            qDebug() << val;

        }

        btnClicked(val,object);

        prev_obj = object;
    }
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    // This function is called whenever the main window is resized


    if(event->size().width() <= 360){

        //switch to mobile view
        ui->splitter->widget(0)->hide();
        ui->splitter->widget(1)->show();
        view = 0; //mobile view

    }else if(event->size().width() <= 775 && event->size().width() <= 775){

        ui->splitter->widget(0)->hide();
        ui->splitter->widget(1)->show();
        ui->splitter->widget(2)->hide();

        qobject_cast<QWidget*>(menu)->show();
        ui->men0_nav_btn->show();
        view = 1; //tablet view?

    }else{

        ui->splitter->widget(0)->show();
        ui->splitter->widget(2)->show();

        qobject_cast<QWidget*>(menu)->hide();
        ui->men0_nav_btn->hide();
        view = 2; //pc or laptop view

    }

    bool is_empty = (ui->third_panel_layout == nullptr) || (ui->third_panel_layout->count() == 0);

    if(is_empty){
        ui->splitter->widget(2)->hide();
    }else{
        ui->splitter->widget(2)->show();
    }


}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    JsonReaderWriter json;
    int success = 0, widget_t = -1;

    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter){

        // this is for the Line Edit
        switch(editType)
        {

            case 0: {   // new list
                        // creating the new list file name by the new_edit text

                        QString filename = new_edit->text();

                        if (filename != "") {
                            json.createList(filename);
                            //!! add a success message if it succesfully created
                            widget_t = 2;
                            success = 1;

                        }
                        break;
                    }
            case 1: {   // new task
                        // creating the new task name by the new_edit text

                        QString filename = getFilename(ui->content_widgets->currentWidget());
                        QString taskname = new_edit->text();

                        if (taskname != "") {
                            json.writeTask(filename,taskname);
                            //!! add a success message
                            widget_t = 10;
                            success = 1;
                        }
                        break;

                    }
            case 2: {   // new step

                        //get the names
                        QString filename = getFilename(ui->content_widgets->currentWidget());
                        QString taskname = currentTask;
                        QString stepname = new_edit->text();

                        //if not empty
                        if (stepname != "") {

                            json.writeStep(filename,taskname,stepname);
                            //!! add a success message
                            widget_t = 14;
                            success = 1;
                        }
                        break;

                    }
            case 3: {   // edit step name !!todo

                        //get the names
                        QString filename = getFilename(ui->content_widgets->currentWidget());
                        QString taskname = currentTask;
                        QString stepname = currentStepname;
                        QString newname = new_edit->text();

                        if(stepname != newname && newname != "") {

                            json.editStepName(filename,taskname,stepname,newname);
                            //!! add a success message
                            widget_t = 12;
                            //success = 1;
                        }
                        break;

                    }
            case 4: {   // edit list name !!todo

                        //get the names
                        QString filename = currentListname;
                        QString key = "title";
                        QString value = new_edit->text();

                        if (value != "") {

                            json.editList(filename,key,value);
                            //!! add a success message
                            widget_t = 15;
                            //success = 1;
                        }
                        break;
                    }
            case 5: {   // edit task name !!todo

                        //get the names
                        QString filename = getFilename(ui->content_widgets->currentWidget());
                        QString taskname = currentTaskname;
                        QString newname = new_edit->text();

                        if (newname != currentTaskname && newname != "") {

                            json.editTaskName(filename,taskname,newname);
                            qDebug() << "yo";
                            //!! add a success message
                            widget_t = 16;
                            //success = 1;
                        }
                        break;
                    }
            default: break;
        }

        //reset !!todo fix the {edits}
        if (success) {
            btnEffectsOut(widget_t,new_edit->parent());
            new_edit->setReadOnly(true);
            new_edit->clearFocus();
            new_edit->clear();
            new_edit = nullptr;
            prev_obj = nullptr;
            editType = -1;
        }
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

    if (event->button() == Qt::LeftButton) {

        if (!(ui->splitter->widget(2)->isHidden()) && !InThirdPanel) ui->splitter->widget(2)->hide();

        if (editType != -1) keyPressEvent(new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Enter, Qt::NoModifier));

    }

}

void MainWindow::on_mini_btn_clicked()
{
    this->showMinimized();
}

void MainWindow::on_maxi_btn_clicked()
{
    if(this->windowState() == Qt::WindowMaximized){ // if maximized

        user_setts->readWindowSettings();

    }else{

        user_setts->saveWindowSettings();

        this->showMaximized();
    }
}

void MainWindow::on_exit_btn_clicked()
{
    user_setts->saveall();
    this->close();
}

