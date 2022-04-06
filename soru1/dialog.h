#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QtSql>
#include <QMessageBox>
#include <QCryptographicHash>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_loginButton_clicked();

    void on_clearButton_clicked();

    void on_signButton_clicked();

    void on_clearButton_2_clicked();
private:
    Ui::Dialog *ui;

    QSqlDatabase myDB;
};
#endif // DIALOG_H
