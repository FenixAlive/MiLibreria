#ifndef LIBRO_H
#define LIBRO_H

#include <QWidget>
#include "librodata.h"

namespace Ui {
class Libro;
}

class Libro : public QWidget
{
    Q_OBJECT

public:
    explicit Libro(QWidget *parent = 0);
    void setDatos(LibroData *lib); //función para agregar los datos de un libro al widget
    ~Libro();

    //reglas para boton
    void dibujarBoton(int codigo);


private slots:
    void on_boton_clicked();

signals:
    void upgradeLibro(LibroData lib);

private:
    Ui::Libro *ui;
    int status;
    LibroData tempLib;

};

#endif // LIBRO_H
