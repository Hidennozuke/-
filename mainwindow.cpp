#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent),


      ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
        QSqlQuery *query = new QSqlQuery();
        query->exec("SELECT table_name FROM information_schema.tables  where table_schema='public'");
        while (query->next())
        {
          ui->comboBox->addItem(query->value(0).toString());
        }
    }

MainWindow::~MainWindow()
    {
        delete ui;
    }

void MainWindow::on_pushButtonUserAdd_clicked()
{
    useradd = new UserAdd();
    useradd->show();
}

void MainWindow::on_pushButtonUserEdit_clicked()
{
    useredit = new UserEdit();
    useredit->show();
}

void MainWindow::on_pushButtonFileAdd_clicked()
{
    fileadd = new FileAdd();
    fileadd->show();
}

void MainWindow::on_pushButtonFileEdit_clicked()
{
    fileedit = new FileEdit();
    fileedit->show();
}

void MainWindow::on_pushButtonUser_clicked()
{
    model=new QSqlRelationalTableModel();
    model->setTable("user");
              model->select();
              ui->tableView->setModel(model);
              ui->tableView->resizeColumnsToContents();
              ui->tableView->show();
}

void MainWindow::on_pushButtonFile_clicked()
{
    model=new QSqlRelationalTableModel();
    model->setTable("file");
              model->select();
              ui->tableView->setModel(model);
              ui->tableView->resizeColumnsToContents();
              ui->tableView->show();
}

