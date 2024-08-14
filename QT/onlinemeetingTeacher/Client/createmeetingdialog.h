#ifndef CREATEMEETINGDIALOG_H
#define CREATEMEETINGDIALOG_H

#include <QDialog>

namespace Ui {
class createMeetingDialog;
}

class createMeetingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit createMeetingDialog(QWidget *parent = nullptr);
    ~createMeetingDialog();
    void setSelectList(QStringList list);
    void prepareMeetingName(QString name);
    QString getMeetingName();
    QStringList getmemberList();

private slots:
    void on_addMember_PB_clicked();

    void on_removeMember_PB_clicked();

private:
    Ui::createMeetingDialog *ui;
};

#endif // CREATEMEETINGDIALOG_H
