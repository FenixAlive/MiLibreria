#ifndef PERFIL_H
#define PERFIL_H

#include <QDialog>
#include "usuario.h"

namespace Ui {
class Perfil;
}

class Perfil : public QDialog
{
    Q_OBJECT

public:
    explicit Perfil(QWidget *parent = 0);
    ~Perfil();

    void agregarInfo(Usuario usuAct); //funcion que recibe los datos de un usuario y los agrega a las entradas de la ventana
    void guardarCambios(Usuario *usu); //funcion que recibe una referencia de un usuario para guardar los nuevos datos del usuario en el

private slots:
    void on_guardarBotonPerfil_clicked(); //boton de guardar datos

signals:
    void guardarPerfilSignal(QString usu);//señal enviada a principal con el nuevo user para revisar si esta disponible antes de llamar la funcion guardar cambios

private:
    Ui::Perfil *ui;
};

#endif // PERFIL_H
