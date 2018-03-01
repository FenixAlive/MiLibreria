#include "perfil.h"
#include "ui_perfil.h"
#include <QMessageBox>

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

//función que agrega la información pasada en el usuario a los input del perfil

void Perfil::agregarInfo(Usuario usuAct){
    ui->nombreInputPerfil->setText(usuAct.getNombre());
    ui->usuarioInputPerfil->setText(usuAct.getUsuario());
    ui->contrasenaInputPerfil->setText(usuAct.getContrasena());
    //para poner la fecha se debe convertir el QString en Qdate
    QDate nac = QDate::fromString(usuAct.getNacimiento(), "dd/MM/yyyy");
    ui->fechaInputPerfil->setDate(nac);
    ui->correoInputPerfil->setText(usuAct.getCorreo());
}

//función que toma la dirección de memoria de un usuario y guarda los datos de los input en el

void Perfil::guardarCambios(Usuario *usu){
    usu->setNombre(ui->nombreInputPerfil->text());
    usu->setUsuario(ui->usuarioInputPerfil->text());
    usu->setContrasena(ui->contrasenaInputPerfil->text());
    usu->setNacimiento(ui->fechaInputPerfil->text());
    usu->setCorreo(ui->correoInputPerfil->text());
}

//al dar clic en el boton guardar revisa que los datos esten llenos correctamente y si es asi emite la señal con el usuario como parametro para revisar que no esta repetido en principal

void Perfil::on_guardarBotonPerfil_clicked()
{
    QMessageBox m;
    m.setStyleSheet("background-color:#333; color:white;");
    m.setWindowTitle("Advertencia");
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
        emit guardarPerfilSignal(ui->usuarioInputPerfil->text());
    }else{
        m.exec();
    }
}
