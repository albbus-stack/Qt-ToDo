#include "edit.h"
#include "ui_Edit.h"

Edit::Edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit)
{
    ui->setupUi(this);
    buttonClicked=false;
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

Edit::~Edit()
{
    delete ui;
}

const QString Edit::getItem(){
    return ui->lineEdit->text();
}

const QString Edit::getDate(){
    return ui->dateEdit->date().toString("dd.MM.yyyy");
}

void Edit::setItem(const QString &a){
    ui->lineEdit->setText(a);
}

void Edit::setDate(const QString &d){
    ui->dateEdit->setDate(QDate::fromString(d.simplified().remove(" "),"dd.MM.yyyy"));
}

void Edit::on_pushButton_clicked()
{
    buttonClicked=true;
    Edit::close();
}

bool Edit::getButtonClicked(){
    return buttonClicked;
}
