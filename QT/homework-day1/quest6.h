#ifndef QUEST6_H
#define QUEST6_H

#include <QWidget>

namespace Ui {
class quest6;
}

class quest6 : public QWidget
{
    Q_OBJECT

public:
    explicit quest6(QWidget *parent = nullptr);
    ~quest6();

private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_verticalSlider_valueChanged(int value);

private:
    Ui::quest6 *ui;
};

#endif // QUEST6_H
