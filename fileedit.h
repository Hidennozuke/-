#ifndef FILEEDIT_H
#define FILEEDIT_H

#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class FileEdit;
}

class FileEdit : public QWidget
{
    Q_OBJECT

public:
    explicit FileEdit(QWidget *parent = nullptr);
    ~FileEdit();

private slots:
    void on_pushButtonFileEdit_clicked();

private:
    Ui::FileEdit *ui;
    QLineEdit *lineEditIdFileEdit;
    QLineEdit *lineEditNameEdit;
    QLineEdit *lineEditSizeEdit;
    QLineEdit *lineEditLocationEdit;
    QLineEdit *lineEditOwnerEdit;
    QPushButton *pushButtonFileEdit;
};

#endif // FILEEDIT_H
