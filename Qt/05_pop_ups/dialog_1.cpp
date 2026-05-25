#include <iostream>

#include <QPushButton>
#include <QDialogButtonBox>

#include "dialog_1.h"

Dialog_1_Window::Dialog_1_Window(QWidget *parent)

   : QDialog(parent),
     ui(new Ui_Dialog_1_Window)  // <-- Again, no 'namespace' stuff

{
    ui->setupUi(this);

    QPushButton *pb1 = ui->dialog_1_push_1;

    connect(pb1,
            &QPushButton::clicked,
            this,
            &Dialog_1_Window::dialog_1_push_1_clicked);

    QDialogButtonBox *btn_box;

    btn_box = ui->buttonBox;

    QPushButton *ok_btn = btn_box->button(QDialogButtonBox::Ok);
    
    connect(ok_btn,
            &QPushButton::clicked,
            this,
            &Dialog_1_Window::dialog_1_OK_button_clicked);
}

Dialog_1_Window::~Dialog_1_Window()
{
    delete ui;
}

void Dialog_1_Window::dialog_1_push_1_clicked()
{
    std::cout << "Dialog 1 - Push 1\n";
}

void Dialog_1_Window::dialog_1_OK_button_clicked()
{
    std::cout << "Dialog 1 - OK button\n";
}

/* EOF */

