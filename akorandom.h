#ifndef akorandom_H
#define akorandom_H

#include <QtCore/QObject>

namespace Akonadi {
  class RecursiveItemFetchJob;
}

class Akorandom : public QObject
{
Q_OBJECT
    Akonadi::RecursiveItemFetchJob* job;
public:
    Akorandom();
    virtual ~Akorandom();

private slots:
    void finished();
};

#endif // random_todo_H
