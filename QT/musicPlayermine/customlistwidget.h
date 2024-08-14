// CustomListWidget.h
#ifndef CUSTOMLISTWIDGET_H
#define CUSTOMLISTWIDGET_H

#include <QListWidget>
#include <QWheelEvent>

class CustomListWidget : public QListWidget
{
    Q_OBJECT

public:
    explicit CustomListWidget(QWidget *parent = nullptr);

signals:
    void wheelScrolled();

protected:
    void wheelEvent(QWheelEvent *event) override;
};

#endif // CUSTOMLISTWIDGET_H
