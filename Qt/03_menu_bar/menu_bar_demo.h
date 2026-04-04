//============================================================================
// FILE: menu_bar_demo.h
//
// DESCRIPTION:
//    Class declaration of 'menu_bar_demo'.
//
//    See README.md about how to define 'slots' for the buttons in the
//    menu-bar pulldowns.  Very clunky.
//============================================================================
#ifndef MENU_BAR_DEMO_H
#define MENU_BAR_DEMO_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class menu_bar_demo; }
QT_END_NAMESPACE

class menu_bar_demo : public QMainWindow
{
    // Macro that declares its own signals and slots
    Q_OBJECT

public:
    menu_bar_demo(QWidget *parent = nullptr);
    ~menu_bar_demo();

public slots:

   // File
   void count_action_slot();

   void exit_action_slot();

   // Ctrl
   void zoom_in_action_slot();

   void zoom_out_action_slot();

   void move_north_action_slot();

   void move_south_action_slot();

   void move_east_action_slot();

   void move_west_action_slot();

   // Themes
   void libRef_action_slot();

   void population_action_slot();

   void drainage_action_slot();

   void polit_ocean_action_slot();

   // Help
   void help_action_slot();

protected:

   void paintEvent(QPaintEvent *event); 

private:
    Ui::menu_bar_demo *ui;

    unsigned int count = 0;

    int x = 0;
    int y = 0;

    std::string message;

    QColor pen_color = Qt::black;
};
#endif // MENU_BAR_DEMO_H

/* EOF */

