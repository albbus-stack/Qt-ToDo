#ifndef CALENDAR_H
#define CALENDAR_H

#include <QDialog>
#include"observer.h"
#include"list.h"
#include"controller.h"

namespace Ui {
class Calendar;
}

class Calendar : public QDialog, public Observer
{
    Q_OBJECT

public:
    explicit Calendar(List* l,Controller* c,QWidget *parent = 0);

    ~Calendar();

    virtual void update();

    QDate getSelDate();

private slots:
    void on_calendarWidget_clicked(const QDate &date);

private:
    Ui::Calendar *ui;

    List* List;

    Controller* controller;

    QDate selDate;
};

#endif // CALENDAR_H
