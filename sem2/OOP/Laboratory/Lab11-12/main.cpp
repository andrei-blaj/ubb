#include "ui.h"
#include <QApplication>

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

#include "repository.h"
#include "controller.h"
#include "dog.h"

#include "admin.h"
#include "user.h"

int main(int argc, char *argv[])
{
    QApplication prog(argc, argv);

    std::string filename = "/Users/blaj/UNI/SEM 2/OOP/Laboratory/Lab11-12/load.txt";

    UI ui;
    ui.show();

    return prog.exec();
}
