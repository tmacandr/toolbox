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
