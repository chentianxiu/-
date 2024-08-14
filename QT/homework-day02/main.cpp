#include "widget.h"
#include "zuoye2.h"
#include "zuoye3.h"
#include "zuoye4.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();
    zuoye4 z;
    z.show();
    return a.exec();
}
