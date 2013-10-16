#include "akorandom.h"
#include "akonadi/recursiveitemfetchjob.h"
#include <akonadi/collection.h>
#include <akonadi/itemfetchscope.h>
#include <kcalcore/todo.h>
#include <QStringList>
#include <QCoreApplication>
#include <ctime>

Akorandom::Akorandom()
{
  qsrand(time(nullptr));
  
  QStringList mimetypes{"application/x-vnd.akonadi.calendar.todo"};
  Akonadi::ItemFetchScope scope;
  scope.fetchFullPayload(true);
  job = new Akonadi::RecursiveItemFetchJob(Akonadi::Collection::root(), mimetypes, this);
  job->setFetchScope(scope);
  
  connect(job, SIGNAL(finished(KJob*)), this, SLOT(finished()));
  job->start();
}

void Akorandom::finished()
{
  int index = qrand() % job->items().count();
  Akonadi::Item item = job->items()[index];
  auto todo = item.payload<KCalCore::Todo::Ptr>();
  std::cout << todo->summary().toLocal8Bit().constData() << std::endl;
  
  QCoreApplication::exit();
}


Akorandom::~Akorandom()
{}

#include "akorandom.moc"
