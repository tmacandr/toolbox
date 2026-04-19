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
#include <iostream>

#include <QPainter>
#include <QPaintEvent>

#include "graphics_window.h"

GraphicsWindow::GraphicsWindow(QWidget *parent)
   : QWidget(parent)
{
   pal = palette();

   // Optional:
   //    The QWidget (window) (by default) has a 'clear' background.
   //    So anything drawn in the main 'canvas' will show through
   //    to the palette.  Thus, anything drawn in the 'canvas' AND
   //    the 'palette' will both be shown.
   //
   //    But use the following to set a 'background' color that
   //    is not 'clear'.
   //          setAutoFillBackground(true);
   //          pal.setColor(QPalette::Window, Qt::white);
   //    For now, leave it 'clear'.

   // Change the default application palette to 'pal'
   setPalette(pal);
}

void GraphicsWindow::update_grid()
{
    draw_grid = not draw_grid;

    update();
}

void GraphicsWindow::update_line()
{
    draw_line = not draw_line;

    update();
}

void GraphicsWindow::update_circle()
{
    draw_circle = not draw_circle;

    update();
}

void GraphicsWindow::update_oval()
{
    draw_oval = not draw_oval;

    update();
}

void GraphicsWindow::update_sine()
{
    draw_sine = not draw_sine;

    update();
}

void GraphicsWindow::update_cosine()
{
    draw_cosine = not draw_cosine;

    update();
}

void GraphicsWindow::update_tangent()
{
    draw_tangent = not draw_tangent;

    update();
}

void GraphicsWindow::update_cotangent()
{
    draw_cotangent = not draw_cotangent;

    update();
}

void GraphicsWindow::update_secant()
{
    draw_secant = not draw_secant;

    update();
}

void GraphicsWindow::update_cosecant()
{
    draw_cosecant = not draw_cosecant;

    update();
}
 
void GraphicsWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);

    if (draw_grid)
    {
        painter.setPen(Qt::blue);

        x = width() / 2;
        y = height();

        const QLine x_axis(x, 0, x, y);

        painter.drawLine(x_axis);

        x = width();
        y = height() / 2;

        const QLine y_axis(0, y, x, y);

        painter.drawLine(y_axis);
    }

    if (draw_line)
    {
        painter.setPen(Qt::red);

        x = width();
        y = height();

        QPoint first(0, y);
        QPoint last(x, 0);

        painter.drawLine(first, last);
    }

    if (draw_circle)
    {
        // There's no 'drawCircle()'.  Use 'drawEllipse()' whose
        // rectangle is a square.
        painter.setPen(Qt::green);

        x = width() / 2;
        y = height() / 2;

        int width = x / 4;

        QPoint upper_left(x - width, y - width);
        QPoint lower_right(x + width, y + width);

        QRectF rectangle(upper_left, lower_right); // a square

        painter.drawEllipse(rectangle);
    }

    if (draw_oval)
    {
        painter.setPen(Qt::magenta);

        x = width() / 6;
        y = height() / 6;

        QPoint upper_left(x, y);
        QPoint lower_right(x + 160, y + 290);

        QRectF rectangle(upper_left, lower_right); // a rectangle 

        painter.drawEllipse(rectangle);
    }

    if (draw_sine)
    {
        painter.setPen(Qt::red);

        x = width() / 2;
        y = height() / 2;

        painter.drawPoint(x,y);
    }

}

/* EOF */

