#ifndef akorandom_H
#define akorandom_H

#include <QtCore/QObject>

namespace Akonadi {
  class RecursiveItemFetchJob;
}

class Akorandom : public QObject
{
Q_OBJECT
public:
    enum Kind {
      Todos
    };

    Akorandom(Kind kind = Todos);
    virtual ~Akorandom();
    
private slots:
    void finished();
    
private:
    Akonadi::RecursiveItemFetchJob* job;
};

#endif // random_todo_H
