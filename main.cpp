#include <QCoreApplication>
#include <QStringList>
#include <qtextstream.h>
#include "akorandom.h"

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    Akorandom::Kind kind = Akorandom::Todos;
    
    const QStringList &arguments = app.arguments();
    
    if (arguments.count() > 1 && arguments.at(1).startsWith("c"))
      kind = Akorandom::Contacts;
    
    Akorandom foo(kind);
    return app.exec();
}
