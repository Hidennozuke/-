#ifndef USEREDIT_H
#define USEREDIT_H

#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class UserEdit;
}

class UserEdit : public QWidget
{
    Q_OBJECT

public:
    explicit UserEdit(QWidget *parent = nullptr);
    ~UserEdit();

private slots:
    void on_pushButtonUserEdit_clicked();

private:
    Ui::UserEdit *ui;
    QLineEdit *lineEditIdUserEdit;
    QLineEdit *lineEditFirstNameEdit;
    QLineEdit *lineEditLastNameEdit;
    QLineEdit *lineEditNumberPhoneEdit;
    QPushButton *pushButtonUserEdit;
};

#endif // USEREDIT_H
