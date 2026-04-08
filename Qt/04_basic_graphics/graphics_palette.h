#ifndef GRAPHICSPALETTE_H
#define GRAPHICSPALETTE_H

#include <QWidget>

class GraphicsPalette : public QWidget
{
    Q_OBJECT

public:

   explicit GraphicsPalette(QWidget *parent = nullptr);

protected:

   // Called whenever the widget needs to be repainted

   void paintEvent(QPaintEvent *event) override;

};

#endif // GRAPHICSPALETTE_H

/* EOF */

