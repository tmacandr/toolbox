//============================================================================
// FILE: text_window.cpp
//
// DESCRIPTION:
//    Implements a base 'QWidget' that is used to show base text information
//    about what's going on during graphics operations of the application.
//    Is a 'child' window of the app's main window "centralwidget'.
//
//    A total refactor from the garbage that came out of the "insightGPT"
//    demo.
//============================================================================
#ifndef TEXT_WINDOW_H
#define TEXT_WINDOW_H

#include <QWidget>

class TextWindow : public QWidget
{
    Q_OBJECT

public:

    explicit TextWindow(QWidget *parent = nullptr);

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

    void update_canvas_dim(const int w, const int h);

protected:

   // Called whenever the widget needs to be repainted
   void paintEvent(QPaintEvent *event) override;

private:

    QPalette pal;

    int graphics_width  = 0;
    int graphics_height = 0;

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

#endif // TEXT_WINDOW_H

/* EOF */

