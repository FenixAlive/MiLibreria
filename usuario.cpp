#include "usuario.h"

Usuario::Usuario()
{

}

QString Usuario::getNombre() const
{
    return nombre;
}

void Usuario::setNombre(const QString &value)
{
    nombre = value;
}

QString Usuario::getUsuario() const
{
    return usuario;
}

void Usuario::setUsuario(const QString &value)
{
    usuario = value;
}

QString Usuario::getContrasena() const
{
    return contrasena;
}

void Usuario::setContrasena(const QString &value)
{
    contrasena = value;
}


QString Usuario::getNacimiento() const
{
    return nacimiento;
}

void Usuario::setNacimiento(const QString &value)
{
    nacimiento = value;
}

QString Usuario::getCorreo() const
{
    return correo;
}

void Usuario::setCorreo(const QString &value)
{
    correo = value;
}
