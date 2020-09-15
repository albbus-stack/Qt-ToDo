#ifndef ITEM_H
#define ITEM_H

#include<QString>
#include<QDate>

class Item{
public:
    explicit Item(QString t, QString dL, bool d=false):task(t),deadLine(dL),done(d){}

    QString getTask() const{
        return task;
    }

    bool getDone() const{
        return done;
    }

    QString getDate()const{
        return deadLine;
    }

    void setTask(const QString t){
        task=t;
    }

    void setDone(const bool d){
        done=d;
    }

private:
    QString task;

    QString deadLine;

    bool done;
};

#endif // ITEM_H
