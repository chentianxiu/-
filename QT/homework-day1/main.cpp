#include "widget.h"
#include "jisuanqi.h"
#include "dairy4.h"
#include "quest5.h"
#include "quest6.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();
//    jisuanqi j;
//    j.show();
//    dairy4 D;
//    D.show();
//    quest5 q5;
//    q5.show();
    quest6 q6;
    q6.show();

    return a.exec();
}
