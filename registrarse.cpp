#include "registrarse.h"
#include "ui_registrarse.h"
#include "iniciar.h"
#include "principal.h" // quitar cabeceras que no necesito
#include <QMessageBox>

Registrarse::Registrarse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registrarse)
{
    ui->setupUi(this);
}

Registrarse::~Registrarse()
{
    delete ui;
}

void Registrarse::on_iniciarBotonNuevo_clicked()
{
    this->close();
    emit regToIni();
}

void Registrarse::on_registrarmeBotonNuevo_clicked()
{
    QMessageBox m;
    //usuario, nombre, fecha, contraseña, correo
    int count = 0;
    if(ui->usuarioInputNuevo->text().count()>3){
        count++;
    }else{
        m.setText("Minimo 4 caracteres para el usuario");
    }
    if(ui->nombreInputNuevo->text().count()>0){
        count++;
    }else{
        m.setText("Ingresa tu nombre");
    }
    if(ui->contrasenaInputNuevo->text().count()>3){
        count++;
    }else{
        m.setText("Minimo 4 caracteres para la contraseña");
    }
    if(ui->correoInputNuevo->text().count()>3){
        count++;
    }else{
        m.setText("Ingresa un correo valido");
    }
    if(count == 4){
        emit regUsu(ui->nombreInputNuevo->text(),
                       ui->usuarioInputNuevo->text(),
                       ui->contrasenaInputNuevo->text(),
                       ui->fechaInputNuevo->text(),
                       ui->correoInputNuevo->text());
    }else{
        m.exec();
    }
}