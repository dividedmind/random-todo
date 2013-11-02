#include <QCoreApplication>
#include <QStringList>
#include <qtextstream.h>
#include "akorandom.h"

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    Akorandom::Kind kind = Akorandom::Todos;
    unsigned int count = 1;
    
    const QStringList &arguments = app.arguments();
    auto argument = arguments.begin() + 1;
    
    if (argument != arguments.end() && argument->startsWith("c")) {
      argument++;
      kind = Akorandom::Contacts;
    }
    
    if (argument != arguments.end())
      count = argument->toUInt();
    
    Akorandom foo(kind, count);
    return app.exec();
}
