#include "libro.h"
#include "ui_libro.h"
#include <QMessageBox>
#include <QDebug>

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

void Libro::dibujarBoton(int codigo)
{
    switch(codigo){
        case 0:
            ui->boton->setText("Mis Libros");
            ui->boton->setStyleSheet("color:#e9e9e9; background-color:#137579;");
            break;
        case 1:
            ui->boton->setText("Favoritos");
            ui->boton->setStyleSheet("color:#313131; background-color:#f7f713;");
            break;
        case 2:
            ui->boton->hide();
            break;
    }
}

//pone los datos que se le pasan de un libro en el widget
void Libro::setDatos(LibroData *lib)
{
    ui->titulo->setText(lib->getTitulo());
    ui->autor->setText(lib->getAutor());
    ui->anio->setText(lib->getAnio());
    ui->editorial->setText(lib->getEditorial());
    ui->categoria->setText(lib->getCategoria());
    //darle valor a boton
    status = lib->getBoton();
    tempLib= *lib;
    dibujarBoton(status);
}

void Libro::on_boton_clicked()
{
    status++;
    tempLib.setBoton(status);
    dibujarBoton(status);
    emit upgradeLibro(tempLib);
}
