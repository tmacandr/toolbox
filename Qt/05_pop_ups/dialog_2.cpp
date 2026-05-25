#include <iostream>

#include <QPushButton>
#include <QLineEdit>

#include "dialog_2.h"

Dialog_2_Window::Dialog_2_Window(QWidget *parent)

      : QDialog(parent),
        ui(new Ui_Dialog_2_Window)  // <-- Again, no 'namespace' stuff

{
    ui->setupUi(this);

    QPushButton *update_btn = ui->dialog_2_update_button;

    connect(update_btn,
            &QPushButton::clicked,
            this,
            &Dialog_2_Window::dialog_2_update_button_clicked);
}

Dialog_2_Window::~Dialog_2_Window()
{
    delete ui;
}

void Dialog_2_Window::dialog_2_update_button_clicked()
{
    count++;

    std::cout << "dialog 2 update - count: " << (int) count << "\n";

    QLineEdit *txt_field = ui->dialog_2_text_field;

    std::string value = std::to_string(count);

    txt_field->setText(value.c_str());
}

/* EOF */

