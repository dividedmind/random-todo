#include "random-todoTest.h"
#include <QtTest/QTest>

void random_todoTest::initTestCase()
{}

void random_todoTest::init()
{}

void random_todoTest::cleanup()
{}

void random_todoTest::cleanupTestCase()
{}

void random_todoTest::someTest()
{
    QCOMPARE(1,2);
}


QTEST_MAIN(random_todoTest)
#include "random-todoTest.moc"
