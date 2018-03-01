#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "libro.h"
#include "usuario.h"

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

void MainWindow::dibujarLibros(LibroData *lib)
{
        //crear lista widget, el padre es el mismo
        QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->listLibrosWidget);
        //agregando el item al listwidget
        ui->listLibrosWidget->addItem(listWidgetItem);
        //creando objeto del widget a agregar
        Libro *libroItem = new Libro;
        libroItem->setDatos(lib);
        //agregar el item
        ui->listLibrosWidget->setItemWidget(listWidgetItem, libroItem);
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

void MainWindow::on_actionAcerca_De_triggered()
{
    QMessageBox acerca;
    acerca.setStyleSheet("background-color:#333; color:white;");
    acerca.setWindowTitle("Acerca De");
    acerca.setText("MiLibreria es un programa elaborado por Luis Angel Muñoz Franco para la clase de Seminario de Algoritmia.\n\nOpen Source, Prohibida su venta.");
    acerca.exec();
}

void MainWindow::on_buscarInput_textChanged(const QString &arg1)
{
    ui->listLibrosWidget->clear();
    if(arg1 != ""){
        ui->resTitulo->setText("Resultados de la busqueda:");
        emit buscarLibrosInputSignal(arg1, 0);
    }else{
        ui->resTitulo->setText("");
    }
}

void MainWindow::on_actionCargar_Libros_triggered()
{
    //hacer señal para una nueva clase semejante a cargar usuarios
}

void MainWindow::on_actionAntolog_a_triggered()
{
    ui->listLibrosWidget->clear();
    ui->resTitulo->setText("Antología:");
    emit buscarLibrosInputSignal("Antología", 5);
}

void MainWindow::on_actionBiograf_a_triggered()
{
    ui->listLibrosWidget->clear();
    ui->resTitulo->setText("Biografía:");
    emit buscarLibrosInputSignal("Biografía", 5);
}

void MainWindow::on_actionDrama_triggered()
{
    ui->listLibrosWidget->clear();
    ui->resTitulo->setText("Drama:");
    emit buscarLibrosInputSignal("Drama", 5);
}

void MainWindow::on_actionExpositivo_triggered()
{
    ui->listLibrosWidget->clear();
    ui->resTitulo->setText("Expositivo:");
    emit buscarLibrosInputSignal("Expositivo", 5);
}

void MainWindow::on_actionEpistolar_triggered()
{
    ui->listLibrosWidget->clear();
    ui->resTitulo->setText("Epistolar:");
    emit buscarLibrosInputSignal("Epistolar", 5);
}

void MainWindow::on_actionNarrativa_triggered()
{
    ui->listLibrosWidget->clear();
    ui->resTitulo->setText("Narrativa:");
    emit buscarLibrosInputSignal("Narrativa", 5);
}

void MainWindow::on_actionObra_gr_fica_triggered()
{
    ui->listLibrosWidget->clear();
    ui->resTitulo->setText("Obra Gráfica:");
    emit buscarLibrosInputSignal("Obra Gráfica", 5);
}

void MainWindow::on_actionPoes_a_triggered()
{
    ui->listLibrosWidget->clear();
    ui->resTitulo->setText("Poesía");
    emit buscarLibrosInputSignal("Poesía", 5);
}

void MainWindow::on_actionReferencia_triggered()
{
    ui->listLibrosWidget->clear();
    ui->resTitulo->setText("Referencia:");
    emit buscarLibrosInputSignal("Referencia", 5);
}

void MainWindow::on_actionCl_sico_triggered()
{
    ui->listLibrosWidget->clear();
    ui->resTitulo->setText("Clásico:");
    emit buscarLibrosInputSignal("Clásico", 5);
}
