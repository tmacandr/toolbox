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
#include <cmath>
#include <vector>

#include <QPainter>
#include <QPaintEvent>
#include <QPointF>
#include <QPolygonF>

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

        QPointF     nxt_point;
        const int   half_w = width() / 2;
        const float half_h = (float) height() / 2.0;
        float       xf;
        float       yf;

        QPolygonF polygon;

        for (float rad = -TWO_PI; rad < TWO_PI; rad = rad + 0.030)
        {
            yf = std::sin(rad);

            //std::cout << "("  << rad << ", " << yf << ")\n";

            xf = (rad / TWO_PI) * (float) half_w;
            x = (int) xf + half_w;

            yf = 1.0 - yf;
            y = (int) (yf * half_h); 

            nxt_point.setX((float) x);
            nxt_point.setY((float) y);

            polygon.push_back(nxt_point);   
        }

        painter.drawPolyline(polygon);
    }

    if (draw_cosine)
    {
        painter.setPen(Qt::darkCyan);

        QPointF     nxt_point;
        const int   half_w = width() / 2;
        const float half_h = (float) height() / 2.0;
        float       xf;
        float       yf;

        QPolygonF polygon;

        for (float rad = -TWO_PI; rad < TWO_PI; rad = rad + 0.030)
        {
            yf = std::cos(rad);

            //std::cout << "("  << rad << ", " << yf << ")\n";

            xf = (rad / TWO_PI) * (float) half_w;
            x = (int) xf + half_w;

            yf = 1.0 - yf;
            y = (int) (yf * half_h);

            nxt_point.setX((float) x);
            nxt_point.setY((float) y);
            
            polygon.push_back(nxt_point);
        }
        
        painter.drawPolyline(polygon);
    }

    if (draw_tangent)
    {
        typedef struct
        {
            float from;
            float to;
        } INTERVAL_T;

        const unsigned int NUM_INTERVALS = 5;

        const INTERVAL_T interval[NUM_INTERVALS] =
                  {
                       { -TWO_PI,          -THREE_PI_over_2 },
                       { -THREE_PI_over_2, -PI_over_2       },
                       { -PI_over_2,       PI_over_2        },
                       { PI_over_2,        THREE_PI_over_2  },
                       { THREE_PI_over_2,  TWO_PI           }
                  };

        painter.setPen(Qt::black);

        QPointF     nxt_point;
        const int   half_w = width() / 2;
        const float half_h = (float) height() / 2.0;
        float       xf;
        float       yf;

        QPolygonF polygon;

        for (unsigned int i = 0; i < NUM_INTERVALS; i++)
        {
            for (float rad = interval[i].from;
                       rad < interval[i].to;
                       rad = rad + 0.030)
            {
                yf = std::tan(rad);

                if ( (yf > 1.0) or (yf < -1.0) ) continue;

                //std::cout << "("  << rad << ", " << yf << ")\n";

                xf = (rad / TWO_PI) * (float) half_w;

                x = (int) xf + half_w;

                yf = 1.0 - yf;

                y = (int) (yf * half_h);

                nxt_point.setX((float) x);
                nxt_point.setY((float) y);

                polygon.push_back(nxt_point);
            }

            painter.drawPolyline(polygon);

            polygon.clear();
        }
    }

    if (draw_cotangent)
    {
        typedef struct
        {
            float from;
            float to;
        } INTERVAL_T;

        const unsigned int NUM_INTERVALS = 4;

        const INTERVAL_T interval[NUM_INTERVALS] =
                  {
                       { -TWO_PI, -PI },
                       { -PI,     0.0f},
                       { 0.0f,    PI},
                       { PI,      TWO_PI}
                  };

        painter.setPen(Qt::darkCyan);

        QPointF     nxt_point;
        const int   half_w = width() / 2;
        const float half_h = (float) height() / 2.0;
        float       xf;
        float       yf;

        QPolygonF polygon;

        for (unsigned int i = 0; i < NUM_INTERVALS; i++)
        {
            for (float rad = interval[i].from;
                       rad < interval[i].to;
                       rad = rad + 0.030)
            {
                yf = 1.0 / std::tan(rad);

                if ( (yf > 1.0) or (yf < -1.0) ) continue;

                //std::cout << "("  << rad << ", " << yf << ")\n";

                xf = (rad / TWO_PI) * (float) half_w;

                x = (int) xf + half_w;

                yf = 1.0 - yf;

                y = (int) (yf * half_h);

                nxt_point.setX((float) x);
                nxt_point.setY((float) y);

                polygon.push_back(nxt_point);
            }

            painter.drawPolyline(polygon);

            polygon.clear();
        }
    }
}

/* EOF */

