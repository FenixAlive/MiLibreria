#ifndef REGISTRARSE_H
#define REGISTRARSE_H

#include <QDialog>

namespace Ui {
class Registrarse;
}

class Registrarse : public QDialog
{
    Q_OBJECT

public:
    explicit Registrarse(QWidget *parent = 0);
    ~Registrarse();

private slots:
    void on_iniciarBotonNuevo_clicked();//boton regresar a iniciar

    void on_registrarmeBotonNuevo_clicked();//boton guardar registro

signals:
    void regUsu(QString nom, QString user, QString pass, QString nac, QString mail);//señal registrar usuario, se manda a principal
    void regToIni();//señal que se manda a principal para abrir ventana de iniciar sesion

private:
    Ui::Registrarse *ui;
};

#endif // REGISTRARSE_H
