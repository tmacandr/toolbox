#include <iostream>

#include "pop_up_demo_main_window.h"
#include "ui_pop_up_demo_main_window.h"

pop_up_demo_Main_Window::pop_up_demo_Main_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::pop_up_demo_Main_Window)
{
    ui->setupUi(this);

    connect(ui->actionDialog_1,
            &QAction::triggered,
            this,
            &pop_up_demo_Main_Window::dialog_1_action_slot);

    connect(ui->actionExit,
            &QAction::triggered,
            this,
            &pop_up_demo_Main_Window::exit_action_slot);

    connect(ui->actionDialog_2,
            &QAction::triggered,
            this,
            &pop_up_demo_Main_Window::dialog_2_action_slot);
}

pop_up_demo_Main_Window::~pop_up_demo_Main_Window()
{
    if (dialog_1)
    {
        delete dialog_1;
    }

    if (dialog_2)
    {
        delete dialog_2;
    }

    if (dialog_3)
    {
        delete dialog_3;
    }

    delete ui;
}


void pop_up_demo_Main_Window::on_dialog_3_button_clicked()
{
    std::cout << "dialog 3 button\n";

    if ( not dialog_3 )
    {
        dialog_3 = new Dialog_3_Window(this);
    }

    dialog_3->show();
}

void pop_up_demo_Main_Window::dialog_1_action_slot()
{
    std::cout << "pop up 1\n";

    if ( not dialog_1 )
    {
        dialog_1 = new Dialog_1_Window(this);
    }

    dialog_1->show();
}

void pop_up_demo_Main_Window::exit_action_slot()
{
    std::exit(0);
}

void pop_up_demo_Main_Window::dialog_2_action_slot()
{
    std::cout << "pop up 2\n";

    if ( not dialog_2 )
    {
        dialog_2 = new Dialog_2_Window(this);
    }

    dialog_2->show();
}

/* EOF */

