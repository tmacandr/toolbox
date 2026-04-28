#ifndef POP_UP_DEMO_MAIN_WINDOW_H
#define POP_UP_DEMO_MAIN_WINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class pop_up_demo_Main_Window; }
QT_END_NAMESPACE

class pop_up_demo_Main_Window : public QMainWindow
{
    Q_OBJECT

public:
    pop_up_demo_Main_Window(QWidget *parent = nullptr);
    ~pop_up_demo_Main_Window();

private slots:
    void on_pushButton_clicked();

private:
    Ui::pop_up_demo_Main_Window *ui;
};
#endif // POP_UP_DEMO_MAIN_WINDOW_H
