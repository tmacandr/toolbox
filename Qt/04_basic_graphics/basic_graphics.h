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

private:
    Ui::basic_graphics_MainWindow *ui;
};
#endif // BASIC_GRAPHICS_MAINWINDOW_H
