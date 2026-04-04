#include "basic_graphics.h"
#include "ui_basic_graphics.h"

basic_graphics_MainWindow::basic_graphics_MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::basic_graphics_MainWindow)
{
    ui->setupUi(this);
}

basic_graphics_MainWindow::~basic_graphics_MainWindow()
{
    delete ui;
}

