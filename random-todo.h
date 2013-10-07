#ifndef random_todo_H
#define random_todo_H

#include <QtCore/QObject>

class random_todo : public QObject
{
Q_OBJECT
public:
    random_todo();
    virtual ~random_todo();
};

#endif // random_todo_H
