#include "librodata.h"
#include <QString>

LibroData::LibroData()
{

}

QString LibroData::getTitulo() const
{
    return titulo;
}

void LibroData::setTitulo(const QString &value)
{
    titulo = value;
}

QString LibroData::getAutor() const
{
    return autor;
}

void LibroData::setAutor(const QString &value)
{
    autor = value;
}

QString LibroData::getAnio() const
{
    return anio;
}

void LibroData::setAnio(const QString &value)
{
    anio = value;
}

QString LibroData::getEditorial() const
{
    return editorial;
}

void LibroData::setEditorial(const QString &value)
{
    editorial = value;
}

QString LibroData::getCategoria() const
{
    return categoria;
}

void LibroData::setCategoria(const QString &value)
{
    categoria = value;
}
