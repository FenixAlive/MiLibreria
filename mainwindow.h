#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "librodata.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void dibujarLibros(LibroData *lib); //función que agrega un widget libro a la lista de widgets

private slots:
    void on_actionSalir_triggered();    //sale del programa

    void on_actionPerfil_triggered(); //abre ventana de perfil

    void on_actionCargar_Usuarios_triggered(); //abre ventana de CargarUsuarios

    void on_actionAcerca_De_triggered(); //abre QMessageBox indicando un acercaDe

    void on_buscarInput_textChanged(const QString &arg1); //función que se ejecuta al cambiar una letra del buscador de libros

    void on_buscarInput_editingFinished();//función que se ejecuta al dar enter en el buscador o al salir del focus

    // Categorias

    void on_actionAntolog_a_triggered();

    void on_actionBiograf_a_triggered();

    void on_actionDrama_triggered();

    void on_actionExpositivo_triggered();

    void on_actionEpistolar_triggered();

    void on_actionNarrativa_triggered();

    void on_actionObra_gr_fica_triggered();

    void on_actionPoes_a_triggered();

    void on_actionReferencia_triggered();

    void on_actionCl_sico_triggered();


    void on_actionTodos_triggered();

    void on_actionMis_Libros_triggered();

    void on_actionFavoritos_triggered();

    void upgradeLibro(LibroData lib);


    void on_actionOrderTitulo_triggered();

    void on_actionOrderAutor_triggered();

    void on_actionOrderAnio_triggered();

    void on_actionOrderEditorial_triggered();

    void on_actionOrderCategoria_triggered();

    void on_actionRecomendados_triggered();

signals:
    void botonPerfil(); //señal que se conecta en clase principal para abrir ventana de perfil
    void cargarUsuario(); //señal para abrir ventana de cargar usuario desde principal
    void buscarLibrosInputSignal(QString lib, int que, int cual); //señal para buscar libros en principal, recibe las letras a buscar y un codigo sobre que va a buscar
    void guardarUpgradeLibro(LibroData lib); //señal para actualizar el boton de agregar a mis libros o favoritos
    void ordenarLibros(int como); //señal para ordenar los libros en cierto orden (1:Titulo, 2:Autor, 3:Anio, 4:Editorial, 5:Categoria)
    void recomendarSignal(); //señal para imprimir recomendados

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
