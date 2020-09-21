#include "headers/list.h"
#include"stdio.h"

void List::saveList(QString name){
    QString filename=name;
    QFile file(filename);
    if(file.open(QIODevice::WriteOnly| QIODevice::Text)){
        for(auto itr=li.begin();itr!=li.end();itr++){
            QTextStream memo(&file);
            if((*itr)->getDone())
                memo<<"1,  ";
            else
                memo<<"0,  ";
            memo<<(*itr)->getTask()<<",  "<<(*itr)->getDate()<<"\n";
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
            Item* currentItem=new Item(t,dL,done);
            li.push_back(currentItem);
            notify();
        }
    }
}

QList<Item*> List::search(QString d){
    QList<Item*> sList;
    for(auto itr=li.begin();itr!=li.end();itr++){
        QString simplifiedDate = (*itr)->getDate().simplified().remove(" ");
        if(simplifiedDate==d)
            sList.push_back((*itr));
    }
    return sList;
}

QList<Item*> List::getList(){
    QList<Item*> l;
    for(auto itr=li.begin();itr!=li.end();itr++){
        l.push_back((*itr));
    }
    return l;
}
