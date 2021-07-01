#ifndef USERADD_H
#define USERADD_H

#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class UserAdd;
}

class UserAdd : public QWidget
{
    Q_OBJECT

public:
    explicit UserAdd(QWidget *parent = nullptr);
    ~UserAdd();

private slots:
    void on_pushButtonUserAdd_clicked();

private:
    Ui::UserAdd *ui;
    QLineEdit *lineEditFirstNameAdd;
    QLineEdit *lineEditLastNameAdd;
    QLineEdit *lineEditNumberPhoneAdd;
    QPushButton *pushButtonUserAdd;

};

#endif // USERADD_H
