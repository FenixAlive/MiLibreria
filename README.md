Aplicación en Qt C++ para la busqueda y ordenamiento de libros, de acuerdo al curso de Seminario de Algoritmia de la Universidad de Guadalajara.

carpeta bdLibros: incluye todas las bases de datos de los libros por usuario
carpeta img: incluye todos los recursos de imagenes necesarios para el proyecto

MiLibreria.pro, MiLibreria.pro.user: archivos necesarios para el proyecto qt

assets.qrc: archivo de qt que guarda los recursos del proyecto

bdUsuarios.txt: archivo que guarda los usuarios registrados en el sistema

Clases:

CargarUsuarios(.h, .cpp, .ui):
    -clase QDialog realizada como ejemplo de un tree view(model-based) de un QFileSystemModel

Iniciar(.h, .cpp, .ui):
    Clase QDialog, ventana para iniciar sesión

Libro(.h, .cpp, .ui):
    QWidget para mostrar un libro dentro de la lista de widgets de la clase MainWindow.

LibroData(.h, .cpp):
    clase normal de c++ para guardar los datos de un libro(se usará para crear una QList con todos los libros con esta clase)

MainWindow(.h, .cpp, .ui):
    Es la ventana principal de la aplicación que contiene los botones, un input para realizar busquedas de libros y un list-widget(item-based) el cual va agregando widgets de la clase Libro conforme se requiere.

perfil(.h, .cpp, .ui):
    Clase QDialog, Es la ventana que permite modificar el perfil del usuario.

principal(.h, .cpp):
    Clase QObject donde se conectan todas las señales, se crean todos los objetos de la clases y se realizan todas las interacciones entre la aplicación.

registrarse(.h, .cpp, .ui):
    Clase QDialog que permite a un usuario registrarse por primera vez al iniciar la aplicación.

usuario(.h, .cpp):
    Clase normal de C++ para guardar los datos del usuario(se crea una Qlist con la clase usuario para guardar los usuarios de la base de datos antes de iniciar sesión)
