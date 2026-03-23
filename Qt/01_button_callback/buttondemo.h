#ifndef BUTTONDEMO_H
#define BUTTONDEMO_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ButtonDemo; }
QT_END_NAMESPACE

class ButtonDemo : public QMainWindow
{
    Q_OBJECT

public:
    ButtonDemo(QWidget *parent = nullptr);
    ~ButtonDemo();

private slots:
    void on_count_button_clicked();

    void on_reset_button_clicked();

    void on_exit_button_clicked();

private:
    Ui::ButtonDemo *ui;

    unsigned int count = 0;
};
#endif // BUTTONDEMO_H
