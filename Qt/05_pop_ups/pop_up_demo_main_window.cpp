//============================================================================
// FILE: pop_up_demo_main_window.h
//
// DESCRIPTION:
//    Manages the 'pop up' demo.
//============================================================================
#include <iostream>

#include "pop_up_demo_main_window.h"
#include "ui_pop_up_demo_main_window.h"

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
    delete ui;
}

void pop_up_demo_Main_Window::pop_up_1_action_slot()
{
    std::cout << "pop up 1\n";
}

void pop_up_demo_Main_Window::exit_action_slot()
{
    std::exit(0);
}

void pop_up_demo_Main_Window::pop_up_2_action_slot()
{
    std::cout << "pop up 2\n";
}

void pop_up_demo_Main_Window::on_pop_up_3_pushButton_clicked()
{
    std::cout << "pop up pushButton\n";
}

/* EOF */

