#include "window.h"
#include "ui_window.h"
#include"QStringList"
#include"item.h"
#include<QMessageBox>
#include"add.h"
#include"edit.h"
#include"calendar.h"
#include<QDate>

MainWindow::MainWindow(class List* l,Controller* c,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    List=l;
    List->addObserver(this);
    controller=c;
    ui->setupUi(this);
    List->loadList();
}

MainWindow::~MainWindow()
{
    List->removeObserver(this);
    delete ui;
}

void MainWindow::update(){
    ui->listWidget->clear();
    QListWidgetItem* item;
    QList<Item*> list=List->getList();
    QString t,d;
    bool cS;
    for(auto itr=list.begin();itr!=list.end();itr++){
        t=(*itr)->getTask();
        d=(*itr)->getDate();
        cS=(*itr)->getDone();
        item=new QListWidgetItem(t+"\n"+d,ui->listWidget);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        if(cS)
            item->setCheckState(Qt::Checked);
        else
            item->setCheckState(Qt::Unchecked);
    }
}


void MainWindow::on_actionsave_triggered()
{
    List->clearList();
    if(ui->listWidget->count()!=0){
        for(int row=0;row<ui->listWidget->count();row++){
            QListWidgetItem* item=ui->listWidget->item(row);
            bool cS;
            if(item->checkState()==Qt::Checked)
                cS=true;
            else
                cS=false;
            QString task=item->text().split("\n").at(0);
            QString date=item->text().split("\n").at(1);
            controller->save(task,date,cS);
        }
    }
    else{
        controller->clear();
    }
}

void MainWindow::on_actiondelete_lit_triggered()
{
    controller->clear();
}

void MainWindow::on_actionsave_and_exit_triggered()
{
    on_actionsave_triggered();
    QApplication::quit();
}

void MainWindow::on_actiondelete_selected_triggered()
{
    QList<QListWidgetItem*> items = ui->listWidget->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        delete ui->listWidget->takeItem(ui->listWidget->row(item));
    }
    on_actionsave_triggered();
}


void MainWindow::on_actionundo_triggered()
{
    update();
    ui->label_2->setText("");
}

void MainWindow::on_actionsearch_triggered()
{
    auto l = new class List;
    Controller* c=new Controller(l);

    Calendar cDialog(l,c);
    cDialog.setModal(true);
    cDialog.exec();
    QDate selDate=cDialog.getSelDate();
    QList<Item*> srcList=controller->search(selDate.toString("dd.MM.yyyy"));
    QListWidgetItem* item;
    ui->listWidget->clear();
    QString t;
    QString d;
    bool cS;
    for(auto itr=srcList.begin();itr!=srcList.end();itr++){
        t=(*itr)->getTask();
        d=(*itr)->getDate();
        cS=(*itr)->getDone();
        item=new QListWidgetItem(t+"\n"+d,ui->listWidget);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        if(cS)
            item->setCheckState(Qt::Checked);
        else
            item->setCheckState((Qt::Unchecked));
    }
    ui->label_2->setText("Activities for "+selDate.toString("dd.MM.yyyy"));
}

void MainWindow::on_actionnew_triggered()
{
    Add aDialog;
    aDialog.setModal(true);
    aDialog.exec();
    if(aDialog.getItem()!="  "){
        QString t=aDialog.getItem();
        QString d=aDialog.getDate();
        bool cS=false;
        controller->write(t,d,cS);
    }
}

void MainWindow::on_listWidget_doubleClicked()
{
    Edit eDialog;
    eDialog.setModal(true);
    eDialog.setItem(ui->listWidget->currentItem()->text().split("\n").at(0));
    QString dl= ui->listWidget->currentItem()->text().split("\n").at(1);
    eDialog.setDate(dl);

    QListWidgetItem* itemSelected=ui->listWidget->currentItem();
    if(ui->listWidget->isItemSelected(itemSelected)){
        eDialog.exec();
        if(eDialog.getButtonClicked()){
            QString t=eDialog.getItem();
            QString d=eDialog.getDate();
            itemSelected->setText(t+"\n"+d);
            on_actionsave_triggered();
        }
    }
    else{
        ui->label->setText("Select an Item to edit!");
    }
}
