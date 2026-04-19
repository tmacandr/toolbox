//============================================================================
// FILE: basic_graphics.cpp
//
// DESCRIPTION:
//    Manages the 'basic-graphics' panel.
//============================================================================
#include <iostream>

#include <QPainter>
#include <QPaintEvent>

#include <QSplitter>
#include <QWidget>
#include <QHBoxLayout>

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

    : QMainWindow(parent),

    ui(new Ui::basic_graphics_MainWindow)
{
    ui->setupUi(this);

    QWidget *central = ui->centralwidget;

    setCentralWidget(central);

    graphics_window = new GraphicsWindow(this);
    text_window     = new TextWindow(this);

    QSplitter *splitter = new QSplitter(Qt::Horizontal, this);

    splitter->addWidget(graphics_window);
    splitter->addWidget(text_window);

    splitter->setSizes({400, 100});

    QHBoxLayout *layout = new QHBoxLayout(central);

    layout->addWidget(splitter);

    connect(ui->actionExitButton,
            &QAction::triggered,
            this,
            &basic_graphics_MainWindow::exit_action_slot);

    connect(ui->actionGridButton,
            &QAction::triggered,
            this,
            &basic_graphics_MainWindow::update_grid_action_slot);

    connect(ui->actionLineButton,
            &QAction::triggered,
            this,
            &basic_graphics_MainWindow::draw_line_action_slot);

    connect(ui->actionCircleButton,
            &QAction::triggered,
            this,
            &basic_graphics_MainWindow::draw_circle_action_slot);

    connect(ui->actionOvalButton,
            &QAction::triggered,
            this,
            &basic_graphics_MainWindow::draw_oval_action_slot);

    connect(ui->actionSine_WaveButton,
            &QAction::triggered,
            this,
            &basic_graphics_MainWindow::draw_sine_action_slot);

    connect(ui->actionCosine_WaveButton,
            &QAction::triggered,
            this,
            &basic_graphics_MainWindow::draw_cosine_action_slot);

    connect(ui->actionTangentButton,
            &QAction::triggered,
            this,
            &basic_graphics_MainWindow::draw_tangent_action_slot);

    connect(ui->actionCotangentButton,
            &QAction::triggered,
            this,
            &basic_graphics_MainWindow::draw_cotangent_action_slot);

    connect(ui->actionSecantButton,
            &QAction::triggered,
            this,
            &basic_graphics_MainWindow::draw_secant_action_slot);

    connect(ui->actionCosecantButton,
            &QAction::triggered,
            this,
            &basic_graphics_MainWindow::draw_cosecant_action_slot);
}

basic_graphics_MainWindow::~basic_graphics_MainWindow()
{
    delete ui;
}

void basic_graphics_MainWindow::exit_action_slot()
{
   std::exit(0);
}

void basic_graphics_MainWindow::update_grid_action_slot()
{
    graphics_window->update_grid();

    int w = graphics_window->width();
    int h = graphics_window->height();

    text_window->update_canvas_dim(w, h); 

    text_window->update_grid();
}

void basic_graphics_MainWindow::draw_line_action_slot()
{
    graphics_window->update_line();

    text_window->update_line();
}

void basic_graphics_MainWindow::draw_circle_action_slot()
{
    graphics_window->update_circle();

    text_window->update_circle();
}

void basic_graphics_MainWindow::draw_oval_action_slot()
{
    graphics_window->update_oval();

    text_window->update_oval();
}

void basic_graphics_MainWindow::draw_sine_action_slot()
{
    graphics_window->update_sine();

    text_window->update_sine();
}

void basic_graphics_MainWindow::draw_cosine_action_slot()
{
    graphics_window->update_cosine();

    text_window->update_cosine();
}

void basic_graphics_MainWindow::draw_tangent_action_slot()
{
    graphics_window->update_tangent();

    text_window->update_tangent();
}

void basic_graphics_MainWindow::draw_cotangent_action_slot()
{
    graphics_window->update_cotangent();

    text_window->update_cotangent();
}

void basic_graphics_MainWindow::draw_secant_action_slot()
{
    graphics_window->update_secant();

    text_window->update_secant();
}

void basic_graphics_MainWindow::draw_cosecant_action_slot()
{
    graphics_window->update_cosecant();

    text_window->update_cosecant();
}

/* EOF */

