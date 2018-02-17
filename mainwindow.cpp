#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSalir_triggered()
{
    this->close();
}

void MainWindow::on_actionPerfil_triggered()
{
    emit botonPerfil();
}

void MainWindow::on_actionCargar_Usuarios_triggered()
{
   emit cargarUsuario();
}
