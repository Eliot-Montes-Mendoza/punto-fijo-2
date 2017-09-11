#include "punto.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    punto w;
    w.show();

    return a.exec();
}
