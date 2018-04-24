#include "cargando.h"
#include "ui_cargando.h"

Cargando::Cargando(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cargando)
{
    ui->setupUi(this);
}

Cargando::~Cargando()
{
    delete ui;
}

void Cargando::setValorTexto(QString text)
{
    ui->texto->setText(text);
}

void Cargando::setValorBar(float val)
{
   ui->progressBar->setValue((int)val);
}
