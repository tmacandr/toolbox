#ifndef MENU_BAR_DEMO_H
#define MENU_BAR_DEMO_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class menu_bar_demo; }
QT_END_NAMESPACE

class menu_bar_demo : public QMainWindow
{
    Q_OBJECT

public:
    menu_bar_demo(QWidget *parent = nullptr);
    ~menu_bar_demo();

public slots:

   void count_action_slot();

   void exit_action_slot();

private:
    Ui::menu_bar_demo *ui;

    unsigned int count = 0;
};
#endif // MENU_BAR_DEMO_H
