#include "libro.h"
#include "ui_libro.h"

Libro::Libro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Libro)
{
    ui->setupUi(this);
}

Libro::~Libro()
{
    delete ui;
}

//pone los datos que se le pasan de un libro en el widget
void Libro::setDatos(LibroData *lib)
{
    ui->titulo->setText(lib->getTitulo());
    ui->autor->setText(lib->getAutor());
    ui->anio->setText(lib->getAnio());
    ui->editorial->setText(lib->getEditorial());
    ui->categoria->setText(lib->getCategoria());
}
