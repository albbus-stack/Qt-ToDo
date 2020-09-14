#ifndef SUBJECT_H
#define SUBJECT_H

#include"observer.h"

class Subject{
public:
    virtual ~Subject(){}
    virtual void notify()=0;
    virtual void addObserver(Observer* o)=0;
    virtual void removeObserver(Observer* o)=0;
};

#endif // SUBJECT_H
