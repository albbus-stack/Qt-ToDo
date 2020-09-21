#include <QString>
#include <QtTest>
#include "headers/controller.h"
#include "headers/list.h"

class TestController : public QObject
{
    Q_OBJECT

public:
    TestController();

private Q_SLOTS:
    void WriteClear();

    void Search();

    void Save();
};

TestController::TestController(){
}

void TestController::WriteClear()
{
    List *l1=new List;
    Controller *c=new Controller(l1);
    c->write("text",QDate::currentDate().toString("dd.MM.yyyy"),false);
    QVERIFY2(l1->getElements()==1, "write doesn't work");
    c->clear();
    QVERIFY2(l1->getElements()==0,"clear doesn't work");
}

void TestController::Search(){
    List *l2=new List;
    Controller *c=new Controller(l2);
    c->write("to be found",QDate::currentDate().toString("dd.MM.yyyy"),false);
    QVERIFY2(c->search(QDate::currentDate().toString("dd.MM.yyyy")).count()==1,"search doesn't work proprely");
    QDate WDate=QDate::fromString("23.04.1997","dd.MM.yyyy");
    QVERIFY2(c->search(WDate.toString("dd.MM.yyyy")).count()==0,"search doesn't work proprely");
}

void TestController::Save(){
    List *l=new List;
    Controller *c=new Controller(l);
    c->save("Test", QDate::currentDate().toString("dd.MM.yyyy"),false);
    List TList;
    TList.loadList();
    QVERIFY2(TList.getElements()==1,"save doesn't work");
    c->save("test2",QDate::currentDate().toString("dd.MM.yyyy"),true);
    TList.loadList();
    QVERIFY2(TList.getElements()==2,"save doesn't iterate through the items");
}

QTEST_APPLESS_MAIN(TestController)
#include "tst_testcontroller.moc"
