#ifndef ZUOYE3_H
#define ZUOYE3_H

#include <QWidget>
#include <QKeyEvent>
#include <QLabel>

namespace Ui {
class zuoye3;
}

class zuoye3 : public QWidget
{
    Q_OBJECT

public:
    explicit zuoye3(QWidget *parent = nullptr);
    ~zuoye3();

protected:
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    Ui::zuoye3 *ui;
    QLabel positionLabel;
};

#endif // ZUOYE3_H
