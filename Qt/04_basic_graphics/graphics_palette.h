#ifndef GRAPHICSPALETTE_H
#define GRAPHICSPALETTE_H

#include <QWidget>

class GraphicsPalette : public QWidget
{
    Q_OBJECT

public:

   explicit GraphicsPalette(QWidget *parent = nullptr);

   void update_grid();

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

};

#endif // GRAPHICSPALETTE_H

/* EOF */

