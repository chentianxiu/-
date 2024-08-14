#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QApplication>
#include<QTextBrowser>
#include <QMouseEvent>

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
    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
