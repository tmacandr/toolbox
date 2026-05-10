//============================================================================
// FILE: dialog_1_window.h
//
// DESCRIPTION:
//    Manages 'dialog 1' of the 'pop up' demo.
//============================================================================
#ifndef DIALOG_1_WINDOW_H
#define DIALOG_1_WINDOW_H

#include <QMainWindow>
#include <ui_dialog_1.h>

class Dialog_1_Window : public QMainWindow
{
    Q_OBJECT

public:
    Dialog_1_Window(QWidget *parent = nullptr);

    ~Dialog_1_Window();

private slots:

    void exit_action_slot();

private:
    Ui_Dialog_1_Window *ui;
};
#endif // DIALOG_1_WINDOW_H

/* EOF */

