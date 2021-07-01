#include "fileadd.h"
#include "ui_fileadd.h"

FileAdd::FileAdd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileAdd)
{
    ui->setupUi(this);
}

FileAdd::~FileAdd()
{
    delete ui;
}

void FileAdd::on_pushButtonFileAdd_clicked()
{
    QString sqlDB = QString ("INSERT INTO user(Name, Size(kb), Location, IdUser) VALUES('%1', '%2' , '%3', '%4')")
                                    .arg(ui->lineEditNameAdd->text(), ui->lineEditSizeAdd->text(), ui->lineEditLocationAdd->text(), ui->lineEditOwnerAdd->text());
            //окно сохранения файла
            QString fileName = QString("FileADD.sql");
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

                ui->lineEditNameAdd->clear();
                ui->lineEditSizeAdd->clear();
                ui->lineEditLocationAdd->clear();
                ui->lineEditOwnerAdd->clear();

}



