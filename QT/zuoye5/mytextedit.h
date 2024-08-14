#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include <QObject>
#include <QTextEdit>
#include <QEvent>
#include <QKeyEvent>
#include <QWheelEvent> //滚轮事件


//设计QTextEdit的派生类 myTextEdit
class myTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    myTextEdit(QWidget* parent = nullptr);

protected:
    virtual bool eventFilter(QObject*, QEvent* event); //事件过滤操作
signals:
     void keyPressed(QPoint pos);
private:
     void keyMove(int key);//通过案件控制按钮移动

     void wheelFont(int delta);//鼠标滚轮
};

#endif // MYTEXTEDIT_H
