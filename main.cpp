#include <QCoreApplication>
#include "akorandom.h"

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    Akorandom foo;
    return app.exec();
}
