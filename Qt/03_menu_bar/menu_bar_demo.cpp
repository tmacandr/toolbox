//============================================================================
// FILE: menu_bar_demo.cpp
//
// DESCRIPTION:
//    Manages the 'menu-bar' demo.
//
//    See README.md about how to define 'slots' for the buttons in the
//    menu-bar pulldowns.  Very clunky.
//============================================================================
#include <iostream>

#include <QPainter>
#include <QFont>    // maybe
#include <QPaintEvent>

#include "menu_bar_demo.h"
#include "ui_menu_bar_demo.h"


menu_bar_demo::menu_bar_demo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::menu_bar_demo)
{
    ui->setupUi(this);

    // File
    connect(ui->actionCount,
            &QAction::triggered,
            this,
            &menu_bar_demo::count_action_slot);

    connect(ui->actionExit,
            &QAction::triggered,
            this,
            &menu_bar_demo::exit_action_slot);

    // Ctrl
    connect(ui->actionZoom_in,
            &QAction::triggered,
            this,
            &menu_bar_demo::zoom_in_action_slot);

    connect(ui->actionZoom_out,
            &QAction::triggered,
            this,
            &menu_bar_demo::zoom_out_action_slot);

    connect(ui->actionMove_North,
            &QAction::triggered,
            this,
            &menu_bar_demo::move_north_action_slot);

    connect(ui->actionMove_South,
            &QAction::triggered,
            this,
            &menu_bar_demo::move_south_action_slot);

    connect(ui->actionMove_East,
            &QAction::triggered,
            this,
            &menu_bar_demo::move_east_action_slot);

    connect(ui->actionMove_West,
            &QAction::triggered,
            this,
            &menu_bar_demo::move_west_action_slot);

    // Theme
    connect(ui->actionLibRef,
            &QAction::triggered,
            this,
            &menu_bar_demo::libRef_action_slot);

    connect(ui->actionPopulation,
            &QAction::triggered,
            this,
            &menu_bar_demo::population_action_slot);

    connect(ui->actionDrainage,
            &QAction::triggered,
            this,
            &menu_bar_demo::drainage_action_slot);

    connect(ui->actionPolit_Ocean,
            &QAction::triggered,
            this,
            &menu_bar_demo::polit_ocean_action_slot);

    // Help
    connect(ui->menuHelp,
            &QMenu::triggered,
            this,
            &menu_bar_demo::help_action_slot);
}

menu_bar_demo::~menu_bar_demo()
{
    delete ui;
}

void menu_bar_demo::count_action_slot()
{
    count++;

    std::string value = std::to_string(count);

    ui->count_text_field->setText(value.c_str());

    std::cout << "Count: " << count << "\n";
}

void menu_bar_demo::exit_action_slot()
{
    std::exit(0);
}

// Ctrl
void menu_bar_demo::zoom_in_action_slot()
{
    update();
}

void menu_bar_demo::zoom_out_action_slot()
{
    std::cout << "NNN not implemented\n";
}

void menu_bar_demo::move_north_action_slot()
{
    std::cout << "Move NORTH not implemented\n";
}

void menu_bar_demo::move_south_action_slot()
{
    std::cout << "Move SOUTH not implemented\n";
}

void menu_bar_demo::move_east_action_slot()
{
    std::cout << "Move EAST not implemented\n";
}

void menu_bar_demo::move_west_action_slot()
{
    std::cout << "Move WEST not implemented\n";
}

// Themes
void menu_bar_demo::libRef_action_slot()
{
    std::cout << "LIBREF not implemented\n";
}

void menu_bar_demo::population_action_slot()
{
    std::cout << "Poplulation not implemented\n";
}

void menu_bar_demo::drainage_action_slot()
{
    std::cout << "Drainage not implemented\n";
}

void menu_bar_demo::polit_ocean_action_slot()
{
    std::cout << "Polit-Ocean not implemented\n";
}

// Help
void menu_bar_demo::help_action_slot()
{
    std::cout << "help not implemented\n";
}


void menu_bar_demo::paintEvent(QPaintEvent *event)
{
    QPainter painter(this); // QPainter automatically init for the paintEvent

    int width = ui->centralwidget->width();
    int height = ui->centralwidget->height();

    // ... set pen, font, etc
    painter.setPen(Qt::blue);

    painter.drawText(width/2, height/2, "Zoom In");
}
/* EOF */

