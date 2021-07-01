#include "fileedit.h"
#include "ui_fileedit.h"

FileEdit::FileEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileEdit)
{
    ui->setupUi(this);
}

FileEdit::~FileEdit()
{
    delete ui;
}

void FileEdit::on_pushButtonFileEdit_clicked()
{
    QString sqlDB = QString ("INSERT INTO user(IdFile, Name, Size(kb), Location, IdUser) VALUES('%1', '%2' , '%3', '%4', '%5')")
                                    .arg(ui->lineEditIdFileEdit->text(), ui->lineEditNameEdit->text(), ui->lineEditSizeEdit->text(), ui->lineEditLocationEdit->text(), ui->lineEditOwnerEdit->text());
            //окно сохранения файла
            QString fileName = QString("FileEDIT.sql");
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

                ui->lineEditIdFileEdit->clear();
                ui->lineEditNameEdit->clear();
                ui->lineEditSizeEdit->clear();
                ui->lineEditLocationEdit->clear();
                ui->lineEditOwnerEdit->clear();

}
