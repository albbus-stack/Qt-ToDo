#ifndef LIST_H
#define LIST_H

#include<iostream>
#include"subject.h"
#include"QList"
#include"item.h"
#include"QDate"
#include"QFile"
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

    void addItem(Item a){
        li.push_back(a);
        saveList();
        notify();
    }

    void pushBack(Item a){
        li.push_back(a);
    }

    void removeItem(Item a){
        int c = 0;
        bool e = false;
        for(auto i : li) {
            if(i.getTask()==a.getTask() && i.getDate()==a.getDate()){
                li.removeAt(c);
                e = true;
            }
            c++;
        }
        if(e){
            saveList();
            notify();
        }
        else{
            std::cerr << "element to be removed not found" << std::endl;
        }
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

    int getUndoneElements()const{
        int c = 0;
        for (auto i : li){
            if(!i.getDone()){
                c++;
            }
        }
        return c;
    }

    void saveList(QString name = "./list.txt");

    void loadList(QString name = "./list.txt");

    QList<Item> getList();

    QList<Item> search(QString d);

private:
    QList<Item> li;

    QList<Observer*> observers;
};

#endif // LIST_H
