#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QObject>
#include <QFile>
#include "iniciar.h"
#include "registrarse.h"
#include "usuario.h"
#include "mainwindow.h"
#include "perfil.h"
#include "cargarusuarios.h"
#include "librodata.h"

#include "QList"

class Principal : public QObject
{
    Q_OBJECT

public:
    explicit Principal(QObject *parent = nullptr);

    void comenzar();
    void leerBDUsuarios(QString ruta);
    void leerBDLibros(QString ruta);


    void guardarBD(QList <Usuario> usu);
    int revisarRepetidoPerfil(QString usu);

    int getUsuarioActual() const;
    void setUsuarioActual(int value);

    QString getDirbd() const;
    void setDirbd(const QString &value);

    QString getDirbdLibros() const;
    void setDirbdLibros(const QString &value);

signals:

public slots:

private slots:
    void registrarUsuario(QString nom, QString user, QString pass, QString nac, QString mail);
    void iniciarSesion(QString user, QString pass);
    void carUsuBase(QString ruta);
    void guardarPerfil(QString usu);
    void buscarLibrosSignal(QString li, int que);
    void cargarUsuShow();
    void regUsuShow();
    void iniUsuShow();
    void perfilShow();

private:
    Iniciar *ini;
    Registrarse *reg;
    MainWindow *w;
    Perfil *perf;
    CargarUsuarios *carUsu;
    QList <Usuario> usuarios;
    QList <LibroData> libros;
    int usuarioActual;
    QString dirbd;
    QString dirbdLibros;
};

#endif // PRINCIPAL_H
