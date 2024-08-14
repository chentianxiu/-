#ifndef JISUANQI_H
#define JISUANQI_H

#include <QWidget>

namespace Ui {
class jisuanqi;
}

class jisuanqi : public QWidget
{
    Q_OBJECT

public:
    explicit jisuanqi(QWidget *parent = nullptr);
    ~jisuanqi();

private:
    Ui::jisuanqi *ui;
};

#endif // JISUANQI_H
