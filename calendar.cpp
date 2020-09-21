#include "calendar.h"
#include "ui_Calendar.h"
#include<QTextCharFormat>


Calendar::Calendar(class List *l, Controller *c, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calendar)
{
    List=l;
    List->addObserver(this);
    controller=c;
    ui->setupUi(this);
    List->loadList();
    selDate=QDate::currentDate();
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    update();
}

Calendar::~Calendar()
{
    delete ui;
}

void Calendar::update(){
    QList<Item> list=List->getList();
    QTextCharFormat dayHighlight;
    dayHighlight.setBackground(Qt::yellow);
    for (auto i : list){
        QString aDay=i.getDate();
        ui->calendarWidget->setDateTextFormat(QDate::fromString(aDay,"dd.MM.yyyy"),dayHighlight);
    }
}

void Calendar::on_calendarWidget_clicked(const QDate &date)
{
    selDate=date;
    Calendar::close();
}

QDate Calendar::getSelDate(){
    return ui->calendarWidget->selectedDate();
}
