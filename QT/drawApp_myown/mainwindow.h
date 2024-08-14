#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QWidgetAction>
#include "cavnas.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionCreat_New_triggered();

    void on_actionSave_as_triggered();

    void on_actionPencil_triggered();

    void on_actionLine_triggered();

    void on_actionRect_triggered();

    void on_actionEillpse_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
