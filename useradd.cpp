#include "useradd.h"
#include "ui_useradd.h"

UserAdd::UserAdd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserAdd)
{
    ui->setupUi(this);
}

UserAdd::~UserAdd()
{
    delete ui;
}

void UserAdd::on_pushButtonUserAdd_clicked()
{
    QString sqlDB = QString ("INSERT INTO user(FirstName, LastName, NumberPhone) VALUES('%1', '%2' , '%3')")
                                    .arg(ui->lineEditFirstNameAdd->text(), ui->lineEditLastNameAdd->text(), ui->lineEditNumberPhoneAdd->text());
            //окно сохранения файла
            QString fileName = QString("UserADD.sql");
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

                ui->lineEditFirstNameAdd->clear();
                ui->lineEditLastNameAdd->clear();
                ui->lineEditNumberPhoneAdd->clear();
}

