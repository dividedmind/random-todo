#include "akorandom.h"
#include "akonadi/recursiveitemfetchjob.h"
#include <akonadi/collection.h>
#include <akonadi/itemfetchscope.h>
#include <kcalcore/todo.h>
#include <kabc/addressee.h>
#include <QStringList>
#include <QCoreApplication>
#include <ctime>

Akorandom::Akorandom(Akorandom::Kind _kind, unsigned int _count) : kind(_kind), count(_count)
{
  qsrand(time(nullptr));
  
  QStringList mimetypes;
  
  switch(kind) {
    case Todos:
      mimetypes = {"application/x-vnd.akonadi.calendar.todo"};
      break;
    case Contacts:
      mimetypes = {"text/directory"};
  };
  
  Akonadi::ItemFetchScope scope;
  scope.fetchFullPayload(true);
  
  job = new Akonadi::RecursiveItemFetchJob(Akonadi::Collection::root(), mimetypes, this);
  job->setFetchScope(scope);
  
  connect(job, SIGNAL(finished(KJob*)), this, SLOT(finished()));
  job->start();
}

void Akorandom::finished()
{
  QTextStream qout(stdout);
  qout.setCodec("UTF-8");
  
  if (job->items().empty())
    qout << "no items found" << endl;
  else {
    Akonadi::Item::List items = job->items();
    std::random_shuffle(items.begin(), items.end());
    auto item = items.begin();
    
    for (unsigned int i = 0; i < count; ++i)
      switch (kind) {
        case Todos: {
          auto todo = (item++)->payload<KCalCore::Todo::Ptr>();
          qout << todo->summary() << endl;
          break;
        }
        case Contacts: {
          auto contact = (item++)->payload<KABC::Addressee>();
          qout << contact.realName() << endl;
          break;
        }
      }
  }
  
  QCoreApplication::exit();
}


Akorandom::~Akorandom()
{}

#include "akorandom.moc"
