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

private:
    Ui::data_entry *ui;
};
#endif // DATA_ENTRY_H
