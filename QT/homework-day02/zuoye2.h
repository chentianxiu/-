#ifndef ZUOYE2_H
#define ZUOYE2_H

#include <QWidget>
#include <QKeyEvent>
#include<QLineEdit>

namespace Ui {
class zuoye2;
}

class zuoye2 : public QWidget
{
    Q_OBJECT

public:
    explicit zuoye2(QWidget *parent = nullptr);
    ~zuoye2();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    Ui::zuoye2 *ui;
};

#endif // ZUOYE2_H
