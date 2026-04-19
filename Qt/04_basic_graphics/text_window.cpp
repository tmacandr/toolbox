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
#include <iostream>
#include <string>

#include <QPainter>
#include <QPaintEvent>

#include "text_window.h"

TextWindow::TextWindow(QWidget *parent)
    : QWidget(parent)
{
    QPalette pal = palette();

    setPalette(pal);
}

void TextWindow::update_grid()
{
    draw_grid = not draw_grid;

    update();
}

void TextWindow::update_line()
{
    draw_line = not draw_line;

    update();
}

void TextWindow::update_circle()
{
    draw_circle = not draw_circle;

    update();
}

void TextWindow::update_oval()
{
    draw_oval = not draw_oval;

    update();
}

void TextWindow::update_sine()
{   
    draw_sine = not draw_sine;

    update();
}

void TextWindow::update_cosine()
{   
    draw_cosine = not draw_cosine;

    update();
}

void TextWindow::update_tangent()
{
    draw_tangent = not draw_tangent;

    update();
}

void TextWindow::update_cotangent()
{
    draw_cotangent = not draw_cotangent;

    update();
}

void TextWindow::update_secant()
{
    draw_secant = not draw_secant;

    update();
}

void TextWindow::update_cosecant()
{
    draw_cosecant = not draw_cosecant;

    update();
}

void TextWindow::update_canvas_dim(const int w, const int h)
{
    graphics_width  = w;
    graphics_height = h;
}

void TextWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);

    if (draw_grid)
    {
        painter.drawText(5, 20, "GRID: ON");
    }
    else
    {
        painter.drawText(5, 20, "GRID: OFF");
    }

    if (draw_line)
    {
        painter.drawText(5, 50, "LINE: ON");
    }
    else
    {
        painter.drawText(5, 50, "LINE: OFF");
    }

    if (draw_circle)
    {
        painter.drawText(5, 80, "CIRCLE: ON");
    }
    else
    {
        painter.drawText(5, 80, "CIRCLE: OFF");
    }

    if (draw_oval)
    {
        painter.drawText(5, 110, "OVAL: ON");
    }
    else
    {
        painter.drawText(5, 110, "OVAL: OFF");
    }

    if (draw_sine)
    {
        painter.drawText(5, 140, "SINE: ON");
    }
    else
    {
        painter.drawText(5, 140, "SINE: OFF");
    }

    if (draw_cosine)
    {
        painter.drawText(5, 170, "COSINE: ON");
    }
    else
    {
        painter.drawText(5, 170, "COSINE: OFF");
    }

    if (draw_tangent)
    {
        painter.drawText(5, 200, "TANGENT: ON");
    }
    else
    {
        painter.drawText(5, 200, "TANGENT: OFF");
    }

    if (draw_cotangent)
    {
        painter.drawText(5, 230, "COTANGENT: ON");
    }
    else
    {
        painter.drawText(5, 230, "COTANGENT: OFF");
    }

    if (draw_secant)
    {
        painter.drawText(5, 260, "SECANT: ON");
    }
    else
    {
        painter.drawText(5, 260, "SECANT: OFF");
    }

    if (draw_cosecant)
    {
        painter.drawText(5, 290, "COSECANT: ON");
    }
    else
    {
        painter.drawText(5, 290, "COSECANT: OFF");
    }

    std::string dim = "Graph Size: (" + std::to_string(graphics_width) +
                      ", " + std::to_string(graphics_height) + ")";

    painter.drawText(10, 330, dim.c_str());

    dim = "Text Size: (" + std::to_string(width()) +
          ", " + std::to_string(height()) + ")";

    painter.drawText(10, 370, dim.c_str());

}

/* EOF */

