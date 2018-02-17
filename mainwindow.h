#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionSalir_triggered();

    void on_actionPerfil_triggered();

    void on_actionCargar_Usuarios_triggered();

signals:
    void botonPerfil();
    void cargarUsuario();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
