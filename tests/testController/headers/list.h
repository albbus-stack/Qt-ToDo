#ifndef LIST_H
#define LIST_H

#include"subject.h"
#include"QList"
#include"item.h"
#include"QDate"
#include "QFile"
#include"QIODevice"
#include"QTextStream"

class List: public Subject{

public:
    List(){}

    virtual void addObserver(Observer *o){
        observers.push_back(o);
    }

    virtual void removeObserver(Observer *o){
        observers.removeOne(o);
    }

    virtual void notify(){
        for(Observer* observer: observers)
            observer->update();
    }

    void addItem(Item* a){
        li.push_back(a);
        saveList();
        notify();
    }

    void pushBack(Item* a){
        li.push_back(a);
    }

    void removeItem(Item* a){
        li.removeOne(a);
        saveList();
        notify();
    }

    void deleteAll(){
        li.clear();
        saveList();
        notify();
    }

    void clearList(){
        li.clear();
    }

    int getElements()const{
        return li.count();
    }

    void saveList(QString name = "./list.txt");

    void loadList(QString name = "./list.txt");

    QList<Item*> getList();

    QList<Item*> search(QString d);

private:
    QList<Item*> li;

    QList<Observer*> observers;
};

#endif // LIST_H
