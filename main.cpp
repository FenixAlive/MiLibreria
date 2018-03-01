#include "principal.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //se crea objeto principal que maneja toda la aplicación
    Principal p;

    //se ponen las direcciones de las bases de datos
    p.setDirbd("/home/angel/Dropbox/rob/segundo/semalgo/algoproy/buking/bdUsuarios.txt");
    p.setDirbdLibros("/home/angel/Dropbox/rob/segundo/semalgo/algoproy/buking/bdLibros/");

    //se comienza la aplicación
    p.comenzar();

    return a.exec();
}
