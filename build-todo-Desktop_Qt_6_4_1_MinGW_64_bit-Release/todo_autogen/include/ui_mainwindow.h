/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFrame *titlebar;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame_8;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *mini_btn;
    QPushButton *maxi_btn;
    QPushButton *exit_btn;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_18;
    QPushButton *pushButton_12;
    QPushButton *pushButton_17;
    QFrame *body;
    QHBoxLayout *horizontalLayout_3;
    QSplitter *splitter;
    QFrame *menu;
    QVBoxLayout *menu_layout;
    QScrollArea *scrollArea_4;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout_7;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_12;
    QFrame *frame_17;
    QVBoxLayout *verticalLayout_19;
    QPushButton *men0_nav_btn;
    QFrame *men1_Today;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_13;
    QPushButton *today;
    QFrame *men1_Important;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton_14;
    QPushButton *important;
    QFrame *men1_Planned;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *pushButton_15;
    QPushButton *planned;
    QFrame *line;
    QFrame *list_cont;
    QVBoxLayout *list_cont_layout;
    QSpacerItem *verticalSpacer_7;
    QFrame *men2_newlist_btn;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *pushButton_16;
    QPushButton *new_btn;
    QFrame *content;
    QVBoxLayout *verticalLayout_18;
    QStackedWidget *content_widgets;
    QWidget *men1_Today_page;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_6;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_17;
    QPushButton *men0_btn;
    QLabel *label;
    QLabel *day_date;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *set3_Today;
    QFrame *line_2;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_8;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_9;
    QFrame *frame_7;
    QVBoxLayout *today_layout;
    QSpacerItem *verticalSpacer_2;
    QFrame *add10_Today;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *pushButton_5;
    QLabel *label_2;
    QWidget *men1_Planned_page;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_13;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_4;
    QPushButton *men0_Planned;
    QFrame *frame_14;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton_3;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *set3_Planned;
    QFrame *line_4;
    QFrame *frame_18;
    QVBoxLayout *verticalLayout_20;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_6;
    QFrame *frame_15;
    QVBoxLayout *planned_layout;
    QSpacerItem *verticalSpacer;
    QFrame *add10_Planned;
    QHBoxLayout *horizontalLayout_17;
    QPushButton *pushButton_7;
    QLabel *label_6;
    QWidget *men1_Important_page;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_10;
    QHBoxLayout *horizontalLayout_5;
    QFrame *frame_6;
    QVBoxLayout *verticalLayout_16;
    QPushButton *men0_Important;
    QFrame *frame_11;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *set3_Important;
    QFrame *line_3;
    QFrame *frame_9;
    QVBoxLayout *verticalLayout_10;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_4;
    QVBoxLayout *verticalLayout_11;
    QFrame *frame_12;
    QVBoxLayout *important_layout;
    QSpacerItem *verticalSpacer_3;
    QFrame *add10_Important;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *pushButton_6;
    QLabel *label_5;
    QWidget *men1_Settings_page;
    QFrame *third_panel;
    QVBoxLayout *third_panel_info;
    QPushButton *tic13_btn;
    QScrollArea *third_panel_scrollarea;
    QWidget *third_panel_srcollcontent;
    QVBoxLayout *third_panel_layout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(983, 662);
        MainWindow->setMinimumSize(QSize(360, 500));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(33, 37, 41, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        MainWindow->setPalette(palette);
        QFont font;
        font.setFamilies({QString::fromUtf8("Roboto")});
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("color:white;\n"
" background-color:#212529;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMinimumSize(QSize(360, 500));
        centralwidget->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color:#212529"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titlebar = new QFrame(centralwidget);
        titlebar->setObjectName("titlebar");
        titlebar->setStyleSheet(QString::fromUtf8("background-color:#212529"));
        titlebar->setFrameShape(QFrame::StyledPanel);
        titlebar->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(titlebar);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 15, 0);
        frame_8 = new QFrame(titlebar);
        frame_8->setObjectName("frame_8");
        frame_8->setMinimumSize(QSize(100, 0));
        frame_8->setStyleSheet(QString::fromUtf8("background-color:#212529"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_8);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, -1, 0, -1);
        mini_btn = new QPushButton(frame_8);
        mini_btn->setObjectName("mini_btn");
        mini_btn->setMinimumSize(QSize(20, 20));
        mini_btn->setMaximumSize(QSize(20, 20));
        mini_btn->setCursor(QCursor(Qt::PointingHandCursor));
        mini_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	min-width:20;\n"
"	min-height:20;\n"
"    max-width:20;\n"
"	max-height:20;\n"
"    background-color: #00FF00;\n"
"    border-radius: 10;\n"
" \n"
"   \n"
"    }\n"
"\n"
"QPushButton:hover {\n"
"    background: #023020\n"
"        \n"
"    }\n"
"\n"
"QPushButton:pressed {\n"
"    \n"
"    background: #023020\n"
"        \n"
"    }"));

        horizontalLayout_2->addWidget(mini_btn);

        maxi_btn = new QPushButton(frame_8);
        maxi_btn->setObjectName("maxi_btn");
        maxi_btn->setMinimumSize(QSize(20, 20));
        maxi_btn->setMaximumSize(QSize(20, 20));
        maxi_btn->setCursor(QCursor(Qt::PointingHandCursor));
        maxi_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	min-width:20;\n"
"	min-height:20;\n"
"    max-width:20;\n"
"	max-height:20;\n"
"    background-color: #FFFF00;\n"
"    border-radius: 10;\n"
" \n"
"  \n"
"    \n"
"    }\n"
"\n"
"QPushButton:hover {\n"
"    background:  #8B8000\n"
"        \n"
"    }\n"
"\n"
"QPushButton:pressed {\n"
"    \n"
"    background:  #8B8000\n"
"        \n"
"    }"));

        horizontalLayout_2->addWidget(maxi_btn);

        exit_btn = new QPushButton(frame_8);
        exit_btn->setObjectName("exit_btn");
        exit_btn->setMinimumSize(QSize(20, 20));
        exit_btn->setMaximumSize(QSize(20, 20));
        exit_btn->setCursor(QCursor(Qt::PointingHandCursor));
        exit_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	min-width:20;\n"
"	min-height:20;\n"
"    max-width:20;\n"
"	max-height:20;\n"
"    background-color: #FF0000;\n"
"  \n"
"    border-radius: 10;\n"
" \n"
"    \n"
"    \n"
"    }\n"
"\n"
"QPushButton:hover {\n"
"    background:  #8B0000\n"
"        \n"
"    }\n"
"\n"
"QPushButton:pressed {\n"
"    \n"
"    background:  #8B0000\n"
"        \n"
"    }"));

        horizontalLayout_2->addWidget(exit_btn);


        horizontalLayout_4->addWidget(frame_8);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButton_18 = new QPushButton(titlebar);
        pushButton_18->setObjectName("pushButton_18");

        horizontalLayout_4->addWidget(pushButton_18);

        pushButton_12 = new QPushButton(titlebar);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setStyleSheet(QString::fromUtf8("border:0px"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/i/resources/icons/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_12->setIcon(icon);
        pushButton_12->setIconSize(QSize(20, 20));

        horizontalLayout_4->addWidget(pushButton_12);

        pushButton_17 = new QPushButton(titlebar);
        pushButton_17->setObjectName("pushButton_17");
        pushButton_17->setStyleSheet(QString::fromUtf8("border:0px"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/i/resources/icons/trash.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_17->setIcon(icon1);
        pushButton_17->setIconSize(QSize(20, 20));

        horizontalLayout_4->addWidget(pushButton_17);


        verticalLayout->addWidget(titlebar);

        body = new QFrame(centralwidget);
        body->setObjectName("body");
        body->setStyleSheet(QString::fromUtf8("background-color:#212529"));
        body->setFrameShape(QFrame::StyledPanel);
        body->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(body);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(body);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        menu = new QFrame(splitter);
        menu->setObjectName("menu");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(menu->sizePolicy().hasHeightForWidth());
        menu->setSizePolicy(sizePolicy);
        menu->setMinimumSize(QSize(225, 0));
        menu->setMaximumSize(QSize(390, 16777215));
        menu->setStyleSheet(QString::fromUtf8("background-color:#212529"));
        menu->setFrameShape(QFrame::StyledPanel);
        menu->setFrameShadow(QFrame::Raised);
        menu_layout = new QVBoxLayout(menu);
        menu_layout->setSpacing(0);
        menu_layout->setObjectName("menu_layout");
        menu_layout->setContentsMargins(0, 0, 0, 0);
        scrollArea_4 = new QScrollArea(menu);
        scrollArea_4->setObjectName("scrollArea_4");
        scrollArea_4->setStyleSheet(QString::fromUtf8("QScrollArea{border:0px;}"));
        scrollArea_4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_4->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName("scrollAreaWidgetContents_3");
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 223, 565));
        verticalLayout_7 = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(5, 0, 5, -1);
        frame_5 = new QFrame(scrollAreaWidgetContents_3);
        frame_5->setObjectName("frame_5");
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_12 = new QVBoxLayout(frame_5);
        verticalLayout_12->setObjectName("verticalLayout_12");
        verticalLayout_12->setContentsMargins(-1, -1, -1, 0);
        frame_17 = new QFrame(frame_5);
        frame_17->setObjectName("frame_17");
        frame_17->setFrameShape(QFrame::StyledPanel);
        frame_17->setFrameShadow(QFrame::Raised);
        verticalLayout_19 = new QVBoxLayout(frame_17);
        verticalLayout_19->setObjectName("verticalLayout_19");
        verticalLayout_19->setContentsMargins(-1, 0, -1, 0);
        men0_nav_btn = new QPushButton(frame_17);
        men0_nav_btn->setObjectName("men0_nav_btn");
        men0_nav_btn->setCursor(QCursor(Qt::PointingHandCursor));
        men0_nav_btn->setStyleSheet(QString::fromUtf8("border-radius: 5; padding: 5px;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/i/resources/icons/menu.png"), QSize(), QIcon::Normal, QIcon::Off);
        men0_nav_btn->setIcon(icon2);
        men0_nav_btn->setIconSize(QSize(20, 20));

        verticalLayout_19->addWidget(men0_nav_btn, 0, Qt::AlignLeft);


        verticalLayout_12->addWidget(frame_17);


        verticalLayout_7->addWidget(frame_5);

        men1_Today = new QFrame(scrollAreaWidgetContents_3);
        men1_Today->setObjectName("men1_Today");
        men1_Today->setCursor(QCursor(Qt::PointingHandCursor));
        men1_Today->setStyleSheet(QString::fromUtf8("border-radius:4;padding: 10px;"));
        men1_Today->setFrameShape(QFrame::StyledPanel);
        men1_Today->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(men1_Today);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(-1, 0, -1, 0);
        pushButton_13 = new QPushButton(men1_Today);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setStyleSheet(QString::fromUtf8("border-radius:15;padding: 1px;"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/i/resources/icons/sun.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_13->setIcon(icon3);
        pushButton_13->setIconSize(QSize(20, 20));

        horizontalLayout_7->addWidget(pushButton_13);

        today = new QPushButton(men1_Today);
        today->setObjectName("today");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Roboto")});
        font1.setPointSize(18);
        font1.setBold(false);
        today->setFont(font1);
        today->setCursor(QCursor(Qt::PointingHandCursor));
        today->setStyleSheet(QString::fromUtf8("border-radius:15;\n"
"padding:1px;\n"
"text-align:left;\n"
""));
        today->setIconSize(QSize(25, 25));

        horizontalLayout_7->addWidget(today);

        horizontalLayout_7->setStretch(1, 1);

        verticalLayout_7->addWidget(men1_Today);

        men1_Important = new QFrame(scrollAreaWidgetContents_3);
        men1_Important->setObjectName("men1_Important");
        men1_Important->setCursor(QCursor(Qt::PointingHandCursor));
        men1_Important->setStyleSheet(QString::fromUtf8("border-radius:4;padding: 10px;"));
        men1_Important->setFrameShape(QFrame::StyledPanel);
        men1_Important->setFrameShadow(QFrame::Raised);
        horizontalLayout_9 = new QHBoxLayout(men1_Important);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_9->setContentsMargins(-1, 0, -1, 0);
        pushButton_14 = new QPushButton(men1_Important);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setStyleSheet(QString::fromUtf8("border-radius:15;padding: 1px;"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/i/resources/icons/note_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_14->setIcon(icon4);
        pushButton_14->setIconSize(QSize(20, 20));

        horizontalLayout_9->addWidget(pushButton_14);

        important = new QPushButton(men1_Important);
        important->setObjectName("important");
        important->setFont(font1);
        important->setCursor(QCursor(Qt::PointingHandCursor));
        important->setStyleSheet(QString::fromUtf8("border-radius:15;\n"
"padding:1px;\n"
"text-align:left;\n"
""));
        important->setIconSize(QSize(30, 30));

        horizontalLayout_9->addWidget(important);

        horizontalLayout_9->setStretch(1, 1);

        verticalLayout_7->addWidget(men1_Important);

        men1_Planned = new QFrame(scrollAreaWidgetContents_3);
        men1_Planned->setObjectName("men1_Planned");
        men1_Planned->setCursor(QCursor(Qt::PointingHandCursor));
        men1_Planned->setStyleSheet(QString::fromUtf8("border-radius:4;padding: 10px;"));
        men1_Planned->setFrameShape(QFrame::StyledPanel);
        men1_Planned->setFrameShadow(QFrame::Raised);
        horizontalLayout_12 = new QHBoxLayout(men1_Planned);
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        horizontalLayout_12->setContentsMargins(-1, 0, -1, 0);
        pushButton_15 = new QPushButton(men1_Planned);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setStyleSheet(QString::fromUtf8("border-radius:15;padding: 1px;"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/i/resources/icons/calendar_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_15->setIcon(icon5);
        pushButton_15->setIconSize(QSize(20, 20));

        horizontalLayout_12->addWidget(pushButton_15);

        planned = new QPushButton(men1_Planned);
        planned->setObjectName("planned");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Roboto")});
        font2.setPointSize(18);
        planned->setFont(font2);
        planned->setStyleSheet(QString::fromUtf8("border-radius:15;\n"
"padding:1px;\n"
"text-align:left;\n"
""));

        horizontalLayout_12->addWidget(planned);

        horizontalLayout_12->setStretch(1, 1);

        verticalLayout_7->addWidget(men1_Planned);

        line = new QFrame(scrollAreaWidgetContents_3);
        line->setObjectName("line");
        line->setStyleSheet(QString::fromUtf8("background: qradialgradient(cx:0.5, cy:0.5,radius:1, fx:0.5, fy:0.5, stop:0 #ffffff, stop:1 rgba(255, 255, 255, 0));\n"
"border-radius:3px;\n"
"\n"
"   "));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line);

        list_cont = new QFrame(scrollAreaWidgetContents_3);
        list_cont->setObjectName("list_cont");
        list_cont->setFrameShape(QFrame::StyledPanel);
        list_cont->setFrameShadow(QFrame::Raised);
        list_cont_layout = new QVBoxLayout(list_cont);
        list_cont_layout->setObjectName("list_cont_layout");
        list_cont_layout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_7 = new QSpacerItem(20, 365, QSizePolicy::Minimum, QSizePolicy::Expanding);

        list_cont_layout->addItem(verticalSpacer_7);


        verticalLayout_7->addWidget(list_cont);

        scrollArea_4->setWidget(scrollAreaWidgetContents_3);

        menu_layout->addWidget(scrollArea_4);

        men2_newlist_btn = new QFrame(menu);
        men2_newlist_btn->setObjectName("men2_newlist_btn");
        men2_newlist_btn->setCursor(QCursor(Qt::PointingHandCursor));
        men2_newlist_btn->setStyleSheet(QString::fromUtf8("border-radius:4;padding: 10px;"));
        men2_newlist_btn->setFrameShape(QFrame::StyledPanel);
        men2_newlist_btn->setFrameShadow(QFrame::Raised);
        horizontalLayout_13 = new QHBoxLayout(men2_newlist_btn);
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        horizontalLayout_13->setContentsMargins(-1, 0, -1, 0);
        pushButton_16 = new QPushButton(men2_newlist_btn);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_16->setStyleSheet(QString::fromUtf8("border-radius:15;padding: 1px;"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/i/resources/icons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_16->setIcon(icon6);
        pushButton_16->setIconSize(QSize(20, 20));

        horizontalLayout_13->addWidget(pushButton_16);

        new_btn = new QPushButton(men2_newlist_btn);
        new_btn->setObjectName("new_btn");
        new_btn->setFont(font1);
        new_btn->setCursor(QCursor(Qt::PointingHandCursor));
        new_btn->setStyleSheet(QString::fromUtf8("border-radius:15;\n"
"padding:1px;\n"
"text-align:left;\n"
""));
        new_btn->setIconSize(QSize(30, 30));

        horizontalLayout_13->addWidget(new_btn);

        horizontalLayout_13->setStretch(1, 1);

        menu_layout->addWidget(men2_newlist_btn);

        splitter->addWidget(menu);
        content = new QFrame(splitter);
        content->setObjectName("content");
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(content->sizePolicy().hasHeightForWidth());
        content->setSizePolicy(sizePolicy1);
        content->setMinimumSize(QSize(50, 0));
        content->setStyleSheet(QString::fromUtf8("background:#89E3AB;color:black"));
        content->setFrameShape(QFrame::StyledPanel);
        content->setFrameShadow(QFrame::Raised);
        verticalLayout_18 = new QVBoxLayout(content);
        verticalLayout_18->setSpacing(0);
        verticalLayout_18->setObjectName("verticalLayout_18");
        verticalLayout_18->setContentsMargins(0, 0, 0, 0);
        content_widgets = new QStackedWidget(content);
        content_widgets->setObjectName("content_widgets");
        men1_Today_page = new QWidget();
        men1_Today_page->setObjectName("men1_Today_page");
        verticalLayout_5 = new QVBoxLayout(men1_Today_page);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(-1, 9, -1, -1);
        frame = new QFrame(men1_Today_page);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        frame_3 = new QFrame(frame);
        frame_3->setObjectName("frame_3");
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_17 = new QVBoxLayout(frame_3);
        verticalLayout_17->setSpacing(0);
        verticalLayout_17->setObjectName("verticalLayout_17");
        verticalLayout_17->setContentsMargins(0, 0, 0, 0);
        men0_btn = new QPushButton(frame_3);
        men0_btn->setObjectName("men0_btn");
        men0_btn->setCursor(QCursor(Qt::PointingHandCursor));
        men0_btn->setStyleSheet(QString::fromUtf8("border-radius: 5; padding: 5px;"));
        men0_btn->setIcon(icon2);
        men0_btn->setIconSize(QSize(20, 20));

        verticalLayout_17->addWidget(men0_btn, 0, Qt::AlignLeft);

        label = new QLabel(frame_3);
        label->setObjectName("label");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Roboto")});
        font3.setPointSize(24);
        font3.setBold(true);
        font3.setStrikeOut(false);
        font3.setKerning(false);
        label->setFont(font3);
        label->setScaledContents(true);
        label->setMargin(0);
        label->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout_17->addWidget(label);

        day_date = new QLabel(frame_3);
        day_date->setObjectName("day_date");
        day_date->setWordWrap(false);

        verticalLayout_17->addWidget(day_date);


        horizontalLayout_6->addWidget(frame_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        set3_Today = new QPushButton(frame);
        set3_Today->setObjectName("set3_Today");
        set3_Today->setCursor(QCursor(Qt::PointingHandCursor));
        set3_Today->setStyleSheet(QString::fromUtf8("border-radius: 5px;  padding: 3px;\n"
""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/i/resources/icons/more-horizontal.png"), QSize(), QIcon::Normal, QIcon::Off);
        set3_Today->setIcon(icon7);
        set3_Today->setIconSize(QSize(30, 30));

        horizontalLayout_6->addWidget(set3_Today);


        verticalLayout_5->addWidget(frame);

        line_2 = new QFrame(men1_Today_page);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_2);

        frame_2 = new QFrame(men1_Today_page);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(frame_2);
        verticalLayout_8->setObjectName("verticalLayout_8");
        scrollArea = new QScrollArea(frame_2);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea{\n"
"border:0px;\n"
"}\n"
""));
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 438, 391));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_9 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        frame_7 = new QFrame(scrollAreaWidgetContents);
        frame_7->setObjectName("frame_7");
        frame_7->setStyleSheet(QString::fromUtf8(""));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        today_layout = new QVBoxLayout(frame_7);
        today_layout->setSpacing(9);
        today_layout->setObjectName("today_layout");
        today_layout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        today_layout->addItem(verticalSpacer_2);


        verticalLayout_9->addWidget(frame_7);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_8->addWidget(scrollArea);

        add10_Today = new QFrame(frame_2);
        add10_Today->setObjectName("add10_Today");
        add10_Today->setStyleSheet(QString::fromUtf8("text-align:left;padding:10px;border-radius:5px;background:white;color:black;"));
        add10_Today->setFrameShape(QFrame::StyledPanel);
        add10_Today->setFrameShadow(QFrame::Raised);
        horizontalLayout_15 = new QHBoxLayout(add10_Today);
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        horizontalLayout_15->setContentsMargins(9, 0, 9, 0);
        pushButton_5 = new QPushButton(add10_Today);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setStyleSheet(QString::fromUtf8("border-radius:15;padding: 1px;"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/i/resources/icons/plus.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon8);
        pushButton_5->setIconSize(QSize(20, 20));

        horizontalLayout_15->addWidget(pushButton_5);

        label_2 = new QLabel(add10_Today);
        label_2->setObjectName("label_2");
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("border-radius:15;\n"
"padding:5px;\n"
"text-align:left;\n"
""));

        horizontalLayout_15->addWidget(label_2);

        horizontalLayout_15->setStretch(1, 1);

        verticalLayout_8->addWidget(add10_Today);


        verticalLayout_5->addWidget(frame_2);

        verticalLayout_5->setStretch(2, 2);
        content_widgets->addWidget(men1_Today_page);
        men1_Planned_page = new QWidget();
        men1_Planned_page->setObjectName("men1_Planned_page");
        verticalLayout_2 = new QVBoxLayout(men1_Planned_page);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(9, 9, -1, -1);
        frame_13 = new QFrame(men1_Planned_page);
        frame_13->setObjectName("frame_13");
        frame_13->setFrameShape(QFrame::StyledPanel);
        frame_13->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_13);
        horizontalLayout->setObjectName("horizontalLayout");
        frame_4 = new QFrame(frame_13);
        frame_4->setObjectName("frame_4");
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_4);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        men0_Planned = new QPushButton(frame_4);
        men0_Planned->setObjectName("men0_Planned");
        men0_Planned->setCursor(QCursor(Qt::PointingHandCursor));
        men0_Planned->setStyleSheet(QString::fromUtf8("border-radius: 5; padding: 5px;"));
        men0_Planned->setIcon(icon2);
        men0_Planned->setIconSize(QSize(20, 20));

        verticalLayout_4->addWidget(men0_Planned, 0, Qt::AlignLeft);

        frame_14 = new QFrame(frame_4);
        frame_14->setObjectName("frame_14");
        frame_14->setFrameShape(QFrame::StyledPanel);
        frame_14->setFrameShadow(QFrame::Raised);
        horizontalLayout_10 = new QHBoxLayout(frame_14);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_10->setContentsMargins(0, -1, 0, -1);
        pushButton_3 = new QPushButton(frame_14);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setStyleSheet(QString::fromUtf8("padding:5px;border-radius:4px;border:0px;"));
        pushButton_3->setIcon(icon5);
        pushButton_3->setIconSize(QSize(20, 20));

        horizontalLayout_10->addWidget(pushButton_3);

        label_4 = new QLabel(frame_14);
        label_4->setObjectName("label_4");
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Roboto")});
        font4.setPointSize(24);
        font4.setBold(false);
        font4.setKerning(false);
        label_4->setFont(font4);

        horizontalLayout_10->addWidget(label_4);


        verticalLayout_4->addWidget(frame_14);


        horizontalLayout->addWidget(frame_4);

        horizontalSpacer_4 = new QSpacerItem(463, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        set3_Planned = new QPushButton(frame_13);
        set3_Planned->setObjectName("set3_Planned");
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(set3_Planned->sizePolicy().hasHeightForWidth());
        set3_Planned->setSizePolicy(sizePolicy2);
        set3_Planned->setCursor(QCursor(Qt::PointingHandCursor));
        set3_Planned->setStyleSheet(QString::fromUtf8("border-radius: 5px;  padding: 3px;\n"
""));
        set3_Planned->setIcon(icon7);
        set3_Planned->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(set3_Planned);


        verticalLayout_2->addWidget(frame_13);

        line_4 = new QFrame(men1_Planned_page);
        line_4->setObjectName("line_4");
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_4);

        frame_18 = new QFrame(men1_Planned_page);
        frame_18->setObjectName("frame_18");
        frame_18->setFrameShape(QFrame::StyledPanel);
        frame_18->setFrameShadow(QFrame::Raised);
        verticalLayout_20 = new QVBoxLayout(frame_18);
        verticalLayout_20->setObjectName("verticalLayout_20");
        scrollArea_2 = new QScrollArea(frame_18);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setStyleSheet(QString::fromUtf8("QScrollArea{border:0px}"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 438, 387));
        verticalLayout_6 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        frame_15 = new QFrame(scrollAreaWidgetContents_2);
        frame_15->setObjectName("frame_15");
        frame_15->setFrameShape(QFrame::StyledPanel);
        frame_15->setFrameShadow(QFrame::Raised);
        planned_layout = new QVBoxLayout(frame_15);
        planned_layout->setSpacing(9);
        planned_layout->setObjectName("planned_layout");
        planned_layout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 415, QSizePolicy::Minimum, QSizePolicy::Expanding);

        planned_layout->addItem(verticalSpacer);


        verticalLayout_6->addWidget(frame_15);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_20->addWidget(scrollArea_2);

        add10_Planned = new QFrame(frame_18);
        add10_Planned->setObjectName("add10_Planned");
        add10_Planned->setMinimumSize(QSize(0, 0));
        add10_Planned->setStyleSheet(QString::fromUtf8("text-align:left;padding:10px;border-radius:5px;background:white;color:black;"));
        add10_Planned->setFrameShape(QFrame::StyledPanel);
        add10_Planned->setFrameShadow(QFrame::Raised);
        horizontalLayout_17 = new QHBoxLayout(add10_Planned);
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        horizontalLayout_17->setContentsMargins(9, 0, 9, 0);
        pushButton_7 = new QPushButton(add10_Planned);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setStyleSheet(QString::fromUtf8("border-radius:15;padding: 1px;"));
        pushButton_7->setIcon(icon8);
        pushButton_7->setIconSize(QSize(20, 20));

        horizontalLayout_17->addWidget(pushButton_7);

        label_6 = new QLabel(add10_Planned);
        label_6->setObjectName("label_6");
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setFont(font2);
        label_6->setStyleSheet(QString::fromUtf8("border-radius:15;\n"
"padding:5px;\n"
"text-align:left;\n"
""));

        horizontalLayout_17->addWidget(label_6);

        horizontalLayout_17->setStretch(1, 1);

        verticalLayout_20->addWidget(add10_Planned);


        verticalLayout_2->addWidget(frame_18);

        verticalLayout_2->setStretch(2, 2);
        content_widgets->addWidget(men1_Planned_page);
        men1_Important_page = new QWidget();
        men1_Important_page->setObjectName("men1_Important_page");
        men1_Important_page->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_3 = new QVBoxLayout(men1_Important_page);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(9, 9, -1, 9);
        frame_10 = new QFrame(men1_Important_page);
        frame_10->setObjectName("frame_10");
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_10);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        frame_6 = new QFrame(frame_10);
        frame_6->setObjectName("frame_6");
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        verticalLayout_16 = new QVBoxLayout(frame_6);
        verticalLayout_16->setSpacing(0);
        verticalLayout_16->setObjectName("verticalLayout_16");
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        men0_Important = new QPushButton(frame_6);
        men0_Important->setObjectName("men0_Important");
        men0_Important->setCursor(QCursor(Qt::PointingHandCursor));
        men0_Important->setStyleSheet(QString::fromUtf8("border-radius: 5; padding: 5px;"));
        men0_Important->setIcon(icon2);
        men0_Important->setIconSize(QSize(20, 20));

        verticalLayout_16->addWidget(men0_Important, 0, Qt::AlignLeft);

        frame_11 = new QFrame(frame_6);
        frame_11->setObjectName("frame_11");
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        horizontalLayout_8 = new QHBoxLayout(frame_11);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(0, -1, 0, -1);
        pushButton = new QPushButton(frame_11);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("padding:5px;border-radius:4px;border:0px;"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/i/resources/icons/star.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon9);
        pushButton->setIconSize(QSize(20, 20));

        horizontalLayout_8->addWidget(pushButton);

        label_3 = new QLabel(frame_11);
        label_3->setObjectName("label_3");
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Roboto")});
        font5.setPointSize(24);
        label_3->setFont(font5);

        horizontalLayout_8->addWidget(label_3);


        verticalLayout_16->addWidget(frame_11);


        horizontalLayout_5->addWidget(frame_6);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        set3_Important = new QPushButton(frame_10);
        set3_Important->setObjectName("set3_Important");
        sizePolicy2.setHeightForWidth(set3_Important->sizePolicy().hasHeightForWidth());
        set3_Important->setSizePolicy(sizePolicy2);
        set3_Important->setCursor(QCursor(Qt::PointingHandCursor));
        set3_Important->setStyleSheet(QString::fromUtf8("border-radius: 5px;  padding: 3px;\n"
""));
        set3_Important->setIcon(icon7);
        set3_Important->setIconSize(QSize(30, 30));

        horizontalLayout_5->addWidget(set3_Important);


        verticalLayout_3->addWidget(frame_10);

        line_3 = new QFrame(men1_Important_page);
        line_3->setObjectName("line_3");
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_3);

        frame_9 = new QFrame(men1_Important_page);
        frame_9->setObjectName("frame_9");
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        verticalLayout_10 = new QVBoxLayout(frame_9);
        verticalLayout_10->setObjectName("verticalLayout_10");
        scrollArea_3 = new QScrollArea(frame_9);
        scrollArea_3->setObjectName("scrollArea_3");
        scrollArea_3->setStyleSheet(QString::fromUtf8("QScrollArea{border:0}"));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName("scrollAreaWidgetContents_4");
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 438, 387));
        verticalLayout_11 = new QVBoxLayout(scrollAreaWidgetContents_4);
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setObjectName("verticalLayout_11");
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        frame_12 = new QFrame(scrollAreaWidgetContents_4);
        frame_12->setObjectName("frame_12");
        frame_12->setFrameShape(QFrame::StyledPanel);
        frame_12->setFrameShadow(QFrame::Raised);
        important_layout = new QVBoxLayout(frame_12);
        important_layout->setSpacing(9);
        important_layout->setObjectName("important_layout");
        important_layout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_3 = new QSpacerItem(20, 415, QSizePolicy::Minimum, QSizePolicy::Expanding);

        important_layout->addItem(verticalSpacer_3);


        verticalLayout_11->addWidget(frame_12);

        scrollArea_3->setWidget(scrollAreaWidgetContents_4);

        verticalLayout_10->addWidget(scrollArea_3);

        add10_Important = new QFrame(frame_9);
        add10_Important->setObjectName("add10_Important");
        add10_Important->setStyleSheet(QString::fromUtf8("text-align:left;padding:10px;border-radius:5px;background:white;color:black;"));
        add10_Important->setFrameShape(QFrame::StyledPanel);
        add10_Important->setFrameShadow(QFrame::Raised);
        horizontalLayout_16 = new QHBoxLayout(add10_Important);
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        horizontalLayout_16->setContentsMargins(9, 0, 9, 0);
        pushButton_6 = new QPushButton(add10_Important);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setStyleSheet(QString::fromUtf8("border-radius:15;padding: 1px;"));
        pushButton_6->setIcon(icon8);
        pushButton_6->setIconSize(QSize(20, 20));

        horizontalLayout_16->addWidget(pushButton_6);

        label_5 = new QLabel(add10_Important);
        label_5->setObjectName("label_5");
        label_5->setFont(font2);
        label_5->setStyleSheet(QString::fromUtf8("border-radius:15;\n"
"padding:5px;\n"
"text-align:left;\n"
""));

        horizontalLayout_16->addWidget(label_5);

        horizontalLayout_16->setStretch(1, 1);

        verticalLayout_10->addWidget(add10_Important);


        verticalLayout_3->addWidget(frame_9);

        verticalLayout_3->setStretch(2, 2);
        content_widgets->addWidget(men1_Important_page);
        men1_Settings_page = new QWidget();
        men1_Settings_page->setObjectName("men1_Settings_page");
        content_widgets->addWidget(men1_Settings_page);

        verticalLayout_18->addWidget(content_widgets);

        splitter->addWidget(content);
        third_panel = new QFrame(splitter);
        third_panel->setObjectName("third_panel");
        third_panel->setMinimumSize(QSize(270, 0));
        third_panel->setMaximumSize(QSize(430, 16777215));
        third_panel->setFrameShape(QFrame::StyledPanel);
        third_panel->setFrameShadow(QFrame::Raised);
        third_panel_info = new QVBoxLayout(third_panel);
        third_panel_info->setSpacing(0);
        third_panel_info->setObjectName("third_panel_info");
        third_panel_info->setContentsMargins(0, 5, 0, 0);
        tic13_btn = new QPushButton(third_panel);
        tic13_btn->setObjectName("tic13_btn");
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tic13_btn->sizePolicy().hasHeightForWidth());
        tic13_btn->setSizePolicy(sizePolicy3);
        tic13_btn->setCursor(QCursor(Qt::PointingHandCursor));
        tic13_btn->setStyleSheet(QString::fromUtf8("background: qradialgradient(cx: 0.5, cy: 0.1, fx: 0.5, fy: 0.1, radius: 1.5, stop: 0 #ffffff, stop: 1 #000000);\n"
"\n"
"border-bottom-left-radius:10px;\n"
"border-bottom-right-radius:10px;\n"
"height: 15px;\n"
"width: 100px;"));

        third_panel_info->addWidget(tic13_btn, 0, Qt::AlignHCenter);

        third_panel_scrollarea = new QScrollArea(third_panel);
        third_panel_scrollarea->setObjectName("third_panel_scrollarea");
        third_panel_scrollarea->setStyleSheet(QString::fromUtf8("QScrollArea{border:0px}"));
        third_panel_scrollarea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        third_panel_scrollarea->setWidgetResizable(true);
        third_panel_srcollcontent = new QWidget();
        third_panel_srcollcontent->setObjectName("third_panel_srcollcontent");
        third_panel_srcollcontent->setGeometry(QRect(0, 0, 270, 596));
        third_panel_srcollcontent->setMinimumSize(QSize(270, 0));
        third_panel_srcollcontent->setMaximumSize(QSize(430, 16777215));
        third_panel_layout = new QVBoxLayout(third_panel_srcollcontent);
        third_panel_layout->setSpacing(4);
        third_panel_layout->setObjectName("third_panel_layout");
        third_panel_layout->setContentsMargins(-1, 0, -1, 0);
        third_panel_scrollarea->setWidget(third_panel_srcollcontent);

        third_panel_info->addWidget(third_panel_scrollarea);

        splitter->addWidget(third_panel);

        horizontalLayout_3->addWidget(splitter);


        verticalLayout->addWidget(body);

        verticalLayout->setStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        content_widgets->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        mini_btn->setText(QString());
        maxi_btn->setText(QString());
        exit_btn->setText(QString());
        pushButton_18->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_12->setText(QString());
        pushButton_17->setText(QString());
        men0_nav_btn->setText(QString());
        pushButton_13->setText(QString());
        today->setText(QCoreApplication::translate("MainWindow", "Today", nullptr));
        pushButton_14->setText(QString());
        important->setText(QCoreApplication::translate("MainWindow", "Important", nullptr));
        pushButton_15->setText(QString());
        planned->setText(QCoreApplication::translate("MainWindow", "Planned", nullptr));
        pushButton_16->setText(QString());
        new_btn->setText(QCoreApplication::translate("MainWindow", "New List", nullptr));
        men0_btn->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Today", nullptr));
        day_date->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        set3_Today->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "Add Task", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Planned", nullptr));
        set3_Planned->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "Add Task", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Important", nullptr));
        set3_Important->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Add Task", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
