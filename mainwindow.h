#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QSqlQuery>
#include <QPushButton>
#include <QTableView>
#include <QComboBox>
#include <QSqlRelationalTableModel>
#include <QListView>
#include "useradd.h"
#include "ui_useradd.h"
#include "useredit.h"
#include "ui_useredit.h"
#include "fileadd.h"
#include "ui_fileadd.h"
#include "fileedit.h"
#include "ui_fileedit.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    UserAdd * useradd;
    UserEdit * useredit;
    FileAdd * fileadd;
    FileEdit * fileedit;

private slots:
    void on_pushButtonUserAdd_clicked();  
    void on_pushButtonUserEdit_clicked();
    void on_pushButtonFileAdd_clicked();
    void on_pushButtonFileEdit_clicked();
    void on_pushButtonFile_clicked();
    void on_pushButtonUser_clicked();

private:
    Ui::MainWindow *ui;
    QSqlRelationalTableModel *model;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QTableView *tableView;
    QSqlQuery *query;
    QListView *listView;
};

#endif // MAINWINDOW_H
