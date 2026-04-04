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
    //    Apparently, there's no way to create connect a 'slot'
    //    function to a 'menubar' button using the 'Qt Creator'
    //    But it can be done 'programmatically' ... shown below.
    //
    //    So, the following did NOT work:
    //       Created a "Help" menubar button with no pulldown buttons.
    //       Tried to use the following to create a handler:
    //
    //          connect(ui->menuHelpButton,
    //                  &QMenu::triggered,
    //                  this,
    //                  &menu_bar_demo::help_action_slot);
    //
    //       But when selecting the "Help" button (only), nothing
    //       happened.
    //
    //    The following worked:
    //
    //       QAction *helpAction = ui->demo_menubar->addAction("What?");
    //
    //       connect(helpAction,
    //               &QAction::triggered,
    //               this,
    //               &menu_bar_demo::help_action_slot);
    //
    //    But I opted for the following: 

    ui->demo_menubar->addAction
            ("Not Help",
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
    x = ui->centralwidget->width() / 2;
    y = ui->centralwidget->height() / 2;

    message = "Zoom in";

    std::cout << message << "\n";

    pen_color = Qt::blue;

    update();
}

void menu_bar_demo::zoom_out_action_slot()
{
    x = ui->centralwidget->width() / 4;
    y = ui->centralwidget->height() / 4;

    message = "Zoom out";

    std::cout << message << "\n";

    pen_color = Qt::darkCyan;

    update();
}

void menu_bar_demo::move_north_action_slot()
{
    x = ui->centralwidget->width() / 3;
    y = ui->centralwidget->height() / 3;

    message = "Move North";

    pen_color = Qt::darkBlue;

    std::cout << message << "\n";

    update();
}

void menu_bar_demo::move_south_action_slot()
{
    x = ui->centralwidget->width() / 6;
    y = ui->centralwidget->height() / 6;

    message = "Move South";

    pen_color = Qt::darkYellow;

    std::cout << message << "\n";

    update();
}

void menu_bar_demo::move_east_action_slot()
{
    x = ui->centralwidget->width() / 9;
    y = ui->centralwidget->height() / 9;

    message = "Move East";

    std::cout << message << "\n";

    update();
}

void menu_bar_demo::move_west_action_slot()
{
    x = ui->centralwidget->width() / 5;
    y = ui->centralwidget->height() / 5;

    message = "Move West";

    pen_color = Qt::cyan;

    std::cout << message << "\n";

    update();
}

// Themes
void menu_bar_demo::libRef_action_slot()
{
    x = (int) (0.65 * ui->centralwidget->width());
    y = ui->centralwidget->height() / 5;

    message = "LibRef";

    pen_color = Qt::darkMagenta;

    std::cout << message << "\n";

    update();
}

void menu_bar_demo::population_action_slot()
{
    x = (int) (0.70 * ui->centralwidget->width());
    y = ui->centralwidget->height() / 2;

    message = "Population";

    pen_color = Qt::yellow;

    std::cout << message << "\n";

    update();
}

void menu_bar_demo::drainage_action_slot()
{
    x = (int) (0.75 * ui->centralwidget->width());
    y = (int) (0.75 * ui->centralwidget->height());

    pen_color = Qt::magenta;

    message = "Drainage";

    std::cout << message << "\n";

    update();
}

void menu_bar_demo::polit_ocean_action_slot()
{
    x = (int) (0.6 * ui->centralwidget->width());
    y = (int) (0.6 * ui->centralwidget->height());

    pen_color = Qt::red;

    message = "Polit Ocean";

    std::cout << message << "\n";

    update();
}

// Help
void menu_bar_demo::help_action_slot()
{
    x = (int) (0.8 * ui->centralwidget->width());
    y = (int) (0.8 * ui->centralwidget->height());

    message = "Help";

    std::cout << message << "\n";

    update();
}


void menu_bar_demo::paintEvent(QPaintEvent *event)
{
    QPainter painter(this); // QPainter automatically init for the paintEvent

    QRegion region = event->region();

    if ( region.isEmpty() )
    {
        painter.setPen(Qt::green);
    }
    else
    {
        painter.setPen(pen_color);
    }

    painter.drawText(x, y, message.c_str());
}

/* EOF */

