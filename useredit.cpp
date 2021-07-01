#include "useredit.h"
#include "ui_useredit.h"

UserEdit::UserEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserEdit)
{
    ui->setupUi(this);
}

UserEdit::~UserEdit()
{
    delete ui;
}

void UserEdit::on_pushButtonUserEdit_clicked()
{
    QString sqlDB = QString ("INSERT INTO user(IdClient, FirstName, LastName, NumberPhone) VALUES('%1', '%2' , '%3', '%4')")
                                    .arg(ui->lineEditIdUserEdit->text(), ui->lineEditFirstNameEdit->text(), ui->lineEditFLastNameEdit->text(), ui->lineEditNumberPhoneEdit->text());
            //окно сохранения файла
            QString fileName = QString("UserEDIT.sql");
            QString fileN=
                       QFileDialog::getSaveFileName( this,
                                                     tr("Сохранить как"),
                                                     fileName,
                                                     tr("SQL(*.sql)")
                                                     );
            qint64 size=0;
            QFile file(fileN);
            if(!fileN.isEmpty() &&file.open(QIODevice::WriteOnly))

            {
                QTextStream stream(&file);
                stream << sqlDB;
                file.close();
            }

                ui->lineEditIdUserEdit->clear();
                ui->lineEditFirstNameEdit->clear();
                ui->lineEditFLastNameEdit->clear();
                ui->lineEditNumberPhoneEdit->clear();
}

