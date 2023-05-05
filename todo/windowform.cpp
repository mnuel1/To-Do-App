#include "windowform.h"
#include "./ui_windowform.h"

WindowForm::WindowForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowForm)
{
    ui->setupUi(this);


}

WindowForm::~WindowForm()
{
    delete ui;
}



//    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
//                                                         "/path/to/default/directory",
//                                                         tr("Files (*.txt *.doc)"));
//        if (!fileName.isEmpty()) {
//            qDebug() << fileName;
//        }




//    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
//                                                         "/path/to/default/directory",
//                                                         tr("Files (*.txt *.doc)"));
//        if (!fileName.isEmpty()) {
//            qDebug() << fileName;
//        }

