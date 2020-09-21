#include "add.h"
#include "ui_Add.h"

Add::Add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add)
{
    ui->setupUi(this);
    activity="  ";
    ui->dateEdit->setDate(QDate::currentDate());
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

Add::~Add()
{
    delete ui;
}

void Add::on_pushButton_clicked()
{
    activity=ui->lineEdit->text();
    Add::close();
}

const QString Add::getDate(){
    QString d=ui->dateEdit->date().toString("dd.MM.yyyy");
    return d;
}
