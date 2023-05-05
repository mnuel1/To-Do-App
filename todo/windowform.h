#ifndef WINDOWFORM_H
#define WINDOWFORM_H

#include <QMainWindow>
#include <QFileDialog>
#include <QListWidgetItem>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class WindowForm; }
QT_END_NAMESPACE


class WindowForm : public QMainWindow
{
    Q_OBJECT

public:
    WindowForm(QWidget *parent = nullptr);
    ~WindowForm();

private slots:



private:
    Ui::WindowForm *ui;
};

#endif // WINDOWFORM_H
