/********************************************************************************
** Form generated from reading UI file 'menu_bar_demo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_BAR_DEMO_H
#define UI_MENU_BAR_DEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menu_bar_demo
{
public:
    QAction *actionCount;
    QAction *actionExit;
    QAction *actionZoom_in;
    QAction *actionZoom_out;
    QAction *actionMove_North;
    QAction *actionMove_South;
    QAction *actionMove_East;
    QAction *actionMove_West;
    QAction *actionLibRef;
    QAction *actionPopulation;
    QAction *actionDrainage;
    QAction *actionPolit_Ocean;
    QWidget *centralwidget;
    QLineEdit *count_text_field;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuCtrl;
    QMenu *menuThemes;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *menu_bar_demo)
    {
        if (menu_bar_demo->objectName().isEmpty())
            menu_bar_demo->setObjectName(QString::fromUtf8("menu_bar_demo"));
        menu_bar_demo->resize(706, 344);
        actionCount = new QAction(menu_bar_demo);
        actionCount->setObjectName(QString::fromUtf8("actionCount"));
        actionExit = new QAction(menu_bar_demo);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionZoom_in = new QAction(menu_bar_demo);
        actionZoom_in->setObjectName(QString::fromUtf8("actionZoom_in"));
        actionZoom_out = new QAction(menu_bar_demo);
        actionZoom_out->setObjectName(QString::fromUtf8("actionZoom_out"));
        actionMove_North = new QAction(menu_bar_demo);
        actionMove_North->setObjectName(QString::fromUtf8("actionMove_North"));
        actionMove_South = new QAction(menu_bar_demo);
        actionMove_South->setObjectName(QString::fromUtf8("actionMove_South"));
        actionMove_East = new QAction(menu_bar_demo);
        actionMove_East->setObjectName(QString::fromUtf8("actionMove_East"));
        actionMove_West = new QAction(menu_bar_demo);
        actionMove_West->setObjectName(QString::fromUtf8("actionMove_West"));
        actionLibRef = new QAction(menu_bar_demo);
        actionLibRef->setObjectName(QString::fromUtf8("actionLibRef"));
        actionPopulation = new QAction(menu_bar_demo);
        actionPopulation->setObjectName(QString::fromUtf8("actionPopulation"));
        actionDrainage = new QAction(menu_bar_demo);
        actionDrainage->setObjectName(QString::fromUtf8("actionDrainage"));
        actionPolit_Ocean = new QAction(menu_bar_demo);
        actionPolit_Ocean->setObjectName(QString::fromUtf8("actionPolit_Ocean"));
        centralwidget = new QWidget(menu_bar_demo);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        count_text_field = new QLineEdit(centralwidget);
        count_text_field->setObjectName(QString::fromUtf8("count_text_field"));
        count_text_field->setGeometry(QRect(170, 200, 113, 25));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 200, 67, 17));
        menu_bar_demo->setCentralWidget(centralwidget);
        menubar = new QMenuBar(menu_bar_demo);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 706, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuCtrl = new QMenu(menubar);
        menuCtrl->setObjectName(QString::fromUtf8("menuCtrl"));
        menuThemes = new QMenu(menubar);
        menuThemes->setObjectName(QString::fromUtf8("menuThemes"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menu_bar_demo->setMenuBar(menubar);
        statusbar = new QStatusBar(menu_bar_demo);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        menu_bar_demo->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuCtrl->menuAction());
        menubar->addAction(menuThemes->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionCount);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuCtrl->addAction(actionZoom_in);
        menuCtrl->addAction(actionZoom_out);
        menuCtrl->addAction(actionMove_North);
        menuCtrl->addAction(actionMove_South);
        menuCtrl->addAction(actionMove_East);
        menuCtrl->addAction(actionMove_West);
        menuThemes->addAction(actionLibRef);
        menuThemes->addAction(actionPopulation);
        menuThemes->addAction(actionDrainage);
        menuThemes->addAction(actionPolit_Ocean);

        retranslateUi(menu_bar_demo);

        QMetaObject::connectSlotsByName(menu_bar_demo);
    } // setupUi

    void retranslateUi(QMainWindow *menu_bar_demo)
    {
        menu_bar_demo->setWindowTitle(QApplication::translate("menu_bar_demo", "menu_bar_demo", nullptr));
        actionCount->setText(QApplication::translate("menu_bar_demo", "Count", nullptr));
        actionExit->setText(QApplication::translate("menu_bar_demo", "Exit", nullptr));
        actionZoom_in->setText(QApplication::translate("menu_bar_demo", "Zoom in", nullptr));
        actionZoom_out->setText(QApplication::translate("menu_bar_demo", "Zoom out", nullptr));
        actionMove_North->setText(QApplication::translate("menu_bar_demo", "Move North", nullptr));
        actionMove_South->setText(QApplication::translate("menu_bar_demo", "Move South", nullptr));
        actionMove_East->setText(QApplication::translate("menu_bar_demo", "Move East", nullptr));
        actionMove_West->setText(QApplication::translate("menu_bar_demo", "Move West", nullptr));
        actionLibRef->setText(QApplication::translate("menu_bar_demo", "LibRef", nullptr));
        actionPopulation->setText(QApplication::translate("menu_bar_demo", "Population", nullptr));
        actionDrainage->setText(QApplication::translate("menu_bar_demo", "Drainage", nullptr));
        actionPolit_Ocean->setText(QApplication::translate("menu_bar_demo", "Polit_Ocean", nullptr));
        label->setText(QApplication::translate("menu_bar_demo", "Count", nullptr));
        menuFile->setTitle(QApplication::translate("menu_bar_demo", "File", nullptr));
        menuCtrl->setTitle(QApplication::translate("menu_bar_demo", "Ctrl", nullptr));
        menuThemes->setTitle(QApplication::translate("menu_bar_demo", "Themes", nullptr));
        menuHelp->setTitle(QApplication::translate("menu_bar_demo", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menu_bar_demo: public Ui_menu_bar_demo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_BAR_DEMO_H
