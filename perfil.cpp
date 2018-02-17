#include "perfil.h"
#include "ui_perfil.h"
#include <QMessageBox>
#include <QFile>

Perfil::Perfil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Perfil)
{
    ui->setupUi(this);
}

Perfil::~Perfil()
{
    delete ui;
}

void Perfil::agregarInfo(Usuario usuAct){
    ui->nombreInputPerfil->setText(usuAct.getNombre());
    ui->usuarioInputPerfil->setText(usuAct.getUsuario());
    ui->contrasenaInputPerfil->setText(usuAct.getContrasena());
    QDate nac = QDate::fromString(usuAct.getNacimiento(), "dd/MM/yyyy");
    ui->fechaInputPerfil->setDate(nac);
    ui->correoInputPerfil->setText(usuAct.getCorreo());
}

void Perfil::guardarCambios(Usuario *usu){
    usu->setNombre(ui->nombreInputPerfil->text());
    usu->setUsuario(ui->usuarioInputPerfil->text());
    usu->setContrasena(ui->contrasenaInputPerfil->text());
    usu->setNacimiento(ui->fechaInputPerfil->text());
    usu->setCorreo(ui->correoInputPerfil->text());
}

void Perfil::on_guardarBotonPerfil_clicked()
{
    QMessageBox m;
    //usuario, nombre, fecha, contraseña, correo
    int count = 0;
    if(ui->usuarioInputPerfil->text().count()>3){
        count++;
    }else{
        m.setText("Minimo 4 caracteres para el usuario");
    }
    if(ui->nombreInputPerfil->text().count()>0){
        count++;
    }else{
        m.setText("Ingresa tu nombre");
    }
    if(ui->contrasenaInputPerfil->text().count()>3){
        count++;
    }else{
        m.setText("Minimo 4 caracteres para la contraseña");
    }
    if(ui->correoInputPerfil->text().count()>3){
        count++;
    }else{
        m.setText("Ingresa un correo valido");
    }

    if(count == 4){
        //revisar si no esta duplicado
        this->close();
        m.setText("Cambios realizados Correctamente");
        emit guardarPerfilSignal();
    }
    m.exec();
}
