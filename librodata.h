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

    int getIndex() const;
    void setIndex(int value);

    int getBoton() const;
    void setBoton(int value);

private: //variables que guardará un libro
    QString titulo;
    QString autor;
    QString anio;
    QString editorial;
    QString categoria;
    int index;
    int boton;

};

#endif // LIBRODATA_H
