#ifndef USUARIO_H
#define USUARIO_H
#include <QString>


class Usuario
{
public:
    Usuario();

    //getters and setters
    QString getNombre() const;
    void setNombre(const QString &value);

    QString getUsuario() const;
    void setUsuario(const QString &value);

    QString getContrasena() const;
    void setContrasena(const QString &value);

    QString getNacimiento() const;
    void setNacimiento(const QString &value);

    QString getCorreo() const;
    void setCorreo(const QString &value);

private: //variables que guarda un usuario
    QString nombre;
    QString usuario;
    QString contrasena;
    QString nacimiento;
    QString correo;

};

#endif // USUARIO_H
