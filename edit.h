#ifndef EDIT_H
#define EDIT_H

#include <QDialog>
#include<QDate>

namespace Ui {
class Edit;
}

class Edit : public QDialog
{
    Q_OBJECT

public:
    explicit Edit(QWidget *parent = 0);

    ~Edit();

    const QString getItem();

    const QString getDate();

    bool getButtonClicked();

    void setItem(const QString& a);

    void setDate(const QString& d);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Edit *ui;

    QString Item;

    QString deadLine;

    bool buttonClicked;
};

#endif // EDIT_H
