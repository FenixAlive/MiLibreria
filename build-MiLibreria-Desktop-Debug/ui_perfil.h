/********************************************************************************
** Form generated from reading UI file 'perfil.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERFIL_H
#define UI_PERFIL_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Perfil
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *perfilLabel;
    QLabel *usuarioLabel;
    QLineEdit *usuarioInputPerfil;
    QLabel *nombreLabel;
    QLineEdit *nombreInputPerfil;
    QLabel *fechaLabel;
    QDateEdit *fechaInputPerfil;
    QLabel *contrasenaLabel;
    QLineEdit *contrasenaInputPerfil;
    QLabel *correoLabel;
    QLineEdit *correoInputPerfil;
    QSpacerItem *horizontalSpacer;
    QPushButton *guardarBotonPerfil;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *cancelarBotonPerfil;

    void setupUi(QDialog *Perfil)
    {
        if (Perfil->objectName().isEmpty())
            Perfil->setObjectName(QStringLiteral("Perfil"));
        Perfil->resize(270, 485);
        QFont font;
        font.setFamily(QStringLiteral("Droid Sans"));
        font.setPointSize(9);
        Perfil->setFont(font);
        Perfil->setWindowOpacity(0.97);
        Perfil->setStyleSheet(QLatin1String("background-color: #333;\n"
"color: #f1f1f1;"));
        verticalLayout = new QVBoxLayout(Perfil);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        perfilLabel = new QLabel(Perfil);
        perfilLabel->setObjectName(QStringLiteral("perfilLabel"));
        QFont font1;
        font1.setPointSize(13);
        perfilLabel->setFont(font1);
        perfilLabel->setStyleSheet(QStringLiteral(""));
        perfilLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(perfilLabel);

        usuarioLabel = new QLabel(Perfil);
        usuarioLabel->setObjectName(QStringLiteral("usuarioLabel"));

        verticalLayout->addWidget(usuarioLabel);

        usuarioInputPerfil = new QLineEdit(Perfil);
        usuarioInputPerfil->setObjectName(QStringLiteral("usuarioInputPerfil"));
        usuarioInputPerfil->setStyleSheet(QLatin1String("background-color: #535353;\n"
"color:#f1f1f1;"));
        usuarioInputPerfil->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(usuarioInputPerfil);

        nombreLabel = new QLabel(Perfil);
        nombreLabel->setObjectName(QStringLiteral("nombreLabel"));

        verticalLayout->addWidget(nombreLabel);

        nombreInputPerfil = new QLineEdit(Perfil);
        nombreInputPerfil->setObjectName(QStringLiteral("nombreInputPerfil"));
        nombreInputPerfil->setStyleSheet(QLatin1String("background-color: #535353;\n"
"color:#f1f1f1;"));
        nombreInputPerfil->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(nombreInputPerfil);

        fechaLabel = new QLabel(Perfil);
        fechaLabel->setObjectName(QStringLiteral("fechaLabel"));

        verticalLayout->addWidget(fechaLabel);

        fechaInputPerfil = new QDateEdit(Perfil);
        fechaInputPerfil->setObjectName(QStringLiteral("fechaInputPerfil"));
        fechaInputPerfil->setStyleSheet(QLatin1String("background-color: #535353;\n"
"color: #f1f1f1;"));
        fechaInputPerfil->setAlignment(Qt::AlignCenter);
        fechaInputPerfil->setDate(QDate(2018, 1, 1));

        verticalLayout->addWidget(fechaInputPerfil);

        contrasenaLabel = new QLabel(Perfil);
        contrasenaLabel->setObjectName(QStringLiteral("contrasenaLabel"));

        verticalLayout->addWidget(contrasenaLabel);

        contrasenaInputPerfil = new QLineEdit(Perfil);
        contrasenaInputPerfil->setObjectName(QStringLiteral("contrasenaInputPerfil"));
        contrasenaInputPerfil->setStyleSheet(QLatin1String("background-color: #535353;\n"
"color:#f1f1f1;"));
        contrasenaInputPerfil->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        contrasenaInputPerfil->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(contrasenaInputPerfil);

        correoLabel = new QLabel(Perfil);
        correoLabel->setObjectName(QStringLiteral("correoLabel"));

        verticalLayout->addWidget(correoLabel);

        correoInputPerfil = new QLineEdit(Perfil);
        correoInputPerfil->setObjectName(QStringLiteral("correoInputPerfil"));
        correoInputPerfil->setStyleSheet(QLatin1String("background-color: #535353;\n"
"color:#f1f1f1;"));
        correoInputPerfil->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(correoInputPerfil);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        guardarBotonPerfil = new QPushButton(Perfil);
        guardarBotonPerfil->setObjectName(QStringLiteral("guardarBotonPerfil"));
        QFont font2;
        font2.setFamily(QStringLiteral("Droid Sans"));
        font2.setBold(true);
        font2.setWeight(75);
        guardarBotonPerfil->setFont(font2);
        guardarBotonPerfil->setStyleSheet(QLatin1String("background-color:#999;\n"
"color:#333;"));

        verticalLayout->addWidget(guardarBotonPerfil);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        cancelarBotonPerfil = new QPushButton(Perfil);
        cancelarBotonPerfil->setObjectName(QStringLiteral("cancelarBotonPerfil"));
        cancelarBotonPerfil->setFont(font2);
        cancelarBotonPerfil->setStyleSheet(QLatin1String("background-color:#999;\n"
"color:#333;"));

        verticalLayout->addWidget(cancelarBotonPerfil);

#ifndef QT_NO_SHORTCUT
        usuarioLabel->setBuddy(usuarioInputPerfil);
        nombreLabel->setBuddy(usuarioInputPerfil);
        fechaLabel->setBuddy(usuarioInputPerfil);
        contrasenaLabel->setBuddy(usuarioInputPerfil);
        correoLabel->setBuddy(usuarioInputPerfil);
#endif // QT_NO_SHORTCUT

        retranslateUi(Perfil);
        QObject::connect(cancelarBotonPerfil, SIGNAL(clicked()), Perfil, SLOT(close()));

        QMetaObject::connectSlotsByName(Perfil);
    } // setupUi

    void retranslateUi(QDialog *Perfil)
    {
        Perfil->setWindowTitle(QApplication::translate("Perfil", "Mi Libreria", nullptr));
        perfilLabel->setText(QApplication::translate("Perfil", "Perfil", nullptr));
        usuarioLabel->setText(QApplication::translate("Perfil", "Usuario", nullptr));
        usuarioInputPerfil->setPlaceholderText(QApplication::translate("Perfil", "Usuario", nullptr));
        nombreLabel->setText(QApplication::translate("Perfil", "Nombre Completo", nullptr));
        nombreInputPerfil->setPlaceholderText(QApplication::translate("Perfil", "Nombre Completo", nullptr));
        fechaLabel->setText(QApplication::translate("Perfil", "Fecha Nacimiento", nullptr));
        contrasenaLabel->setText(QApplication::translate("Perfil", "Contrase\303\261a", nullptr));
        contrasenaInputPerfil->setPlaceholderText(QApplication::translate("Perfil", "Contrase\303\261a", nullptr));
        correoLabel->setText(QApplication::translate("Perfil", "Correo", nullptr));
        correoInputPerfil->setPlaceholderText(QApplication::translate("Perfil", "Correo", nullptr));
        guardarBotonPerfil->setText(QApplication::translate("Perfil", "Guardar Cambios", nullptr));
        cancelarBotonPerfil->setText(QApplication::translate("Perfil", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Perfil: public Ui_Perfil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERFIL_H
