#include "widget.h"
#include "jisuanqi.h"
#include "dairy4.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();
//    jisuanqi j;
//    j.show();
    dairy4 D;
    D.show();
    return a.exec();
}
