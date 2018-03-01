#include "iniciar.h"
#include "mainwindow.h"
#include "ui_iniciar.h"
#include "registrarse.h"
#include "principal.h"
#include <QMessageBox>

Iniciar::Iniciar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Iniciar)
{
    ui->setupUi(this);
}

Iniciar::~Iniciar()
{
    delete ui;
}

void Iniciar::on_iniciarBoton_clicked()
{
    QMessageBox mes;
    mes.setStyleSheet("background-color:#333; color:white;");
    mes.setWindowTitle("Advertencia");
    if(ui->contrasenaInput->text().count()<4){
        mes.setText("Revisa la contraseña\n");
    }
    if(ui->usuarioInput->text().count()<4){
        mes.setText("Revisa tu usuario\n");
    }
    if(ui->contrasenaInput->text().count()>3 && ui->usuarioInput->text().count()>3){
        emit iniciar(ui->usuarioInput->text(), ui->contrasenaInput->text());
    }else{
        mes.exec();
    }


}

void Iniciar::on_registrarmeBoton_clicked()
{
    this->close();
    emit botonReg();
}
