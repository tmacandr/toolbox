//============================================================================
// FILE: menu_bar_demo.cpp
//
// DESCRIPTION:
//    Manages the 'menu-bar' demo.
//
//    See README.md about how to define 'slots' for the buttons in the
//    menu-bar pulldowns.  Very clunky.
//============================================================================
#include <iostream>
#include "menu_bar_demo.h"
#include "ui_menu_bar_demo.h"


menu_bar_demo::menu_bar_demo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::menu_bar_demo)
{
    ui->setupUi(this);

    connect(ui->actionCount,
            &QAction::triggered,
            this,
            &menu_bar_demo::count_action_slot);
}

menu_bar_demo::~menu_bar_demo()
{
    delete ui;
}

void menu_bar_demo::count_action_slot()
{
   count++;

   std::cout << "Count: " << count << "\n";
}

void menu_bar_demo::exit_action_slot()
{
}
