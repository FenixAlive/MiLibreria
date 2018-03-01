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


private:
    Ui::Libro *ui;

};

#endif // LIBRO_H
