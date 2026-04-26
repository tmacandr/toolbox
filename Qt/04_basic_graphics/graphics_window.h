//============================================================================
// FILE: graphics_window.cpp
//
// DESCRIPTION:
//    Implements a base 'QWidget' that is used to demonstrate basic
//    graphics operations in Qt.  Is a 'child' window of the app's
//    main window "centralwidget'.
//
//    A total refactor from the garbage that came out of the "insightGPT"
//    demo.
//============================================================================
#ifndef GRAPHICS_WINDOW_H
#define GRAPHICS_WINDOW_H

#include <QWidget>

class GraphicsWindow : public QWidget
{
    Q_OBJECT

public:

   explicit GraphicsWindow(QWidget *parent = nullptr);

   void update_grid();

   void update_line();

   void update_circle();

   void update_oval();

   void update_sine();

   void update_cosine();

   void update_tangent();

   void update_cotangent();

   void update_secant();

   void update_cosecant();

protected:

   // Called whenever the widget needs to be repainted

   void paintEvent(QPaintEvent *event) override;

private:

    QPalette pal;

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

    // C++20 has std::numbers::pi
    const float PI              = 3.14159;
    const float TWO_PI          = 2.0 * PI;
    const float PI_over_2       = PI / 2.0;
    const float THREE_PI_over_2 = 3.0f * PI_over_2;
};

#endif // GRAPHICS_WINDOW_H

/* EOF */

