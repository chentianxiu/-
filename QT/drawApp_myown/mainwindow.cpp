#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionCreat_New_triggered()
{

}

void MainWindow::on_actionSave_as_triggered()
{

}

void MainWindow::on_actionPencil_triggered()
{

}

void MainWindow::on_actionLine_triggered()
{

}

void MainWindow::on_actionRect_triggered()
{

}

void MainWindow::on_actionEillpse_triggered()
{

}
