#ifndef random_todo_H
#define random_todo_H

#include <QtCore/QObject>

namespace Akonadi {
class RecursiveItemFetchJob;
}

class random_todo : public QObject
{
Q_OBJECT
    Akonadi::RecursiveItemFetchJob* job;
public:
    random_todo();
    virtual ~random_todo();

private slots:
    void finished();
};

#endif // random_todo_H
