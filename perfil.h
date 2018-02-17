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

    void agregarInfo(Usuario usuAct);
    void guardarCambios(Usuario *usu);

private slots:
    void on_guardarBotonPerfil_clicked();

signals:
    void guardarPerfilSignal();

private:
    Ui::Perfil *ui;
};

#endif // PERFIL_H
