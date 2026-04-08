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

#include "graphics_palette.h"
#include "text_palette.h"
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

    GraphicsPalette *graphics_palette = new GraphicsPalette(this);
    TextPalette     *text_palette     = new TextPalette(this);

    QSplitter *splitter = new QSplitter(Qt::Horizontal, this);

    splitter->addWidget(graphics_palette);
    splitter->addWidget(text_palette);

    splitter->setSizes({300, 200});

    QHBoxLayout *layout = new QHBoxLayout(central);

    layout->addWidget(splitter);

    connect(ui->actionExitButton,
            &QAction::triggered,
            this,
            &basic_graphics_MainWindow::exit_action_slot);

    connect(ui->actionGridButton,
            &QAction::triggered,
            this,
            &basic_graphics_MainWindow::draw_grid_action_slot);

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
            &basic_graphics_MainWindow::draw_sine__action_slot);

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

void basic_graphics_MainWindow::draw_grid_action_slot()
{
   if (draw_grid)
      draw_grid = false;
   else
      draw_grid = true;

   update();
}

void basic_graphics_MainWindow::draw_line_action_slot()
{
    if (draw_line)
       draw_line = false;
    else
       draw_line = true;

    update();
}

void basic_graphics_MainWindow::draw_circle_action_slot()
{
    if (draw_circle)
       draw_circle = false;
    else
       draw_circle = true;

    update();
}

void basic_graphics_MainWindow::draw_oval_action_slot()
{
    if (draw_oval)
       draw_oval = false;
    else
       draw_oval = true;

    update();
}

void basic_graphics_MainWindow::draw_sine__action_slot()
{
    if (draw_sine)
       draw_sine = false;
    else
       draw_sine = true;

    update();
}

void basic_graphics_MainWindow::draw_cosine_action_slot()
{
    if (draw_cosine)
       draw_cosine = false;
    else
       draw_cosine = true;

    update();
}

void basic_graphics_MainWindow::draw_tangent_action_slot()
{
    if (draw_tangent)
       draw_tangent = false;
    else
       draw_tangent = true;

    update();
}

void basic_graphics_MainWindow::draw_cotangent_action_slot()
{
    if ( draw_cotangent)
       draw_cotangent = false;
    else
       draw_cotangent = true;

    update();
}

void basic_graphics_MainWindow::draw_secant_action_slot()
{
    if ( draw_secant )
       draw_secant = false;
    else
       draw_secant = true;

    update();
}

void basic_graphics_MainWindow::draw_cosecant_action_slot()
{
    if ( draw_cosecant )
       draw_cosecant = false;
    else
       draw_cosecant = true;

    update();
}

void basic_graphics_MainWindow::paintEvent(QPaintEvent *event)
{
    if (!event)
    {
        std::cout << "ERROR - paint event is NULL\n";
        return;
    }

    QPainter painter(this);

    if (draw_grid)
    {
        painter.setPen(Qt::blue);

        x = ui->centralwidget->width() / 2;
        y = ui->centralwidget->height();

        const QLine x_axis(x, 0, x, y);

        painter.drawLine(x_axis);

        x = ui->centralwidget->width();
        y = ui->centralwidget->height() / 2;

        const QLine y_axis(0, y, x, y);

        painter.drawLine(y_axis);
    }

    if (draw_line)
    {
        painter.setPen(Qt::red);

        x = ui->centralwidget->width();
        y = ui->centralwidget->height();

        QPoint first(0, y);
        QPoint last(x, 0);

        painter.drawLine(first, last);

        update();
    }

    if (draw_circle)
    {
        // There's no 'drawCircle()'.  Use 'drawEllipse()' whose
        // rectangle is a square.
        painter.setPen(Qt::green);

        x = ui->centralwidget->width() / 2;
        y = ui->centralwidget->height() / 2;

        int width = x / 4;

        QPoint upper_left(x - width, y - width);
        QPoint lower_right(x + width, y + width);

        QRectF rectangle(upper_left, lower_right); // a square

        painter.drawEllipse(rectangle);
    }
}

/* EOF */

