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
    carWait = new Cargando();

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

    QObject::connect(w, SIGNAL(recomendarSignal()),
                     this, SLOT(recomendadosSlot()));

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
    int numUsu = leerBDUsuarios(getDirbd());

    //lee la base de datos de libros
    libros = leerBDLibros(getDirbdLibros()+"todos.txt");

    //hacer grafo para recomendados
    hacerGrafo(numUsu);

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

int Principal::leerBDUsuarios(QString ruta){
    int num = 0;
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
                num++;
            }
       }
    }
    //cierra la base de datos
    bd.close();
    return num;
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

void Principal::recomendadosSlot()
{
   recomendarLibros();
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
            //busca los libros para recomendar
            recomendarLibros();
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
    liBuscar = li;
    queBuscar = que;
    cualBuscar = cual;
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
      //mergesort
      mergeSort(libros, como);
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
      //reimprimir lista ahora ordenada
      buscarLibrosSignal(liBuscar, queBuscar, cualBuscar);
}

void Principal::mergeSort(QList<LibroData> &A, int como)
{
    if(A.size() > 1){
        QList<LibroData>::iterator it = A.begin();
        unsigned int p = A.size() / 2;
        QList<LibroData> B;
        QList<LibroData> C;
        for (unsigned int i=0; i< p; ++i, ++it){
            B.push_back(*it);//valor en el iterador
        }
        for(unsigned int i = p; i<(unsigned int)A.size(); ++i, ++it){
            C.push_back(*it);
        }
        mergeSort(B, como);
        mergeSort(C, como);
        merge(B, C, A, como);
    }
}

void Principal::merge(QList<LibroData> B, QList<LibroData> C, QList<LibroData> &A, int como)
{
    A.clear(); //limpiar lista
    QList<LibroData>::iterator itB = B.begin();
    QList<LibroData>::iterator itC = C.begin();

    while(itB != B.end() && itC != C.end()){
        LibroData b = *itB;
        LibroData c = *itC;
        switch(como){
            case 1:
            //función de ordenamiento, recibe donde comienza, donde termina y una función personalizada para comparar y ordenar
            if(b.getTitulo() <= c.getTitulo()){
                A.push_back(*itB);
                ++itB;
            }else{
                A.push_back(*itC);
                ++itC;
            }
            break;
         case 2:
            if(b.getAutor() <= c.getAutor()){
                A.push_back(*itB);
                ++itB;
            }else{
                A.push_back(*itC);
                ++itC;
            }
            break;
         case 3:
            if(b.getAnio() <= c.getAnio()){
                A.push_back(*itB);
                ++itB;
            }else{
                A.push_back(*itC);
                ++itC;
            }
            break;
         case 4:
            if(b.getEditorial() <= c.getEditorial()){
                A.push_back(*itB);
                ++itB;
            }else{
                A.push_back(*itC);
                ++itC;
            }
            break;
         case 5:
            if(b.getCategoria() <= c.getCategoria()){
                A.push_back(*itB);
                ++itB;
            }else{
                A.push_back(*itC);
                ++itC;
            }
            break;
      }

    }
    if( itB == B.end()){
        while(itC != C.end()){
            A.push_back(*itC);
            ++itC;
        }
    }else{
        while(itB != B.end()){
            A.push_back(*itB);
            ++itB;
        }
    }
}

void Principal::hacerGrafo(int numUsu)
{
    //sacar porcentaje de usuarios
    float porc = 100.0/(float)numUsu;
    QHash<QString, int> aristas;
    QFile bd;
    QString temp;
    QList <QString> tempList;
    QList <QString> tempLibroKey;
    QList <QString> tempLibroAristas;
    QString keyGrafo, KeyArista;
    int contadorUsu = 0;
    //iterar usuarios para leer sus libros y favoritos
    foreach(Usuario u, usuarios){
        //imprimir porcentaje
        contadorUsu++;
        qDebug()<<"\tCargando...\t"<<porc*(float)contadorUsu<<"\t%";
        //leer el archivo mis libros
        bd.setFileName(getDirbdLibros()+"mis/"+u.getUsuario()+"_bks.txt");
        if(!bd.exists()){
            qDebug() <<"El archivo no existe, mis: "+u.getUsuario();
            bd.open(QIODevice::WriteOnly | QIODevice::Text);
            bd.close();
        }else{
            bd.open(QIODevice::ReadOnly | QIODevice::Text);
            if(!bd.isOpen()){
                qDebug() <<"El archivo no se pudo abrir";
            }else{
                temp = bd.readAll();
                tempList.clear();
                tempList = temp.split("\n");
                //agregar la información a la lista
                //llave del grafo
                foreach(QString t, tempList){
                    tempLibroKey.clear();
                    tempLibroKey = t.split("|");
                    //si la linea que se esta leyendo no esta vacia
                    if(tempLibroKey[0] != ""){
                        //dar valor al nombre a buscar en el grafo como key
                        //0:titulo, 1:Autor, 2:Editorial, 3:Año, 4:Categoria
                        keyGrafo = tempLibroKey[0]+tempLibroKey[3];
                        //si no existe el nodo en el grafo
                        if(!grafo.contains(keyGrafo)){
                            aristas.clear();
                            //crear el nodo del grafo y ponerle una arista vacia
                            grafo.insert(keyGrafo, aristas);
                        }
                        //llave de aristas
                        foreach(QString subLibro, tempList){
                            tempLibroAristas.clear();
                            tempLibroAristas = subLibro.split("|");
                            //si la linea que se esta leyendo no esta vacia
                            if(tempLibroAristas[0] != ""){
                                //dar valor al key de la arista a agregar al grafo
                                KeyArista = tempLibroAristas[0]+tempLibroAristas[3];
                                //revisa si la key del grafo no es la misma que el key de la arista a agregar
                                if(keyGrafo != KeyArista){
                                    //si ya existe la arista
                                    if(grafo[keyGrafo].contains(KeyArista)){
                                        //agrega en 1 el valor del peso
                                        grafo[keyGrafo][KeyArista]++;
                                    }else{
                                        //si no existe, crea la arista y le asigna el peso
                                        grafo[keyGrafo].insert(KeyArista, 1);
                                    }
                                }
                            }
                        }
                    }
                }

            }
        }
        bd.close();
        //leer archivo favoritos
        bd.setFileName(getDirbdLibros()+"fav/"+u.getUsuario()+"_fv.txt");
        if(!bd.exists()){
            qDebug() <<"El archivo no existe, fav: "+u.getUsuario();
            bd.open(QIODevice::WriteOnly | QIODevice::Text);
            bd.close();
        }else{
            bd.open(QIODevice::ReadOnly | QIODevice::Text);
            if(!bd.isOpen()){
                qDebug() <<"El archivo no se pudo abrir";
            }else{
                temp = bd.readAll();
                tempList.clear();
                tempList = temp.split("\n");
                foreach(QString t, tempList){
                    tempLibroKey.clear();
                    tempLibroKey = t.split("|");
                    if(tempLibroKey[0] != ""){
                        keyGrafo = tempLibroKey[0]+tempLibroKey[3];
                        if(!grafo.contains(keyGrafo)){
                            grafo.insert(keyGrafo, aristas);
                        }
                        foreach(QString subLibro, tempList){
                            tempLibroAristas.clear();
                            tempLibroAristas = subLibro.split("|");
                            if(tempLibroAristas[0] != ""){
                                KeyArista = tempLibroAristas[0]+tempLibroAristas[3];
                                if(keyGrafo != KeyArista){
                                    if(grafo[keyGrafo].contains(KeyArista)){
                                        grafo[keyGrafo][KeyArista]+=5;
                                    }else{
                                        grafo[keyGrafo].insert(KeyArista, 5);
                                    }
                                }
                            }
                        }
                    }
                }

            }
        }
        bd.close();
    }
    qDebug()<<"\tIniciando.. 100    %";
    /*
    //iterar, imprimir el grafo y guardarlo en archivo de texto
    QHash<QString, QHash<QString, int>>::iterator origenes = grafo.begin();
    QString ruta = getDirbdLibros()+"grafo.txt";
    int gb=0;
    bd.setFileName(ruta);
    if(!bd.exists()){
        qDebug() <<"El archivo de agregarBDLibro no existe en la ruta: "+ruta;
    }else{
        bd.open(QIODevice::WriteOnly | QIODevice::Text);
        if(!bd.isOpen()){
            qDebug() <<"El archivo de BDLibro no se pudo abrir en la ruta: "+ruta;
        }else{
            gb=1;
        }
    }
    while(origenes != grafo.end()){
        QHash<QString, int>::iterator destinos =origenes.value().begin();
        while(destinos != origenes.value().end()){
            qDebug()<<origenes.key()<<" : "<<destinos.key()<<", "<<destinos.value();
        //base de datos
        if(gb){
            QTextStream out(&bd);
            out << origenes.key() <<" : "<<destinos.key() <<" = "<<destinos.value() <<"\n";
            bd.flush();
        }

            destinos++;
        }
        origenes++;
    }
    bd.close();
*/
}

void Principal::recomendarLibros()
{
    QString titKey, titAri;
    int valGrafo, valRec[3]={0,0,0};
    //iterar mis libros
    foreach(LibroData libK, libros){
        //si esta en mis libros
        if(libK.getBoton()){
            titKey = libK.getTitulo()+libK.getAnio();
            foreach(LibroData libA, libros){
                //si no esta en mis libros
                if(!libA.getBoton()){
                    titAri = libA.getTitulo()+libA.getAnio();
                    if(grafo[titKey].contains(titAri)){
                        valGrafo = grafo[titKey][titAri];
                        if(valGrafo > valRec[0]){
                            qDebug()<<"cero: "<<titKey<<" : "<<titAri<<valGrafo;
                            valRec[2] = valRec[1];
                            valRec[1] = valRec[0];
                            valRec[0] = valGrafo;
                            recomendados[2]=recomendados[1];
                            recomendados[1] = recomendados[0];
                            recomendados[0] = libA;
                        }else if(valGrafo > valRec[1]){
                           qDebug()<<"uno: "<<titKey<<" : "<<titAri<<valGrafo;
                            valRec[2] = valRec[1];
                            valRec[1] = valGrafo;
                            recomendados[2] =recomendados[1];
                            recomendados[1] = libA;
                        }else if(valGrafo > valRec[2]){
                            qDebug()<<"dos: "<<titKey<<" : "<<titAri<<valGrafo;
                            valRec[2] = valRec[1];
                            valRec[2] = valGrafo;
                            recomendados[2] = libA;

                        }
                    }
                }
            }
        }
    }
    //imprimir libros recomendados
    w->dibujarLibros(&recomendados[0]);
    w->dibujarLibros(&recomendados[1]);
    w->dibujarLibros(&recomendados[2]);
    qDebug()<<"\n------------------------------------\n";
    qDebug()<<"Recomendado 1: "<<recomendados[0].getTitulo()+recomendados[0].getAnio()<<valRec[0];
    qDebug()<<"Recomendado 2: "<<recomendados[1].getTitulo()+recomendados[1].getAnio()<<valRec[1];
    qDebug()<<"Recomendado 3: "<<recomendados[2].getTitulo()<<valRec[2];
}
