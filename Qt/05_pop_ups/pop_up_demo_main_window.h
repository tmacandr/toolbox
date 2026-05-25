#ifndef POP_UP_DEMO_MAIN_WINDOW_H
#define POP_UP_DEMO_MAIN_WINDOW_H

#include <QMainWindow>

#include "dialog_1.h"
#include "dialog_2.h"
#include "dialog_3.h"

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
    void on_dialog_3_button_clicked();

    void dialog_1_action_slot();

    void exit_action_slot();

    void dialog_2_action_slot();

private:
    Ui::pop_up_demo_Main_Window *ui;

    Dialog_1_Window *dialog_1 = nullptr;

    Dialog_2_Window *dialog_2 = nullptr;

    Dialog_3_Window *dialog_3 = nullptr;
};
#endif // POP_UP_DEMO_MAIN_WINDOW_H
