#ifndef LIBRODATA_H
#define LIBRODATA_H
#include <QString>


class LibroData
{

public:
    LibroData();

    QString getTitulo() const;
    void setTitulo(const QString &value);

    QString getAutor() const;
    void setAutor(const QString &value);

    QString getAnio() const;
    void setAnio(const QString &value);

    QString getEditorial() const;
    void setEditorial(const QString &value);

    QString getCategoria() const;
    void setCategoria(const QString &value);

private:
    QString titulo;
    QString autor;
    QString anio;
    QString editorial;
    QString categoria;

};

#endif // LIBRODATA_H
