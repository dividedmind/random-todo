#include "random-todo.h"
#include "akonadi/recursiveitemfetchjob.h"
#include <akonadi/collection.h>
#include <akonadi/itemfetchscope.h>
#include <kcalcore/todo.h>
#include <QStringList>
#include <QCoreApplication>

random_todo::random_todo()
{
  QStringList mimetypes{"application/x-vnd.akonadi.calendar.todo"};
  Akonadi::ItemFetchScope scope;
  scope.fetchFullPayload(true);
  job = new Akonadi::RecursiveItemFetchJob(Akonadi::Collection::root(), mimetypes, this);
  job->setFetchScope(scope);
  
  connect(job, SIGNAL(finished(KJob*)), this, SLOT(finished()));
  job->start();
}

void random_todo::finished()
{
  int index = qrand() * job->items().count() / RAND_MAX;
  Akonadi::Item item = job->items()[index];
  auto todo = item.payload<KCalCore::Todo::Ptr>();
  std::cout << todo->summary().toLocal8Bit().constData() << std::endl;
  
  QCoreApplication::exit();
}


random_todo::~random_todo()
{}

#include "random-todo.moc"
