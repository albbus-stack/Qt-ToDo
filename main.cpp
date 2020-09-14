#include "window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    List* l= new List;
    Controller* c=new Controller(l);
    MainWindow w(l,c);
    w.show();

    return a.exec();
}
