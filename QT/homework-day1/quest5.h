#ifndef QUEST5_H
#define QUEST5_H

#include <QWidget>

namespace Ui {
class quest5;
}

class quest5 : public QWidget
{
    Q_OBJECT

public:
    explicit quest5(QWidget *parent = nullptr);
    ~quest5();

private slots:
    void on_pushButton_clicked();

private:
    Ui::quest5 *ui;
};

#endif // QUEST5_H
