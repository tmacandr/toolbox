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

protected:

   void paintEvent(QPaintEvent *event);

private:
    Ui::basic_graphics_MainWindow *ui;

    int x = 0;
    int y = 0;

    QColor pen_color = Qt::black;

    bool draw_grid = false;
};
#endif // BASIC_GRAPHICS_MAINWINDOW_H

/* EOF */

