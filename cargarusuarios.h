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
    void on_botones_accepted();

    void on_botones_rejected();

    void on_buscarTree_clicked(const QModelIndex &index);

signals:
    void carUsuRuta(QString ruta);

private:
    Ui::CargarUsuarios *ui;
    QFileSystemModel *filemodel;
};

#endif // CARGARUSUARIOS_H
