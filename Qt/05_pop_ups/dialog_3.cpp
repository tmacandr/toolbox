#include <iostream>

#include <QRadioButton>

#include "dialog_3.h"

Dialog_3_Window::Dialog_3_Window(QWidget *parent)

      : QDialog(parent),
        ui(new Ui_Dialog_3_Window)  // <-- Again, no 'namespace' stuff

{
    ui->setupUi(this);

    QRadioButton *radio_btn = ui->dialog_3_radio_button;

    connect(radio_btn,
            &QRadioButton::clicked,
            this,
            &Dialog_3_Window::dialog_3_radio_button_clicked);
}

Dialog_3_Window::~Dialog_3_Window()
{
    delete ui;
}

void Dialog_3_Window::dialog_3_radio_button_clicked()
{
   QRadioButton *rb = ui->dialog_3_radio_button;
    
   bool ON = rb->isChecked();

   std::string state = (ON ? "ON" : "OFF");

   std::cout << "Dialog 3 radio button: " << state << "\n";
}

/* EOF */

