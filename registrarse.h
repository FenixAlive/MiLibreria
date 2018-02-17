#ifndef REGISTRARSE_H
#define REGISTRARSE_H

#include <QDialog>

namespace Ui {
class Registrarse;
}

class Registrarse : public QDialog
{
    Q_OBJECT

public:
    explicit Registrarse(QWidget *parent = 0);
    ~Registrarse();

private slots:
    void on_iniciarBotonNuevo_clicked();

    void on_registrarmeBotonNuevo_clicked();

signals:
    void regUsu(QString nom, QString user, QString pass, QString nac, QString mail);
    void regToIni();

private:
    Ui::Registrarse *ui;
};

#endif // REGISTRARSE_H
