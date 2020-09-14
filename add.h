#ifndef ADD_H
#define ADD_H

#include <QDialog>

namespace Ui {
class Add;
}

class Add : public QDialog
{
    Q_OBJECT

public:
    explicit Add(QWidget *parent = 0);

    ~Add();

    const QString getItem(){
        return activity;
    }

    const QString getDate();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Add *ui;

    QString activity;
};

#endif // ADD_H
