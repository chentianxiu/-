#ifndef CHILDWINDOW_H
#define CHILDWINDOW_H

#include <QMainWindow>

namespace Ui {
class childWindow;
}

class childWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit childWindow(QWidget *parent = nullptr);
    ~childWindow();

signals:
    void logout();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::childWindow *ui;
};

#endif // CHILDWINDOW_H
