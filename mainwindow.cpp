#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "libro.h"
#include "usuario.h"
#include <QDebug>

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
        //señal para agregar a mis libros y a favoritos
        ui->listLibrosWidget->connect(libroItem, SIGNAL(upgradeLibro(LibroData)),
                                      this, SLOT(upgradeLibro(LibroData)));
}

void MainWindow::limpiarList()
{
    ui->listLibrosWidget->clear();
}

//función que corre al cambiar el texto en el buscador de libros
void MainWindow::on_buscarInput_textChanged(const QString &arg1)
{
    //limpia la lista de libros
    if(arg1 == ""){
        ui->listLibrosWidget->clear();
        ui->resTitulo->setText("");
    }
}

void MainWindow::on_buscarInput_editingFinished()
{

    //declara variable con el valor del texto a buscar
    QString arg1 = ui->buscarInput->text();

    //revisa si el texto no esta vacio
    if(arg1 != ""){
        //limpia la lista de libros
        ui->listLibrosWidget->clear();
        //escribe en el label debajo del buscador un titulo
        ui->resTitulo->setText("Resultados de la busqueda: "+arg1);
        // emite señal con la palabra a buscar y con la clave 0 que busca en todos los datos y otro 0 indicando que busque en todos los libros
        emit buscarLibrosInputSignal(arg1, 0, 0);
    }
}
//al dar clic en las categorias se hace lo siguiente:
//se limpia la lista de widgets
//se pone el titulo de la categoria en el label debajo del buscador
//se emite la señal con la categoria a buscar y la clave 5 que busca solo categoria

void MainWindow::on_actionAntolog_a_triggered()
{
    ui->buscarInput->setText("");
    ui->listLibrosWidget->clear();
    ui->resTitulo->setText("Antología:");
    emit buscarLibrosInputSignal("Antología", 5, 0);
}

void MainWindow::on_actionBiograf_a_triggered()
{
    ui->buscarInput->setText("");
    ui->listLibrosWidget->clear();
    ui->resTitulo->setText("Biografía:");
    emit buscarLibrosInputSignal("Biografía", 5, 0);
}

void MainWindow::on_actionDrama_triggered()
{
    ui->buscarInput->setText("");
    ui->listLibrosWidget->clear();
    ui->resTitulo->setText("Drama:");
    emit buscarLibrosInputSignal("Drama", 5, 0);
}

void MainWindow::on_actionExpositivo_triggered()
{
    ui->buscarInput->setText("");
    ui->listLibrosWidget->clear();
    ui->resTitulo->setText("Expositivo:");
    emit buscarLibrosInputSignal("Expositivo", 5, 0);
}

void MainWindow::on_actionEpistolar_triggered()
{
    ui->buscarInput->setText("");
    ui->listLibrosWidget->clear();
    ui->resTitulo->setText("Epistolar:");
    emit buscarLibrosInputSignal("Epistolar", 5, 0);
}

void MainWindow::on_actionNarrativa_triggered()
{
    ui->buscarInput->setText("");
    ui->listLibrosWidget->clear();
    ui->resTitulo->setText("Narrativa:");
    emit buscarLibrosInputSignal("Narrativa", 5, 0);
}

void MainWindow::on_actionObra_gr_fica_triggered()
{
    ui->buscarInput->setText("");
    ui->listLibrosWidget->clear();
    ui->resTitulo->setText("Obra Gráfica:");
    emit buscarLibrosInputSignal("Obra Gráfica", 5, 0);
}

void MainWindow::on_actionPoes_a_triggered()
{
    ui->buscarInput->setText("");
    ui->listLibrosWidget->clear();
    ui->resTitulo->setText("Poesía");
    emit buscarLibrosInputSignal("Poesía", 5, 0);
}

void MainWindow::on_actionReferencia_triggered()
{
    ui->buscarInput->setText("");
    ui->listLibrosWidget->clear();
    ui->resTitulo->setText("Referencia:");
    emit buscarLibrosInputSignal("Referencia", 5, 0);
}

void MainWindow::on_actionCl_sico_triggered()
{
    ui->buscarInput->setText("");
    ui->listLibrosWidget->clear();
    ui->resTitulo->setText("Clásico:");
    emit buscarLibrosInputSignal("Clásico", 5, 0);
}

//dar clic en todos los libros busca el codigo 7 que son todos los libros y 0 que busca en la lista de todos los libros

void MainWindow::on_actionTodos_triggered()
{
    ui->buscarInput->setText("");
    ui->listLibrosWidget->clear();
    ui->resTitulo->setText("Todos los Libros");
    emit buscarLibrosInputSignal("", 7, 0);
}

//al dar clic en mis libros manda a llamar la funcion buscar libros, 7 para todos los libros y 1 que busca en la lista de mis libros

void MainWindow::on_actionMis_Libros_triggered()
{
    ui->buscarInput->setText(""); // deja en blanco el buscador
    ui->listLibrosWidget->clear(); //limpia el widget de libros
    ui->resTitulo->setText("Mis Libros"); //pone texto en el label de titulo
    emit buscarLibrosInputSignal("", 7, 1); //envia señal para buscar todos los libros en mis libros
}

void MainWindow::on_actionFavoritos_triggered()
{
    ui->buscarInput->setText(""); // deja en blanco el buscador
    ui->listLibrosWidget->clear(); //limpia el widget de libros
    ui->resTitulo->setText("Favoritos"); //pone texto en el label de titulo
    emit buscarLibrosInputSignal("", 7, 2); //envia señal para buscar todos los libros en Favoritos
}

//Slot que emite una señal a principal para guardar la señal del boton del widget

void MainWindow::upgradeLibro(LibroData lib)
{
   emit guardarUpgradeLibro(lib);
}

void MainWindow::on_actionOrderTitulo_triggered()
{
    //ver si no estaba checkeado antes
    if(ui->actionOrderTitulo->isChecked()){
        //quitar el check a las otras categorias
        ui->actionOrderAutor->setChecked(false);
        ui->actionOrderAnio->setChecked(false);
        ui->actionOrderEditorial->setChecked(false);
        ui->actionOrderCategoria->setChecked(false);
        ui->listLibrosWidget->clear(); //limpia el widget de libros
        //emitir señal de ordenamiento
        emit ordenarLibros(1);
    }else{
        ui->actionOrderTitulo->setChecked(true);
    }
}

void MainWindow::on_actionOrderAutor_triggered()
{
    //ver si no estaba checkeado antes
    if(ui->actionOrderAutor->isChecked()){
        //quitar el check a las otras categorias
        ui->actionOrderTitulo->setChecked(false);
        ui->actionOrderAnio->setChecked(false);
        ui->actionOrderEditorial->setChecked(false);
        ui->actionOrderCategoria->setChecked(false);
        ui->listLibrosWidget->clear(); //limpia el widget de libros
        //emitir señal de ordenamiento
        emit ordenarLibros(2);
    }else{
        ui->actionOrderAutor->setChecked(true);
    }
}

void MainWindow::on_actionOrderAnio_triggered()
{
    //ver si no estaba checkeado antes
    if(ui->actionOrderAnio->isChecked()){
        //quitar el check a las otras categorias
        ui->actionOrderTitulo->setChecked(false);
        ui->actionOrderAutor->setChecked(false);
        ui->actionOrderEditorial->setChecked(false);
        ui->actionOrderCategoria->setChecked(false);
        ui->listLibrosWidget->clear(); //limpia el widget de libros
        //emitir señal de ordenamiento
        emit ordenarLibros(3);
    }else{
        ui->actionOrderAnio->setChecked(true);
    }
}

void MainWindow::on_actionOrderEditorial_triggered()
{
    //ver si no estaba checkeado antes
    if(ui->actionOrderEditorial->isChecked()){
        //quitar el check a las otras categorias
        ui->actionOrderTitulo->setChecked(false);
        ui->actionOrderAutor->setChecked(false);
        ui->actionOrderAnio->setChecked(false);
        ui->actionOrderCategoria->setChecked(false);
        ui->listLibrosWidget->clear(); //limpia el widget de libros
        //emitir señal de ordenamiento
        emit ordenarLibros(4);
    }else{
        ui->actionOrderEditorial->setChecked(true);
    }
}

void MainWindow::on_actionOrderCategoria_triggered()
{
    //ver si no estaba checkeado antes
    if(ui->actionOrderCategoria->isChecked()){
        //quitar el check a las otras categorias
        ui->actionOrderTitulo->setChecked(false);
        ui->actionOrderAutor->setChecked(false);
        ui->actionOrderAnio->setChecked(false);
        ui->actionOrderEditorial->setChecked(false);
        ui->listLibrosWidget->clear(); //limpia el widget de libros
        //emitir señal de ordenamiento
        emit ordenarLibros(5);
    }else{
        ui->actionOrderCategoria->setChecked(true);
    }
}

void MainWindow::on_actionRecomendados_triggered()
{
   ui->resTitulo->setText("Recomendados"); //pone texto en el label de titulo
   ui->listLibrosWidget->clear(); //limpia el widget de libros
   emit recomendarSignal();
}
