#include "pop_up_demo_main_window.h"
#include "ui_pop_up_demo_main_window.h"

pop_up_demo_Main_Window::pop_up_demo_Main_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::pop_up_demo_Main_Window)
{
    ui->setupUi(this);
}

pop_up_demo_Main_Window::~pop_up_demo_Main_Window()
{
    delete ui;
}


void pop_up_demo_Main_Window::on_pushButton_clicked()
{
    // pop up 1 button
}
