#ifndef CARGANDO_H
#define CARGANDO_H

#include <QDialog>

namespace Ui {
class Cargando;
}

class Cargando : public QDialog
{
    Q_OBJECT

public:
    explicit Cargando(QWidget *parent = 0);
    ~Cargando();
    void setValorTexto(QString text);
    void setValorBar(float val);

private:
    Ui::Cargando *ui;
};

#endif // CARGANDO_H
