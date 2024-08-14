#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QLabel>
#include <QPropertyAnimation>
#include <QList>
#include <QPair>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void keyPressEvent(QKeyEvent *event) override;

private slots:
    void ActionFinished();


private:
    Ui::Widget *ui;
    QPoint TargetPos; //目的地位置
    QList<QPair<QLabel*,QPoint>> ways; //路径
    QPropertyAnimation * pa;
    bool isMove = false ;

    void startAnimation();

};
#endif // WIDGET_H
