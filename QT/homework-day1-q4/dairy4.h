#ifndef DAIRY4_H
#define DAIRY4_H

#include <QWidget>

namespace Ui {
class dairy4;
}

class dairy4 : public QWidget
{
    Q_OBJECT

public:
    explicit dairy4(QWidget *parent = nullptr);
    ~dairy4();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::dairy4 *ui;
};

#endif // DAIRY4_H
