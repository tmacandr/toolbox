//============================================================================
// FILE: data_entry.cpp
//
// DESCRIPTION:
//    Manages the 'data-entry' panel.  Extracts the data from the
//    text-fiels and writes them (as ASCII text) to a file.
//============================================================================
#include <iostream>
#include "data_entry.h"
#include "ui_data_entry.h"

data_entry::data_entry(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::data_entry)
{
    ui->setupUi(this);
}

data_entry::~data_entry()
{
    delete ui;
}


void data_entry::on_exit_button_clicked()
{
    std::exit(0);
}

void data_entry::on_cancel_button_clicked()
{
    ui->name_text_field->clear();
    ui->address_text_field->clear();
    ui->city_text_field->clear();
    ui->state_text_field->clear();
    ui->zip_text_field->clear();
    ui->phone_text_field->clear();
}

void data_entry::on_save_button_clicked()
{
    QString tmp = ui->name_text_field->text();

    std::string name = tmp.toStdString();

    tmp = ui->address_text_field->text();

    std::string address = tmp.toStdString();

    tmp = ui->city_text_field->text();

    std::string city = tmp.toStdString();

    tmp = ui->state_text_field->text();

    std::string state = tmp.toStdString();

    tmp = ui->zip_text_field->text();

    std::string zip = tmp.toStdString();

    tmp = ui->phone_text_field->text();

    std::string phone = tmp.toStdString();

    std::cout << "Name.....: " << name       << "\n"
              << "Address..: " << address    << "\n"
              << "City.....: " << city       << "\n"
              << "State....: " << state      << "\n"
              << "ZIP......: " << zip        << "\n"
              << "Phone....: " << phone      << "\n";
}
