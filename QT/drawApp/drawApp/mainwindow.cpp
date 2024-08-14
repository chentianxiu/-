#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    centralLayout = new QVBoxLayout(this); //centralWidget 布局对象
    centralLayout->setContentsMargins(50,20,50,20); //设置边距 左右50 上下边距20
    ui->centralwidget->setLayout(centralLayout); //给centralWidget设置布局对象

    penWidth = new QSpinBox(this);  //画笔宽度的数值调整器
    //将调整器放入选择画笔粗细的菜单中
    QWidgetAction* widgetAction = new QWidgetAction(this);
    widgetAction->setDefaultWidget(penWidth);
    ui->widthMenu->addAction(widgetAction);

    //连接数值变化时的处理槽函数
    connect(penWidth,static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),this,&MainWindow::on_penWidthChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionCreate_New_triggered() //新建画布
{
    if(cavnas != nullptr)  //判断旧画布是否存在
    {
        centralLayout->removeWidget(cavnas); //从布局中移除
        delete cavnas;  //释放空间
        cavnas = nullptr;
    }

    cavnas = new Cavnas(ui->centralwidget); //生成新的画布实例
    centralLayout->addWidget(cavnas);  //添加到布局中
}

void MainWindow::on_actionSave_as_triggered() //保存
{
    if(cavnas == nullptr) //没有画布对象
    {
        return; //结束
    }

    //通过文件对话框 选择保存路径
    QString path = QFileDialog::getSaveFileName(this,"保存图片","./","图片文件(.jpg,.png)");
    //判断路径中是否有图片的文件后缀
    QString format = path.split(".").last();

    if(format!="jpg" && format!="png") //没有
    {
        path += ".jpg"; //增加后缀
    }
    QImage image = cavnas->getHistory().toImage(); //获取画布的历史图片记录
    image.save(path); //保存
}


//设置绘图工具
void MainWindow::on_actionPencil_triggered() //铅笔
{
    cavnas->setCurrentType(Cavnas::PencilType);
}

void MainWindow::on_actionLine_triggered() //直线
{
    cavnas->setCurrentType(Cavnas::LineType);
}

void MainWindow::on_actionRect_triggered() //矩形
{
    cavnas->setCurrentType(Cavnas::RectType);
}

void MainWindow::on_actionEillpse_triggered() //椭圆形
{
    cavnas->setCurrentType(Cavnas::EllipseType);
}


//画笔粗细设置
void MainWindow::on_action1_xp_triggered() //1xp
{
    cavnas->setCurrentPen(1);
    penWidth->setValue(1);
}

void MainWindow::on_action5_xp_triggered() //5xp
{
    cavnas->setCurrentPen(5);
    penWidth->setValue(5);
}

void MainWindow::on_action10_xp_triggered() //10xp
{
    cavnas->setCurrentPen(10);
    penWidth->setValue(10);
}

void MainWindow::on_action20_xp_triggered() //20xp
{
    cavnas->setCurrentPen(20);
    penWidth->setValue(20);
}

void MainWindow::on_penWidthChanged(int i) //获取spinbox中的数值
{
    cavnas->setCurrentPen(i); //设置画笔宽度
}

void MainWindow::on_actionSet_Color_triggered() //设置颜色
{
    //通过颜色对话框获取颜色
    QColor color = QColorDialog::getColor(Qt::white,this,"选择画笔颜色");
    //设置颜色
    cavnas->setCurrentPen(color);
}
