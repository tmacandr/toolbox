//============================================================================
// FILE: pop_up_demo_main_window.h
//
// DESCRIPTION:
//    Manages the 'pop up' demo.
//============================================================================
#ifndef POP_UP_DEMO_MAIN_WINDOW_H
#define POP_UP_DEMO_MAIN_WINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class pop_up_demo_Main_Window;
}
QT_END_NAMESPACE

class pop_up_demo_Main_Window : public QMainWindow
{
    Q_OBJECT

public:
    pop_up_demo_Main_Window(QWidget *parent = nullptr);

    ~pop_up_demo_Main_Window();

private slots:

    void pop_up_1_action_slot();

    void exit_action_slot();

    void pop_up_2_action_slot();

    void on_pop_up_3_pushButton_clicked();

private:
    Ui::pop_up_demo_Main_Window *ui;
};
#endif // POP_UP_DEMO_MAIN_WINDOW_H

/* EOF */

