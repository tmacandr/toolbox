#ifndef BASIC_GRAPHICS_MAINWINDOW_H
#define BASIC_GRAPHICS_MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class basic_graphics_MainWindow; }
QT_END_NAMESPACE

class basic_graphics_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    basic_graphics_MainWindow(QWidget *parent = nullptr);
    ~basic_graphics_MainWindow();

public slots:

   void exit_action_slot();

   void draw_grid_action_slot();

   void draw_line_action_slot();

   void draw_circle_action_slot();

   void draw_oval_action_slot();

   void draw_sine__action_slot();

   void draw_cosine_action_slot();

   void draw_tangent_action_slot();

   void draw_cotangent_action_slot();

   void draw_secant_action_slot();

   void draw_cosecant_action_slot();

protected:

   void paintEvent(QPaintEvent *event);

private:
    Ui::basic_graphics_MainWindow *ui;

    int x = 0;
    int y = 0;

    bool draw_grid      = false;
    bool draw_line      = false;
    bool draw_circle    = false;
    bool draw_oval      = false;
    bool draw_sine      = false;
    bool draw_cosine    = false;
    bool draw_tangent   = false;
    bool draw_cotangent = false;
    bool draw_secant    = false;
    bool draw_cosecant  = false;

};
#endif // BASIC_GRAPHICS_MAINWINDOW_H

/* EOF */

