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

//al dar clic en iniciar sesion se emite señal para abrir la ventana iniciar desde principal

void Registrarse::on_iniciarBotonNuevo_clicked()
{
    this->close();
    emit regToIni();
}

//al dar clic en registrar revisa que los datos esten llenos correctamente y de ser asi emite la señal a principal donde revisa que no se repita y se guarda el nuevo usuario

void Registrarse::on_registrarmeBotonNuevo_clicked()
{
    QMessageBox m;
    m.setStyleSheet("background-color:#333; color:white;");
    m.setWindowTitle("Advertencia");
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
