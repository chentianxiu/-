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
    void keyMove(int key);
    void wheelFont(int delta);
};

#endif // MYTEXTEDIT_H
