//============================================================================
// FILE: pop_up_demo_main_window.h
//
// DESCRIPTION:
//    Manages the 'pop up' demo.
//============================================================================
#include <iostream>

#include <QDialog>

#include "pop_up_demo_main_window.h"
#include "ui_pop_up_demo_main_window.h"


static QDialog *dialog_1 = NULL;
static QDialog *dialog_2 = NULL;
static QDialog *dialog_3 = NULL;


pop_up_demo_Main_Window::pop_up_demo_Main_Window(QWidget *parent)

    : QMainWindow(parent),
      ui(new Ui::pop_up_demo_Main_Window)

{
    ui->setupUi(this);

    connect(ui->actionPop_Up_1,
            &QAction::triggered,
            this,
            &pop_up_demo_Main_Window::pop_up_1_action_slot);

    connect(ui->actionExit,
            &QAction::triggered,
            this,
            &pop_up_demo_Main_Window::exit_action_slot);

    // Ctrl
    connect(ui->actionPop_Up_2,
            &QAction::triggered,
            this,
            &pop_up_demo_Main_Window::pop_up_2_action_slot);

}

pop_up_demo_Main_Window::~pop_up_demo_Main_Window()
{
    if (dialog_1) delete dialog_1;
    if (dialog_2) delete dialog_2;
    if (dialog_3) delete dialog_3;

    delete ui;
}

void pop_up_demo_Main_Window::pop_up_1_action_slot()
{
    std::cout << "pop up 1\n";

    if ( ! dialog_1 )
    {
        dialog_1 = new QDialog(ui->centralwidget, Qt::Dialog);
    }

    dialog_1->setVisible(true);

    dialog_1->show();
}

void pop_up_demo_Main_Window::exit_action_slot()
{
    std::exit(0);
}

void pop_up_demo_Main_Window::pop_up_2_action_slot()
{
    std::cout << "pop up 2\n";

    if ( ! dialog_2 )
    {
        dialog_2 = new QDialog(ui->centralwidget, Qt::Dialog);
    }

    dialog_2->setVisible(true);

    dialog_2->show();
}

void pop_up_demo_Main_Window::on_pop_up_3_pushButton_clicked()
{
    std::cout << "pop up pushButton\n";

    if ( ! dialog_3 )
    {
        dialog_3 = new QDialog(ui->centralwidget, Qt::Dialog);
    }

    dialog_3->setVisible(true);

    dialog_3->show();
}

/* EOF */

