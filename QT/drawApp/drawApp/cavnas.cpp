#include "cavnas.h"
#include "ui_cavnas.h"

Cavnas::Cavnas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cavnas)
{
    ui->setupUi(this);
    this->show();
}

Cavnas::~Cavnas()
{
    delete ui;
}

void Cavnas::paintEvent(QPaintEvent *event) //绘图事件
{
    painter.begin(this); //开始绘图

    painter.fillRect(this->rect(),Qt::white); //填充画布颜色

    painter.drawPixmap(this->rect(),history); //填充历史记录图片

    if(paintmethod != nullptr)  //判断绘图方式是否设置
    {
        paintmethod->draw(&painter); //根据方法绘制图形
    }

    painter.end(); //结束绘图
}

void Cavnas::mousePressEvent(QMouseEvent *event) //鼠标按下
{
    newpaintMethod(currentType,event->pos(),currentPen); //生成新的绘图方法
}

void Cavnas::mouseMoveEvent(QMouseEvent *event) //鼠标移动
{
    paintmethod->addPoint(event->pos()); //记录鼠标位置
    update(); //更新画布
}

void Cavnas::mouseReleaseEvent(QMouseEvent *) //鼠标释放
{
    history = this->grab(this->rect()); //将画笔截图缓存为历史记录
}

void Cavnas::setCurrentType(const paintType &value)
{
    currentType = value;
}

void Cavnas::setCurrentPen(int width)
{
    currentPen.setWidth(width);
}

void Cavnas::setCurrentPen(QColor color)
{
    currentPen.setColor(color);
}

const QPixmap& Cavnas::getHistory() const
{
    return history;
}

void Cavnas::newpaintMethod(Cavnas::paintType type,QPoint start,QPen pen) //新建绘图方式
{
    if(paintmethod != nullptr) //删除旧绘图方式
    {
        delete paintmethod;
        paintmethod = nullptr;
    }

    //更具使用的工具类型生成绘图方式
    switch(type)
    {
    case LineType:
        paintmethod = new paintLine(pen,start);
        break;
    case RectType:
        paintmethod = new paintRect(pen,start);
        break;
    case EllipseType:
        paintmethod = new paintEllipse(pen,start);
        break;
    case PencilType:
        paintmethod = new pencilPaint(pen,start);
        break;
    default:
        break;
    }
}
