#ifndef FILEADD_H
#define FILEADD_H

#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class FileAdd;
}

class FileAdd : public QWidget
{
    Q_OBJECT

public:
    explicit FileAdd(QWidget *parent = nullptr);
    ~FileAdd();

private slots:
    void on_pushButtonFileAdd_clicked();

private:
    Ui::FileAdd *ui;
    QLineEdit *lineEditNameAdd;
    QLineEdit *lineEditSizeAdd;
    QLineEdit *lineEditLocationAdd;
    QLineEdit *lineEditOwnerAdd;
    QPushButton *pushButtonFileAdd;
};

#endif // FILEADD_H
