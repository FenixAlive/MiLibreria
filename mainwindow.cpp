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

//salir de la apliciación

void MainWindow::on_actionSalir_triggered()
{
    this->close();
}

//emitir señal para abrir la ventana de perfil desde principal

void MainWindow::on_actionPerfil_triggered()
{
    emit botonPerfil();
}

//emite señal para abrir ventana de cargarUsuario desde principal

void MainWindow::on_actionCargar_Usuarios_triggered()
{
   emit cargarUsuario();
}

//abre messagebox con acerca de

void MainWindow::on_actionAcerca_De_triggered()
{
    QMessageBox acerca;
    acerca.setStyleSheet("background-color:#333; color:white;");
    acerca.setWindowTitle("Acerca De");
    acerca.setText("MiLibreria es un programa elaborado por Luis Angel Muñoz Franco para la clase de Seminario de Algoritmia.\n\nOpen Source, Prohibida su venta.");
    acerca.exec();
}

// función que dibuja un libro a la vez en la lista widget

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

//función que corre al cambiar el texto en el buscador de libros

void MainWindow::on_buscarInput_textChanged(const QString &arg1)
{
    //limpia la lista de libros
    ui->listLibrosWidget->clear();

    //revisa si el texto no esta vacio
    if(arg1 != ""){
        //escribe en el label debajo del buscador un titulo
        ui->resTitulo->setText("Resultados de la busqueda:");
        // emite señal con la palabra a buscar y con la clave 0 que busca en todos los datos
        emit buscarLibrosInputSignal(arg1, 0);
    }else{
        ui->resTitulo->setText("");
    }
}

//al dar clic en las categorias se hace lo siguiente:
//se limpia la lista de widgets
//se pone el titulo de la categoria en el label debajo del buscador
//se emite la señal con la categoria a buscar y la clave 5 que busca solo categoria

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
