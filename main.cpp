#include <QCoreApplication>
#include "random-todo.h"


int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    random_todo foo;
    return app.exec();
}
