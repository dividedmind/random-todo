#ifndef random_todoTEST_H
#define random_todoTEST_H

#include <QtCore/QObject>

class random_todoTest : public QObject
{
Q_OBJECT
private slots:
    void initTestCase();
    void init();
    void cleanup();
    void cleanupTestCase();

    void someTest();
};

#endif // random_todoTEST_H
