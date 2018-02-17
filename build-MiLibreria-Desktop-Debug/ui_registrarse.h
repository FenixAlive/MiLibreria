/********************************************************************************
** Form generated from reading UI file 'registrarse.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRARSE_H
#define UI_REGISTRARSE_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Registrarse
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *registrarmeLabel;
    QLabel *usuarioLabel;
    QLineEdit *usuarioInputNuevo;
    QLabel *nombreLabel;
    QLineEdit *nombreInputNuevo;
    QLabel *fechaLabel;
    QDateEdit *fechaInputNuevo;
    QLabel *contrasenaLabel;
    QLineEdit *contrasenaInputNuevo;
    QLabel *correoLabel;
    QLineEdit *correoInputNuevo;
    QSpacerItem *horizontalSpacer;
    QPushButton *registrarmeBotonNuevo;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line;
    QLabel *label;
    QPushButton *iniciarBotonNuevo;

    void setupUi(QDialog *Registrarse)
    {
        if (Registrarse->objectName().isEmpty())
            Registrarse->setObjectName(QStringLiteral("Registrarse"));
        Registrarse->resize(270, 485);
        QFont font;
        font.setFamily(QStringLiteral("Droid Sans"));
        font.setPointSize(9);
        Registrarse->setFont(font);
        Registrarse->setWindowOpacity(0.97);
        Registrarse->setStyleSheet(QLatin1String("background-color: #333;\n"
"color: #f1f1f1;"));
        verticalLayout = new QVBoxLayout(Registrarse);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        registrarmeLabel = new QLabel(Registrarse);
        registrarmeLabel->setObjectName(QStringLiteral("registrarmeLabel"));
        QFont font1;
        font1.setPointSize(13);
        registrarmeLabel->setFont(font1);
        registrarmeLabel->setStyleSheet(QStringLiteral(""));
        registrarmeLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(registrarmeLabel);

        usuarioLabel = new QLabel(Registrarse);
        usuarioLabel->setObjectName(QStringLiteral("usuarioLabel"));

        verticalLayout->addWidget(usuarioLabel);

        usuarioInputNuevo = new QLineEdit(Registrarse);
        usuarioInputNuevo->setObjectName(QStringLiteral("usuarioInputNuevo"));
        usuarioInputNuevo->setStyleSheet(QLatin1String("background-color: #535353;\n"
"color:#f1f1f1;"));
        usuarioInputNuevo->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(usuarioInputNuevo);

        nombreLabel = new QLabel(Registrarse);
        nombreLabel->setObjectName(QStringLiteral("nombreLabel"));

        verticalLayout->addWidget(nombreLabel);

        nombreInputNuevo = new QLineEdit(Registrarse);
        nombreInputNuevo->setObjectName(QStringLiteral("nombreInputNuevo"));
        nombreInputNuevo->setStyleSheet(QLatin1String("background-color: #535353;\n"
"color:#f1f1f1;"));
        nombreInputNuevo->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(nombreInputNuevo);

        fechaLabel = new QLabel(Registrarse);
        fechaLabel->setObjectName(QStringLiteral("fechaLabel"));

        verticalLayout->addWidget(fechaLabel);

        fechaInputNuevo = new QDateEdit(Registrarse);
        fechaInputNuevo->setObjectName(QStringLiteral("fechaInputNuevo"));
        fechaInputNuevo->setStyleSheet(QLatin1String("background-color: #535353;\n"
"color: #f1f1f1;"));
        fechaInputNuevo->setAlignment(Qt::AlignCenter);
        fechaInputNuevo->setDate(QDate(2018, 1, 1));

        verticalLayout->addWidget(fechaInputNuevo);

        contrasenaLabel = new QLabel(Registrarse);
        contrasenaLabel->setObjectName(QStringLiteral("contrasenaLabel"));

        verticalLayout->addWidget(contrasenaLabel);

        contrasenaInputNuevo = new QLineEdit(Registrarse);
        contrasenaInputNuevo->setObjectName(QStringLiteral("contrasenaInputNuevo"));
        contrasenaInputNuevo->setStyleSheet(QLatin1String("background-color: #535353;\n"
"color:#f1f1f1;"));
        contrasenaInputNuevo->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        contrasenaInputNuevo->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(contrasenaInputNuevo);

        correoLabel = new QLabel(Registrarse);
        correoLabel->setObjectName(QStringLiteral("correoLabel"));

        verticalLayout->addWidget(correoLabel);

        correoInputNuevo = new QLineEdit(Registrarse);
        correoInputNuevo->setObjectName(QStringLiteral("correoInputNuevo"));
        correoInputNuevo->setStyleSheet(QLatin1String("background-color: #535353;\n"
"color:#f1f1f1;"));
        correoInputNuevo->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(correoInputNuevo);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        registrarmeBotonNuevo = new QPushButton(Registrarse);
        registrarmeBotonNuevo->setObjectName(QStringLiteral("registrarmeBotonNuevo"));
        registrarmeBotonNuevo->setEnabled(true);
        QPalette palette;
        QBrush brush(QColor(51, 51, 51, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(153, 153, 153, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(231, 231, 231, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        registrarmeBotonNuevo->setPalette(palette);
        QFont font2;
        font2.setFamily(QStringLiteral("Droid Sans"));
        font2.setBold(true);
        font2.setWeight(75);
        registrarmeBotonNuevo->setFont(font2);
        registrarmeBotonNuevo->setStyleSheet(QLatin1String("background-color:#999;\n"
"color:#333;"));
        registrarmeBotonNuevo->setFlat(false);

        verticalLayout->addWidget(registrarmeBotonNuevo);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        line = new QFrame(Registrarse);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        label = new QLabel(Registrarse);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        iniciarBotonNuevo = new QPushButton(Registrarse);
        iniciarBotonNuevo->setObjectName(QStringLiteral("iniciarBotonNuevo"));
        iniciarBotonNuevo->setFont(font2);
        iniciarBotonNuevo->setStyleSheet(QLatin1String("background-color:#999;\n"
"color:#333;"));

        verticalLayout->addWidget(iniciarBotonNuevo);

#ifndef QT_NO_SHORTCUT
        usuarioLabel->setBuddy(usuarioInputNuevo);
        nombreLabel->setBuddy(usuarioInputNuevo);
        fechaLabel->setBuddy(usuarioInputNuevo);
        contrasenaLabel->setBuddy(usuarioInputNuevo);
        correoLabel->setBuddy(usuarioInputNuevo);
#endif // QT_NO_SHORTCUT

        retranslateUi(Registrarse);

        registrarmeBotonNuevo->setDefault(false);


        QMetaObject::connectSlotsByName(Registrarse);
    } // setupUi

    void retranslateUi(QDialog *Registrarse)
    {
        Registrarse->setWindowTitle(QApplication::translate("Registrarse", "Mi Libreria", nullptr));
        registrarmeLabel->setText(QApplication::translate("Registrarse", "Registrarme", nullptr));
        usuarioLabel->setText(QApplication::translate("Registrarse", "Usuario", nullptr));
        usuarioInputNuevo->setPlaceholderText(QApplication::translate("Registrarse", "Usuario", nullptr));
        nombreLabel->setText(QApplication::translate("Registrarse", "Nombre Completo", nullptr));
        nombreInputNuevo->setPlaceholderText(QApplication::translate("Registrarse", "Nombre Completo", nullptr));
        fechaLabel->setText(QApplication::translate("Registrarse", "Fecha Nacimiento", nullptr));
        contrasenaLabel->setText(QApplication::translate("Registrarse", "Contrase\303\261a", nullptr));
        contrasenaInputNuevo->setPlaceholderText(QApplication::translate("Registrarse", "Contrase\303\261a", nullptr));
        correoLabel->setText(QApplication::translate("Registrarse", "Correo", nullptr));
        correoInputNuevo->setPlaceholderText(QApplication::translate("Registrarse", "Correo", nullptr));
        registrarmeBotonNuevo->setText(QApplication::translate("Registrarse", "Registrarme", nullptr));
        label->setText(QApplication::translate("Registrarse", "Ya tienes cuenta?", nullptr));
        iniciarBotonNuevo->setText(QApplication::translate("Registrarse", "Iniciar Sesi\303\263n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Registrarse: public Ui_Registrarse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRARSE_H
