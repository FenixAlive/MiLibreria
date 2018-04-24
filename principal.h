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
#include "QList" //necesario para el usuario y libro
#include "cargando.h"

class Principal : public QObject
{
    Q_OBJECT

public:
    explicit Principal(QObject *parent = nullptr);

    void comenzar(); // función que corre al iniciar la aplicación

    QList<LibroData> leerBDLibros(QString ruta); //funcion para leer una base de datos de libros
    void agregarBDLibro(LibroData lib, QString ruta);

    int leerBDUsuarios(QString ruta); // función para leer la base de datos de los usuarios
    void guardarBD(QList <Usuario> usu); //funcion para guardar una lista de usarios en su base de datos
    int revisarRepetidoPerfil(QString usu); //función que revisa que el nuevo usuario al modificar el perfil no se repita con otro

    void verRelacionLibros(); //le pone valor a la variable boton del la lista libros

    //funciones mergeSort para ordenar los libros
    void mergeSort(QList<LibroData> &A, int como);
    void merge(QList<LibroData> B, QList<LibroData> C, QList<LibroData> &A, int como);

    //funciones para el grafo de libros
    void hacerGrafo(int numUsu);

    // getters and setters
    int getUsuarioActual() const;
    void setUsuarioActual(int value);

    QString getDirbd() const;
    void setDirbd(const QString &value);

    QString getDirbdLibros() const;
    void setDirbdLibros(const QString &value);

signals:

public slots:

private slots:
    //funciones que reciben las señales que se envian de otras clases
    void registrarUsuario(QString nom, QString user, QString pass, QString nac, QString mail);//recibe la señal para registrar usuario
    void iniciarSesion(QString user, QString pass); //recibe la señal para iniciar sesión
    void carUsuBase(QString ruta); // recibe señal  para cargar la base de datos de usuarios
    void guardarPerfil(QString usu); //recibe señal para guardar el nuevo perfil del usuario
    void buscarLibrosSignal(QString li, int que, int cual); //recibe señal para buscar libros
    void guardarUpgradeLibro(LibroData lib); //recibe señal para actualizar mis libros y favoritos
    void ordenarLibros(int como); //recibe señal para ordenar los libros (1:Titulo, 2:Autor, 3:Anio, 4:Editorial, 5:Categoria)
    void cargarUsuShow(); //recibe señal para mostrar ventana cargarUsuarios
    void regUsuShow(); //recibe señal para abrir ventana de registrar usuario
    void iniUsuShow(); //recibe señal para abrir ventana de iniciar sesion
    void perfilShow(); //recibe señal para abrir ventana de cambiar perfil
    //poner función para editar listas al dar clic en boton de libros

private:
    Iniciar *ini; //crea un objeto de la ventana iniciar sesión
    Registrarse *reg; //crea un objeto de la clase registrarse
    MainWindow *w; //crea un objeto del mainWindow
    Perfil *perf; //crea objeto de la ventana  y clase perfil
    CargarUsuarios *carUsu; //crea objeto de la clase cargarUsuarios
    Cargando *carWait; //crea objeto de la clase Cargando
    QList <Usuario> usuarios; //crea una lista de usuarios donde se guardaran mas tarde
    QList <LibroData> libros; //crea una lista de libros vacia para todos los libros
    int usuarioActual; //crea una variable para guardar el usuario actual
    QString dirbd; //crea una variable con la direccion de la base de datos actual de usuarios
    QString dirbdLibros; //crea una variable con la direccion de la base de datos de libros

    //variables para guardar la ultima busqueda
    QString liBuscar;
    int queBuscar;
    int cualBuscar;

    //variables para el grafo
    QHash<QString, QHash<QString, int>> grafo;
};

#endif // PRINCIPAL_H
