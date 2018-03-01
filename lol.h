#ifndef LIBRO_H
#define LIBRO_H

#include <QWidget>

namespace Ui {
class Libro;
}

class Libro : public QWidget
{
    Q_OBJECT

public:
    explicit Libro(QWidget *parent = 0);
    ~Libro();

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
    Ui::Libro *ui;

    QString titulo;
    QString autor;
    QString anio;
    QString Editorial;
    QString Categoria;
};

#endif // LIBRO_H
