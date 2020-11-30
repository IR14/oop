#include <iostream>
#include "mainwindow.h"
#include "ingredient.h"
#include "recipe.h"
#include <string>
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
