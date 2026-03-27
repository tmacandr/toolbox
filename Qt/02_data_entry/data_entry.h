#ifndef DATA_ENTRY_H
#define DATA_ENTRY_H

#include <QMainWindow>
#include "ui_data_entry.h"

QT_BEGIN_NAMESPACE
namespace Ui { class data_entry; }
QT_END_NAMESPACE

class data_entry : public QMainWindow
{
    Q_OBJECT

public:
    data_entry(QWidget *parent = nullptr);
    ~data_entry();

private slots:
    void on_exit_button_clicked();

    void on_cancel_button_clicked();

    void on_save_button_clicked();

private:
    Ui::data_entry *ui;
};
#endif // DATA_ENTRY_H
