/********************************************************************************
** Form generated from reading UI file 'iniciar.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INICIAR_H
#define UI_INICIAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Iniciar
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *iniciarLabel;
    QLabel *usuarioLabel;
    QLineEdit *usuarioInput;
    QLabel *contrasenaLabel;
    QLineEdit *contrasenaInput;
    QSpacerItem *horizontalSpacer;
    QPushButton *iniciarBoton;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *registrarmeBoton;

    void setupUi(QDialog *Iniciar)
    {
        if (Iniciar->objectName().isEmpty())
            Iniciar->setObjectName(QStringLiteral("Iniciar"));
        Iniciar->resize(270, 323);
        Iniciar->setWindowOpacity(0.97);
        Iniciar->setStyleSheet(QLatin1String("background-color: #333;\n"
"color: #f3f3f3;"));
        verticalLayout = new QVBoxLayout(Iniciar);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        iniciarLabel = new QLabel(Iniciar);
        iniciarLabel->setObjectName(QStringLiteral("iniciarLabel"));
        QFont font;
        font.setFamily(QStringLiteral("Droid Sans"));
        font.setPointSize(13);
        iniciarLabel->setFont(font);
        iniciarLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(iniciarLabel);

        usuarioLabel = new QLabel(Iniciar);
        usuarioLabel->setObjectName(QStringLiteral("usuarioLabel"));

        verticalLayout->addWidget(usuarioLabel);

        usuarioInput = new QLineEdit(Iniciar);
        usuarioInput->setObjectName(QStringLiteral("usuarioInput"));
        usuarioInput->setStyleSheet(QStringLiteral("background-color: #535353;"));
        usuarioInput->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(usuarioInput);

        contrasenaLabel = new QLabel(Iniciar);
        contrasenaLabel->setObjectName(QStringLiteral("contrasenaLabel"));

        verticalLayout->addWidget(contrasenaLabel);

        contrasenaInput = new QLineEdit(Iniciar);
        contrasenaInput->setObjectName(QStringLiteral("contrasenaInput"));
        contrasenaInput->setStyleSheet(QStringLiteral("background-color: #535353;"));
        contrasenaInput->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        contrasenaInput->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(contrasenaInput);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        iniciarBoton = new QPushButton(Iniciar);
        iniciarBoton->setObjectName(QStringLiteral("iniciarBoton"));
        iniciarBoton->setEnabled(true);
        QFont font1;
        font1.setFamily(QStringLiteral("Droid Sans"));
        font1.setBold(true);
        font1.setWeight(75);
        iniciarBoton->setFont(font1);
        iniciarBoton->setStyleSheet(QLatin1String("background-color: #999;\n"
"color: #535353;"));

        verticalLayout->addWidget(iniciarBoton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        line = new QFrame(Iniciar);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        label = new QLabel(Iniciar);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_3);

        registrarmeBoton = new QPushButton(Iniciar);
        registrarmeBoton->setObjectName(QStringLiteral("registrarmeBoton"));
        registrarmeBoton->setFont(font1);
        registrarmeBoton->setStyleSheet(QLatin1String("background-color: #999;\n"
"color: #535353;"));

        verticalLayout->addWidget(registrarmeBoton);

#ifndef QT_NO_SHORTCUT
        usuarioLabel->setBuddy(usuarioInput);
        contrasenaLabel->setBuddy(usuarioInput);
#endif // QT_NO_SHORTCUT

        retranslateUi(Iniciar);

        QMetaObject::connectSlotsByName(Iniciar);
    } // setupUi

    void retranslateUi(QDialog *Iniciar)
    {
        Iniciar->setWindowTitle(QApplication::translate("Iniciar", "Mi Libreria", nullptr));
        iniciarLabel->setText(QApplication::translate("Iniciar", "Iniciar Sesi\303\263n", nullptr));
        usuarioLabel->setText(QApplication::translate("Iniciar", "Usuario:", nullptr));
        usuarioInput->setPlaceholderText(QApplication::translate("Iniciar", "Usuario", nullptr));
        contrasenaLabel->setText(QApplication::translate("Iniciar", "Contrase\303\261a:", nullptr));
        contrasenaInput->setText(QString());
        contrasenaInput->setPlaceholderText(QApplication::translate("Iniciar", "Contrase\303\261a", nullptr));
        iniciarBoton->setText(QApplication::translate("Iniciar", "Iniciar", nullptr));
        label->setText(QApplication::translate("Iniciar", "\302\277Eres nuevo?", nullptr));
        registrarmeBoton->setText(QApplication::translate("Iniciar", "Registrarme", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Iniciar: public Ui_Iniciar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICIAR_H
