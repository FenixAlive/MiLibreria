#include "cargarusuarios.h"
#include "ui_cargarusuarios.h"
#include <QMessageBox>

CargarUsuarios::CargarUsuarios(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CargarUsuarios)
{
    ui->setupUi(this);
    //configuracion de QFileSystemModel
    filemodel = new QFileSystemModel(this);
    filemodel->setRootPath("./");
    ui->buscarTree->setModel(filemodel);
}

CargarUsuarios::~CargarUsuarios()
{
    delete ui;
}

void CargarUsuarios::on_botones_accepted()
{
    QMessageBox m;
    m.setStyleSheet("background-color:#333; color:white;");
    m.setWindowTitle("Advertencia");
    //revisar si el archivo es txt antes de cargarlo
    if(ui->rutaInput->text().count() > 1){
        if(ui->rutaInput->text().split(".").last() == "txt"){
            emit carUsuRuta(ui->rutaInput->text());
        }else{
            m.setText("El archivo no es txt");
            m.exec();
        }
    }else{
        m.setText("La ruta esta vacia");
        m.exec();
    }
}

void CargarUsuarios::on_botones_rejected()
{
   this->close();
}

// función que pone la direccion que se da clic en el arbol al input para abrirlo
void CargarUsuarios::on_buscarTree_clicked(const QModelIndex &index)
{
    ui->rutaInput->setText(QString(filemodel->fileInfo(index).absoluteFilePath()));
}
