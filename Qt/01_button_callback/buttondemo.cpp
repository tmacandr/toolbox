#include <iostream>

#include "buttondemo.h"
#include "ui_buttondemo.h"

ButtonDemo::ButtonDemo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ButtonDemo)
{
    ui->setupUi(this);
}

ButtonDemo::~ButtonDemo()
{
    delete ui;
}


void ButtonDemo::on_count_button_clicked()
{
    count++;

    std::cout << "Count = " << count << "\n";

    std::string value = std::to_string(count);

    ui->count_line->setText(value.c_str());
}

void ButtonDemo::on_reset_button_clicked()
{
    count = 0;

    std::cout << "Reset Count = " << count << "\n";

    std::string value = std::to_string(count);

    ui->count_line->setText(value.c_str());
}

void ButtonDemo::on_exit_button_clicked()
{
    std::exit(0);
}
