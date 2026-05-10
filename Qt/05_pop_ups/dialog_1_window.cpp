//============================================================================
// FILE: dialog_1_window.cpp
//
// DESCRIPTION:
//    Manages the 'dialog 1' window of 'pop up' demo.
//============================================================================
#include <iostream>

#include "dialog_1_window.h"
#include "ui_dialog_1.h"

Dialog_1_Window::Dialog_1_Window(QWidget *parent)

    : QMainWindow(parent),
      ui(new Ui_Dialog_1_Window)

{
    ui->setupUi(this);
}

Dialog_1_Window::~Dialog_1_Window()
{
    delete ui;
}

void Dialog_1_Window::exit_action_slot()
{
    std::exit(0);
}

/* EOF */

