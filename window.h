#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"observer.h"
#include"list.h"
#include"controller.h"
#include"QDate"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    explicit MainWindow(List* l,Controller* c,QWidget *parent = 0);
    ~MainWindow();

    virtual void update();

private slots:

    void on_actionsave_triggered();

    void on_actiondelete_lit_triggered();

    void on_actionsave_and_exit_triggered();

    void on_actiondelete_selected_triggered();

    void on_actionundo_triggered();

    void on_actionsearch_triggered();

    void on_actionnew_triggered();

    void on_listWidget_doubleClicked();

private:
    Ui::MainWindow *ui;

    List* List;

    Controller* controller;
};

#endif // MAINWINDOW_H
