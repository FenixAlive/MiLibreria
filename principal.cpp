#include "principal.h"
#include <QMessageBox>
#include <QFile>
#include <QDebug>

Principal::Principal(QObject *parent) : QObject(parent)
{
    //crear objetos
    ini = new Iniciar();
    reg = new Registrarse();
    w = new MainWindow();
    perf = new Perfil();
    carUsu = new CargarUsuarios();

    //conectar señales

    //Clase iniciar
    QObject::connect(ini, SIGNAL(iniciar(QString, QString)),
                     this, SLOT(iniciarSesion(QString,QString)));

    QObject::connect(ini, SIGNAL(botonReg()),
                     this, SLOT(regUsuShow()));

    //Clase Registrarse
    QObject::connect(reg, SIGNAL(regUsu(QString, QString, QString, QString, QString)),
                     this, SLOT(registrarUsuario(QString,QString,QString,QString,QString)));

    QObject::connect(reg, SIGNAL(regToIni()),
                     this, SLOT(iniUsuShow()));

    //Clase mainWindow
    QObject::connect(w, SIGNAL(botonPerfil()),
                     this, SLOT(perfilShow()));

    QObject::connect(w, SIGNAL(cargarUsuario()),
                     this, SLOT(cargarUsuShow()));

    QObject::connect(perf, SIGNAL(guardarPerfilSignal()),
                     this, SLOT(guardarPerfil()));

    QObject::connect(carUsu, SIGNAL(carUsuRuta(QString)),
                     this, SLOT(carUsuBase(QString)));

}

//metodos de funcion
void Principal::leerBDUsuarios(QString ruta){
    QFile bd;
    bd.setFileName(ruta);
    if(!bd.exists()){
        qDebug() <<"El archivo no existe";
    }else{
        bd.open(QIODevice::ReadOnly | QIODevice::Text);
        if(!bd.isOpen()){
            qDebug() <<"El archivo no se pudo abrir";
        }else{
            QString temp;
            temp = bd.readAll();
            QList <QString> tempList = temp.split("\n");
            //agregar la información a la lista
            QList<QString> tempUsuList;
            Usuario u;
            foreach(QString t, tempList){
                tempUsuList = t.split("|");
                if(tempUsuList[0] != ""){
                    //guardar datos en un tipo usuario y agregar el usuario a la lista
                    u.setNombre(tempUsuList[0]);
                    u.setNacimiento(tempUsuList[1]);
                    u.setUsuario(tempUsuList[2]);
                    u.setContrasena(tempUsuList[3]);
                    u.setCorreo(tempUsuList[4]);
                    usuarios.append(u);
                }
            }
       }
    }
    bd.close();
}
void Principal::comenzar(){
    leerBDUsuarios(getDirbd());
    ini->show();
}
//slots
void Principal::regUsuShow(){
    reg->show();
}
void Principal::iniUsuShow(){
    ini->show();
}

void Principal::perfilShow(){
    perf->show();
    perf->agregarInfo(usuarios[getUsuarioActual()]);
}

void Principal::cargarUsuShow()
{
    carUsu->show();
}

QString Principal::getDirbd() const
{
    return dirbd;
}

void Principal::setDirbd(const QString &value)
{
    dirbd = value;
}

void Principal::guardarBD(QList<Usuario> usu)
{
    //base de datos
    QFile bd;
    bd.setFileName(getDirbd());
    if(!bd.exists()){
        qDebug() <<"El archivo no existe";
    }else{
        bd.open(QIODevice::WriteOnly | QIODevice::Text);
        if(!bd.isOpen()){
            qDebug() <<"El archivo no se pudo abrir";
        }else{
            QTextStream out(&bd);
            foreach (Usuario u, usu) {
                out << u.getNombre() << "|" << u.getNacimiento() << "|" << u.getUsuario() << "|" << u.getContrasena() << "|" << u.getCorreo() << "\n";
            }
        }
        bd.flush();
        bd.close();
    }

}
//funciones de señales
int Principal::getUsuarioActual() const
{
    return usuarioActual;
}

void Principal::setUsuarioActual(int value)
{
    usuarioActual = value;
}

void Principal::registrarUsuario(QString nom, QString user, QString pass, QString nac, QString mail){
    int count = 0;
    QList<Usuario>::iterator it=usuarios.begin();
    QMessageBox m;
    while(it != usuarios.end()){
        if(it->getUsuario()==user){
            m.setText("El Usuario ya existe");
            m.exec();
            break;
        }
        ++it;
        count++;
    }
    if(it == usuarios.end()){

        Usuario u;
        u.setNombre(nom);
        u.setUsuario(user);
        u.setContrasena(pass);
        u.setNacimiento(nac);
        u.setCorreo(mail);
        usuarios.append(u);
        //base de datos
        QFile bd;
        bd.setFileName(getDirbd());
        if(!bd.exists()){
            qDebug() <<"El archivo no existe";
        }else{
            bd.open(QIODevice::Append | QIODevice::Text);
            if(!bd.isOpen()){
                qDebug() <<"El archivo no se pudo abrir";
            }else{
                QTextStream out(&bd);
                out << nom <<"|"<<nac<<"|"<<user<<"|"<<pass<<"|"<<mail<<"\n";
            }
            bd.flush();
            bd.close();
        }
        m.setText("Registrado Correctamente");
        m.exec();
        setUsuarioActual(count);
        reg->close();
        w->show();
    }
}
void Principal::iniciarSesion(QString user, QString pass){
    QList<Usuario>::iterator it=usuarios.begin();
    QMessageBox m;
    int count = 0;
    while(it != usuarios.end()){
        if(it->getUsuario()==user && it->getContrasena()==pass){
            w->show();
            ini->close();
            setUsuarioActual(count);
            break;
        }
        ++it;
        count++;
    }
    if(it == usuarios.end()){
        m.setText("No se encuentra el usuario");
        m.exec();
    }
}

void Principal::carUsuBase(QString ruta)
{
   QMessageBox m;
   //lee la base de datos y agrega los usuarios a la lista
   leerBDUsuarios(ruta);
   //buscar y eliminar repetidos
   int i=0, c=0;
   foreach(Usuario us, usuarios){
       foreach(Usuario x, usuarios){
           if(us.getUsuario() == x.getUsuario()){
               c++;
               if(c >= 2)
                    usuarios.removeAt(i);
           }
           i++;
       }
       i=0;
       c=0;
   }
   //guardar los usuarios sin repeticiones
   guardarBD(usuarios);
   m.setText("Usuarios cargados exitosamente");
   m.exec();
   carUsu->close();

}

void Principal::guardarPerfil()
{
    perf->guardarCambios(&usuarios[getUsuarioActual()]);
    guardarBD(usuarios);
}

//line.trimmed() quita saltos de linea de la cadena
