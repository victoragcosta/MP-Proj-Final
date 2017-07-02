#include "../include/mainwindow.h"
#include <QApplication>
#include <stdio.h>

#include "../include/usuarios.h"
#include "../include/product.h"
#include "../include/product_search.h"
#include "../include/avaliacao.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    if(usuarios_carregarArquivo() != USUARIOS_SUCESSO){
        exit(1);
    }

    int retorno = a.exec();

    usuarios_limpar();

    return retorno;
}
