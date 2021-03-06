#-------------------------------------------------
#
# Project created by QtCreator 2017-07-01T15:49:53
#
#-------------------------------------------------

QT       += core gui
CONFIG   += console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MP-Proj-Final-Qt
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    ../usuarios/usuarios.cpp \
    ../usuarios/aleatorio.cpp \
    ../product_search/product_search.cpp \
    ../product/product.cpp \
    ../grafo/grafo.cpp \
    ../avaliacao/avaliacao.cpp \
    ../transaction/transaction.cpp \
    ../transaction_search/transaction_search.cpp \
    ../valid_index/valid_index.cpp \
    admin.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    productwidget.cpp \
    registrar.cpp \
    transacao.cpp \
    visualizadorproduto.cpp

HEADERS += \
    ../../include/aleatorio.h \
    ../../include/avaliacao.h \
    ../../include/error_level.h \
    ../../include/grafo.h \
    ../../include/mainwindow.h \
    ../../include/product.h \
    ../../include/product_search.h \
    ../../include/transaction.h \
    ../../include/transaction_search.h \
    ../../include/usuarios.h \
    ../../include/valid_index.h \
    ../../include/login.h \
    ../../include/productwidget.h \
    ../../include/registrar.h \
    ../../include/visualizadorproduto.h \
    ../../include/admin.h \
    ../../include/transacao.h

FORMS += \
        mainwindow.ui \
    login.ui \
    registrar.ui \
    productwidget.ui \
    visualizadorproduto.ui \
    admin.ui \
    transacao.ui

INCLUDEPATH += \
    ../../include
