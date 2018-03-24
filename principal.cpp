#include "principal.h"
#include <QMessageBox>
#include <QFile>
#include <QDebug>

//constructor

Principal::Principal(QObject *parent) : QObject(parent)
{
    //crear objetos de las clases
    ini = new Iniciar();
    reg = new Registrarse();
    w = new MainWindow();
    perf = new Perfil();
    carUsu = new CargarUsuarios();

    //conectar señales de las clases

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

    QObject::connect(w, SIGNAL(buscarLibrosInputSignal(QString, int, int)),
                     this, SLOT(buscarLibrosSignal(QString, int, int)));

    QObject::connect(w, SIGNAL(ordenarLibros(int)),
                     this, SLOT(ordenarLibros(int)));

    //clase perfil
    QObject::connect(perf, SIGNAL(guardarPerfilSignal(QString)),
                     this, SLOT(guardarPerfil(QString)));

    //clase cargarUsuario
    QObject::connect(carUsu, SIGNAL(carUsuRuta(QString)),
                     this, SLOT(carUsuBase(QString)));

    //de clase Libro a MainWindow y de mainWindow a principal
    QObject::connect(w, SIGNAL(guardarUpgradeLibro(LibroData)),
                     this, SLOT(guardarUpgradeLibro(LibroData)));



}

//función que corre al iniciar aplicación

void Principal::comenzar(){
    //lee la base de datos de usuarios
    leerBDUsuarios(getDirbd());

    //lee la base de datos de libros
    libros = leerBDLibros(getDirbdLibros()+"todos.txt");

    //abre la ventana de iniciar sesión
    ini->show();
}

//getter and setters de variables privadas de la clase

QString Principal::getDirbdLibros() const
{
    return dirbdLibros;
}

void Principal::setDirbdLibros(const QString &value)
{
    dirbdLibros = value;
}

QString Principal::getDirbd() const
{
    return dirbd;
}

void Principal::setDirbd(const QString &value)
{
    dirbd = value;
}

int Principal::getUsuarioActual() const
{
    return usuarioActual;
}

void Principal::setUsuarioActual(int value)
{
    usuarioActual = value;
}

//metodos de funcion

//función para leer la base de datos de usuarios y guardarla en la Qlist de usuarios

void Principal::leerBDUsuarios(QString ruta){
    QFile bd; //crear QFile para leer base de datos
    bd.setFileName(ruta); //agregarle la ruta a la base de datos
    if(!bd.exists()){ //si no existe el archivo
        qDebug() <<"El archivo no existe";
    }else{
        //Abrir base de datos en modo lectura
        bd.open(QIODevice::ReadOnly | QIODevice::Text);
        if(!bd.isOpen()){//si no se puede abrir
            qDebug() <<"El archivo no se pudo abrir";
        }else{
            QString temp; //variable temporal
            temp = bd.readAll(); //lee toda la base de datos
            QList <QString> tempList = temp.split("\n"); //la separo por salto de linea y la guardo en una lista
            //agregar la información a la lista
            QList<QString> tempUsuList; //crea una lista temporal
            Usuario u; //crea un usuario temporal

            foreach(QString t, tempList){ //por cada usuario en la lista temporal
                tempUsuList = t.split("|"); //Separa la información por un pipe

                if(tempUsuList[0] != ""){ //si no esta vacia la información del usuario
                    //guardar datos en el usuario temporal y agrega el usuario a la lista
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
    //cierra la base de datos
    bd.close();
}

//funcion que lee la base de datos de libros con la ruta igual que la anterior base de datos

QList <LibroData> Principal::leerBDLibros(QString ruta)
{
    QList <LibroData> leerLib;
    QFile bd;
    bd.setFileName(ruta);
    if(!bd.exists()){
        qDebug() <<"El archivo no existe";
        bd.open(QIODevice::WriteOnly | QIODevice::Text);
        bd.close();
        if(bd.exists())
            qDebug() <<"Archivo creado en: "+ruta;
    }else{
        bd.open(QIODevice::ReadOnly | QIODevice::Text);
        if(!bd.isOpen()){
            qDebug() <<"El archivo no se pudo abrir";
        }else{
            QString temp;
            temp = bd.readAll();
            QList <QString> tempList = temp.split("\n");
            //agregar la información a la lista
            QList <QString> tempLibroList;
            LibroData l;
            int index = 0;
            foreach(QString t, tempList){
                tempLibroList = t.split("|");
                if(tempLibroList[0] != ""){
                    //guardar datos en un tipo usuario y agregar el usuario a la lista
                    l.setTitulo(tempLibroList[0]);
                    l.setAutor(tempLibroList[1]);
                    l.setAnio(tempLibroList[3]);
                    l.setEditorial(tempLibroList[2]);
                    l.setCategoria(tempLibroList[4]);
                    l.setIndex(index);
                    l.setBoton(0);
                    leerLib.append(l);
                    index++;
                }
            }
       }
    }
    bd.close();
    return leerLib;
}

void Principal::agregarBDLibro(LibroData lib, QString ruta)
{
        //base de datos
        QFile bd;
        bd.setFileName(ruta);
        if(!bd.exists()){
            qDebug() <<"El archivo de agregarBDLibro no existe en la ruta: "+ruta;
        }else{
            bd.open(QIODevice::Append | QIODevice::Text);
            if(!bd.isOpen()){
                qDebug() <<"El archivo de BDLibro no se pudo abrir en la ruta: "+ruta;
            }else{
                QTextStream out(&bd);
                out <<"\n"<< lib.getTitulo() <<"|"<<lib.getAutor() <<"|"<<lib.getEditorial() <<"|"<<lib.getAnio() <<"|"<<lib.getCategoria();
            }
            bd.flush();
            bd.close();
        }
}

//slots

void Principal::regUsuShow(){
    //abre la ventana de registrar usuario
    reg->show();
}
void Principal::iniUsuShow(){
    //Abre la ventana de iniciar sesión
    ini->show();
}

void Principal::perfilShow(){
    //abre la ventana de perfil
    perf->show();
    //llama a la función de perfil para agregar la información a al ventana del usuario actual
    perf->agregarInfo(usuarios[getUsuarioActual()]);
}

void Principal::cargarUsuShow()
{
    //abre ventana de cargar usuarios
    carUsu->show();
}

//función para guardar la lista de usuarios pasada como argumento en la base de datos de usuarios

void Principal::guardarBD(QList<Usuario> usu)
{
    //base de datos
    QFile bd;
    bd.setFileName(getDirbd());
    if(!bd.exists()){
        qDebug() <<"El archivo no existe";
    }else{
        //abre la base de datos como escritura, lo cual borra lo que hay en el archivo antes de escribir
        bd.open(QIODevice::WriteOnly | QIODevice::Text);
        if(!bd.isOpen()){
            qDebug() <<"El archivo no se pudo abrir";
        }else{
            QTextStream out(&bd);
            //guarda cada usuario de la lista en una nueva linea en la base de datos
            foreach (Usuario u, usu) {
                out << u.getNombre() << "|" << u.getNacimiento() << "|" << u.getUsuario() << "|" << u.getContrasena() << "|" << u.getCorreo() << "\n";
            }
        }
        bd.flush();
        bd.close();
    }
}

//función para registrar un nuevo usuario

void Principal::registrarUsuario(QString nom, QString user, QString pass, QString nac, QString mail){
    int count = 0;
    QList<Usuario>::iterator it=usuarios.begin();
    QMessageBox m;
    m.setStyleSheet("background-color:#333; color:white;");
    m.setWindowTitle("Advertencia");
    //revisar que el usuario no este repetido
    while(it != usuarios.end()){
        if(it->getUsuario()==user){
            m.setText("El Usuario ya existe");
            m.exec();
            break;
        }
        ++it;
        count++;
    }
    //si el usuario no esta repetido lo guarda en la lista y lo agrega a la base de datos
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
        m.setWindowTitle("MiLibreria");
        m.setText("Registrado Correctamente");
        m.exec();
        setUsuarioActual(count);
        reg->close();
        ini->show();
    }
}

//funcion para iniciar sesión

void Principal::iniciarSesion(QString user, QString pass){
    QList<Usuario>::iterator it=usuarios.begin();
    QMessageBox m;
    m.setStyleSheet("background-color:#333; color:white;");
    m.setWindowTitle("Advertencia");
    int count = 0;
    //buscar en los usuarios uno que sea el mismo y tenga la misma contraseña
    while(it != usuarios.end()){
        if(it->getUsuario()==user && it->getContrasena()==pass){
            //si se lo encuentra abre la ventana prinicial y guarda el usuario actual
            w->show();
            ini->close();
            setUsuarioActual(count);
            //carga lista de libros a fav y mis libros
            verRelacionLibros();
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

//función para cargar usuarios desde otro archivo

void Principal::carUsuBase(QString ruta)
{
   QMessageBox m;
    m.setStyleSheet("background-color:#333; color:white;");
    m.setWindowTitle("MiLibreria");
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

//función que recibe la señal de perfil al dar clic en guardar

void Principal::guardarPerfil(QString usu)
{
    QMessageBox m;
    m.setStyleSheet("background-color:#333; color:white;");
    m.setWindowTitle("MiLibreria");
    //revisa si no esta repetido el usuario que quiere guardar
    if(!revisarRepetidoPerfil(usu)){
        //si no esta repetido llama a la funcion de guardar datos y le pasa la direccion de memoria del usuario para modificarlo
        perf->guardarCambios(&usuarios[getUsuarioActual()]);
        //una vez modificado el usuario en la lista guarda la lista de usuarios en la base de datos
        guardarBD(usuarios);
        m.setText("Usuario Guardado Exitosamente");
        m.exec();
        perf->close();
    }else{
        m.setWindowTitle("Advertencia");
        m.setText("El Usuario ya existe, elija otro");
        m.exec();
    }
}

//funcion que revisa si un usuario que no es el actual ya esta ocupado

int Principal::revisarRepetidoPerfil(QString usu){
   //Ver si no esta repetido
   int c=0;
   foreach(Usuario us, usuarios){
        if(usu == us.getUsuario() && usu != usuarios[getUsuarioActual()].getUsuario()){
               c++;
         }
    }
    if(c){
        return 1;
    }else{
        return 0;
    }
}

//función que revisa las relaciones entre las bases de datos

void Principal::verRelacionLibros()
{
    QList <LibroData> librosMis = leerBDLibros(getDirbdLibros()+"mis/"+usuarios[getUsuarioActual()].getUsuario()+"_bks.txt");
    QList <LibroData> librosFav = leerBDLibros(getDirbdLibros()+"fav/"+usuarios[getUsuarioActual()].getUsuario()+"_fv.txt");
    int enc=0;
    foreach(LibroData l, libros){
        enc=0;
        foreach(LibroData li, librosFav){
            if(l.getTitulo() == li.getTitulo()){
                l.setBoton(2);
                enc=1;
                break;
            }
        }
        if(!enc){
            foreach(LibroData lib, librosMis){
                if(l.getTitulo() == lib.getTitulo()){
                    l.setBoton(1);
                    enc=1;
                    break;
                }
            }
        }
        if(!enc){
            l.setBoton(0);
        }
        libros[l.getIndex()] = l;
    }
}


//función que busca un libro en la base de datos de libros

void Principal::buscarLibrosSignal(QString li, int que, int cual)
{
    int mostrar = 0;

    //por cada libro en la lista de libros
    foreach(LibroData lib, libros){
        mostrar = 0;
        //revisa si el codigo es 0 o si es el indicado
        if(!que || que == 1)
            //revisa si el libro contiene las palabras buscadas
            if(lib.getTitulo().contains(li, Qt::CaseInsensitive)){
                mostrar = 1;
            }
        if(!que || que == 2)
            if(lib.getAutor().contains(li, Qt::CaseInsensitive)){
                mostrar = 1;
            }
        if(!que || que == 3)
            if(lib.getAnio().contains(li, Qt::CaseInsensitive)){
                mostrar = 1;
            }
        if(!que || que == 4)
            if(lib.getEditorial().contains(li, Qt::CaseInsensitive)){
                mostrar = 1;
            }
        if(!que || que == 5)
            if(lib.getCategoria().contains(li, Qt::CaseInsensitive)){
                mostrar = 1;
            }
        //con 7 muestra todos los libros
        if(que == 7)
            mostrar = 1;
        //si encuentra lo buscado en el libro
        if(cual > lib.getBoton()){
            mostrar=0;
        }
        if(mostrar){
            //llama la función de mainwindow para agregar el libro a la lista
            w->dibujarLibros(&lib);
        }
    }
}

//función que corre al dar clic en boton de un libro para agregarlo a mis libros o a favoritos

void Principal::guardarUpgradeLibro(LibroData lib)
{
    libros[lib.getIndex()]=lib;
    QString ruta;
    int agregar = 0;
    switch(lib.getBoton()){
        case 1:
            ruta = getDirbdLibros()+"mis/"+usuarios[getUsuarioActual()].getUsuario()+"_bks.txt";
            agregar =1;
            break;
        case 2:
            agregar =1;
            ruta = getDirbdLibros()+"fav/"+usuarios[getUsuarioActual()].getUsuario()+"_fv.txt";
            break;
    }
    if(agregar)
        agregarBDLibro(lib, ruta);
}

//funcion para ordenar los libros
void Principal::ordenarLibros(int como)
{
      switch(como){
         case 1:
            //función de ordenamiento, recibe donde comienza, donde termina y una función personalizada para comparar y ordenar
            std::sort(libros.begin(), libros.end(), compararTitulo);
            break;
         case 2:
            std::sort(libros.begin(), libros.end(), compararAutor);
            break;
         case 3:
            std::sort(libros.begin(), libros.end(), compararAnio);
            break;
         case 4:
            std::sort(libros.begin(), libros.end(), compararEditorial);
            break;
         case 5:
            std::sort(libros.begin(), libros.end(), compararCategoria);
            break;
      }
      //reacomodar la variable index de los libros despues de ordenarlos.
      int i=0;
      LibroData libTemp;
      foreach (LibroData l, libros) {
          libTemp.setTitulo(l.getTitulo());
          libTemp.setAutor(l.getAutor());
          libTemp.setAnio(l.getAnio());
          libTemp.setEditorial(l.getEditorial());
          libTemp.setCategoria(l.getCategoria());
          libTemp.setBoton(l.getBoton());
          libTemp.setIndex(i);
          libros[i]=libTemp;
          i++;
      }
}

//funciones personalizadas utilizadas para ordenar los libros

bool Principal::compararTitulo(const LibroData& i, const LibroData& j)
{
        return i.getTitulo() < j.getTitulo();
}

bool Principal::compararAutor(const LibroData &i, const LibroData &j)
{
        return i.getAutor() < j.getAutor();
}

bool Principal::compararAnio(const LibroData &i, const LibroData &j)
{
        return i.getAnio() < j.getAnio();
}

bool Principal::compararEditorial(const LibroData &i, const LibroData &j)
{
        return i.getEditorial() < j.getEditorial();
}

bool Principal::compararCategoria(const LibroData &i, const LibroData &j)
{
        return i.getCategoria() < j.getCategoria();
}
