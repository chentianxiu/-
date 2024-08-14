#ifndef ZUOYE4_H
#define ZUOYE4_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class zuoye4;
}

class zuoye4 : public QWidget
{
    Q_OBJECT

public:
    explicit zuoye4(QWidget *parent = nullptr);
    ~zuoye4();

protected:
    virtual void mouseMoveEvent(QMouseEvent *event) override;

private:
    Ui::zuoye4 *ui;
};

#endif // ZUOYE4_H
