#include <QString>
#include <QObject>
#include <QtTest>
#include <item.h>

class TestItem: public QObject
{
    Q_OBJECT

public:
    TestItem();

private Q_SLOTS:
    void Constructor();

    void SetTask();

    void SetDone();
};

TestItem::TestItem(){
}

void TestItem::Constructor(){
    QString String="test";
    QString Date=QDate::currentDate().toString("dd.MM.yyyy");
    bool Done=true;
    Item i(String,Date,Done);
    QVERIFY2(i.getTask()==String, "the name of the task doesn't match");
    QVERIFY2(i.getDate()==Date,"date doesn't match");
    QVERIFY2(i.getDone()==Done,"checkstate doesn't match");
}

void TestItem::SetTask(){
    Item it("a",QDate::currentDate().toString("dd.MM.yyyy"),false);
    QString String="test";
    it.setTask(String);
    QVERIFY2(it.getTask()==String,"setTask doesn't work!");
}

void TestItem::SetDone(){
    Item item("a",QDate::currentDate().toString("dd.MM.yyyy"),false);
    item.setDone(true);
    QVERIFY2(item.getDone()==true,"setDone doesn't work!");
}

QTEST_APPLESS_MAIN(TestItem)
#include "tst_testitem.moc"
