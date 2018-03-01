#ifndef CARGARUSUARIOS_H
#define CARGARUSUARIOS_H

#include <QDialog>
#include <QFileSystemModel>

namespace Ui {
class CargarUsuarios;
}

class CargarUsuarios : public QDialog
{
    Q_OBJECT

public:
    explicit CargarUsuarios(QWidget *parent = 0);
    ~CargarUsuarios();

private slots:
    void on_botones_accepted(); //boton de aceptar clic

    void on_botones_rejected(); //boton cancelar clic

    void on_buscarTree_clicked(const QModelIndex &index); //clic en un elemento del arbol

signals:
    void carUsuRuta(QString ruta); //señal enviada a principal para leer los usuarios en la ruta especificda y guardarlos en la base de usuarios

private:
    Ui::CargarUsuarios *ui;
    QFileSystemModel *filemodel; //objeto de la clase file para el arbol
};

#endif // CARGARUSUARIOS_H
