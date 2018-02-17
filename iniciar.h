#ifndef INICIAR_H
#define INICIAR_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Iniciar;
}

class Iniciar : public QDialog
{
    Q_OBJECT

public:
    explicit Iniciar(QWidget *parent = 0);
    ~Iniciar();

private slots:
    void on_iniciarBoton_clicked();

    void on_registrarmeBoton_clicked();

signals:
    void iniciar(QString user, QString pass);
    void botonReg();

private:
    Ui::Iniciar *ui;
};

#endif // INICIAR_H
