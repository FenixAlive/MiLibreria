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

    void dibujarLibros(LibroData *lib);

private slots:
    void on_actionSalir_triggered();

    void on_actionPerfil_triggered();

    void on_actionCargar_Usuarios_triggered();

    void on_actionAcerca_De_triggered();

    void on_buscarInput_textChanged(const QString &arg1);

    void on_actionCargar_Libros_triggered();

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

signals:
    void botonPerfil();
    void cargarUsuario();
    void buscarLibrosInputSignal(QString lib, int que);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
