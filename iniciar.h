#ifndef INICIAR_H
#define INICIAR_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Iniciar;
}

class Iniciar : public QDialog
{
    Q_OBJECT

public:
    explicit Iniciar(QWidget *parent = 0);
    ~Iniciar();

private slots:
    void on_iniciarBoton_clicked(); //boton de iniciar sesión

    void on_registrarmeBoton_clicked(); //boton para registrar usuario

signals:
    void iniciar(QString user, QString pass); //envia una señal a principal para revisar los datos del usuario y buscarlo
    void botonReg(); //envia una señal a principal para abrir la ventana de registrar

private:
    Ui::Iniciar *ui;
};

#endif // INICIAR_H
