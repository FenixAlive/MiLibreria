#include "principal.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Principal p;
    p.setDirbd("/home/angel/Dropbox/rob/segundo/semalgo/algoproy/buking/bdUsuarios.txt");
    p.comenzar();
    return a.exec();
}
