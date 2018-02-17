/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionFavoritos;
    QAction *actionPerfil;
    QAction *actionSalir;
    QAction *actionTodos;
    QAction *actionMis_Libros;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *Buscador;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QMenuBar *menuBar;
    QMenu *menuInicio;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(500, 300);
        MainWindow->setStyleSheet(QLatin1String("background-color: #333;\n"
"color: white;"));
        actionFavoritos = new QAction(MainWindow);
        actionFavoritos->setObjectName(QStringLiteral("actionFavoritos"));
        actionPerfil = new QAction(MainWindow);
        actionPerfil->setObjectName(QStringLiteral("actionPerfil"));
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        actionTodos = new QAction(MainWindow);
        actionTodos->setObjectName(QStringLiteral("actionTodos"));
        actionMis_Libros = new QAction(MainWindow);
        actionMis_Libros->setObjectName(QStringLiteral("actionMis_Libros"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Buscador = new QLineEdit(centralWidget);
        Buscador->setObjectName(QStringLiteral("Buscador"));
        Buscador->setStyleSheet(QLatin1String("border-radius: 13px;\n"
"color: #f1f1f1;\n"
"background-color:#535353;"));
        Buscador->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(Buscador);

        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setStyleSheet(QStringLiteral("background-color: #f3f3f3;"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 480, 185));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 500, 20));
        menuInicio = new QMenu(menuBar);
        menuInicio->setObjectName(QStringLiteral("menuInicio"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuInicio->menuAction());
        menuInicio->addSeparator();
        menuInicio->addAction(actionTodos);
        menuInicio->addAction(actionMis_Libros);
        menuInicio->addAction(actionFavoritos);
        menuInicio->addAction(actionPerfil);
        menuInicio->addSeparator();
        menuInicio->addAction(actionSalir);
        mainToolBar->addAction(actionTodos);
        mainToolBar->addAction(actionMis_Libros);
        mainToolBar->addAction(actionFavoritos);
        mainToolBar->addAction(actionPerfil);
        mainToolBar->addAction(actionSalir);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Mi Libreria", nullptr));
        actionFavoritos->setText(QApplication::translate("MainWindow", "Favoritos", nullptr));
        actionPerfil->setText(QApplication::translate("MainWindow", "Perfil", nullptr));
        actionSalir->setText(QApplication::translate("MainWindow", "Salir", nullptr));
        actionTodos->setText(QApplication::translate("MainWindow", "Todos", nullptr));
        actionMis_Libros->setText(QApplication::translate("MainWindow", "Mis Libros", nullptr));
        Buscador->setPlaceholderText(QApplication::translate("MainWindow", "Buscar ...", nullptr));
        menuInicio->setTitle(QApplication::translate("MainWindow", "Inicio", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
