//============================================================================
// FILE: basic_graphics.cpp
//
// DESCRIPTION:
//    Manages the 'basic-graphics' panel.
//============================================================================
#include <iostream>

#include <QPainter>
#include <QPaintEvent>

#include "basic_graphics.h"
#include "ui_basic_graphics.h"

//========================================================
// METHOD: basic_graphics_MainWindow 
//
// DESCRIPTION:
//    Constructor as entry point to create the GUI/Window
//    of the application.
//========================================================
basic_graphics_MainWindow::basic_graphics_MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::basic_graphics_MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionExitButton,
            &QAction::triggered,
            this,
            &basic_graphics_MainWindow::exit_action_slot);

    connect(ui->actionGridButton,
            &QAction::triggered,
            this,
            &basic_graphics_MainWindow::draw_grid_action_slot);
}

basic_graphics_MainWindow::~basic_graphics_MainWindow()
{
    delete ui;
}

void basic_graphics_MainWindow::exit_action_slot()
{
   std::exit(0);
}

void basic_graphics_MainWindow::draw_grid_action_slot()
{
   if (draw_grid)
      draw_grid = false;
   else
      draw_grid = true;

   std::cout << "Grid: " << draw_grid << "\n";

   update();
}

void basic_graphics_MainWindow::paintEvent(QPaintEvent *event)
{
    if (!event)
    {
        std::cout << "ERROR - paint event is NULL\n";
        return;
    }

    if (draw_grid)
    {
        QPainter painter(this);

        x = ui->centralwidget->width() / 2;
        y = ui->centralwidget->height();

        const QLine x_axis(x, 0, x, y);

        painter.drawLine(x_axis);

        x = ui->centralwidget->width();
        y = ui->centralwidget->height() / 2;

        const QLine y_axis(0, y, x, y);

        painter.drawLine(y_axis);
    }
}

/* EOF */

