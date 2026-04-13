#ifndef TEXTPALETTE_H
#define TEXTPALETTE_H

#include <QWidget>

class TextPalette : public QWidget
{
    Q_OBJECT

public:

    explicit TextPalette(QWidget *parent = nullptr);

protected:

   // Called whenever the widget needs to be repainted
   void paintEvent(QPaintEvent *event) override;

};

#endif // TEXTPALETTE_H

/* EOF */

