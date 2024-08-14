#ifndef ADDFRIEDNDIALOG_H
#define ADDFRIEDNDIALOG_H

#include <QDialog>

namespace Ui {
class addFriednDialog;
}

class addFriednDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addFriednDialog(QWidget *parent = nullptr);
    ~addFriednDialog();
    void setSelectList(QStringList text);

signals:
    void addfriends(QStringList friends);

private slots:
    void on_moveRight_PB_clicked();

    void on_moveLeft_PB_clicked();

    void on_addName_PB_clicked();

    void on_buttonBox_accepted();

private:
    Ui::addFriednDialog *ui;
};

#endif // ADDFRIEDNDIALOG_H
