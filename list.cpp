#include "list.h"
#include"stdio.h"

void List::saveList(QString name){
    QString filename=name;
    QFile file(filename);
    if(file.open(QIODevice::WriteOnly| QIODevice::Text)){
        for(auto i : li){
            QTextStream memo(&file);
            if(i.getDone())
                memo<<"1,  ";
            else
                memo<<"0,  ";
            memo<<i.getTask()<<",  "<<i.getDate()<<"\n";
        }
    file.close();
    }
}

void List::loadList(QString name){
    QString filename=name;
    QFile file(filename);
    QTextStream memo(&file);
    li.clear();
    if(file.open(QIODevice::ReadOnly| QIODevice::Text)){
        while(!memo.atEnd()){
            QString line=memo.readLine();
            QString t=line.split(",  ").at(1);
            QString dL=line.split(",  ").at(2);
            QString d=line.split(",  ").first();
            bool done;
            if(d=="1")
                done=true;
            else if(d=="0")
                done=false;
            Item currentItem=Item(t,dL,done);
            li.push_back(currentItem);
            notify();
        }
    }
}

QList<Item> List::search(QString d){
    QList<Item> sList;
    for(auto i : li){
        QString simplifiedDate = i.getDate().simplified().remove(" ");
        if(simplifiedDate==d)
            sList.push_back(i);
    }
    return sList;
}

QList<Item> List::getList(){
    QList<Item> l;
    for(auto i : li){
        l.push_back(i);
    }
    return l;
}
