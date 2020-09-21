#ifndef CONTROLLER_H
#define CONTROLLER_H

#include"list.h"
#include"QString"
#include"item.h"

class Controller
{
public:
    Controller(List* l):list(l){}
    
    void write(QString t,QString d,bool cS);
    
    void clear();
    
    QList<Item*> search(QString d);
    
    void save(QString t,QString d,bool cS);
    
private:
    List* list;
};

#endif // CONTROLLER_H
