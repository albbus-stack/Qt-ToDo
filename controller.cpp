#include "controller.h"
#include"item.h"

void Controller::write(QString t, QString d,bool cS){
    Item* i=new Item(t,d,cS);
    list->addItem(i);
}

void Controller::clear(){
    list->deleteAll();
    list->saveList();
}

QList<Item*> Controller::search(QString d){
    QList<Item*> srcList=list->search(d);
    return srcList;
}

void Controller::save(QString t,QString d,bool cS){
    Item* a=new Item(t,d,cS);
    list->pushBack(a);
    list->saveList();
}
