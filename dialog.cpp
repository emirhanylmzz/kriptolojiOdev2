#include "dialog.h"
#include "ui_dialog.h"

#define path_to_db "/home/emir/Desktop/mydatabase.db"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    myDB = QSqlDatabase::addDatabase("QSQLITE");
    myDB.setDatabaseName(path_to_db);

    QFileInfo checkFile(path_to_db);
    if(checkFile.isFile() && myDB.open()){
        qDebug("Database connected!");
    }
    else {
        qDebug("Database connection failed!");
    }

}

Dialog::~Dialog()
{
    delete ui;
    myDB.close();
}


void Dialog::on_loginButton_clicked()
{

    QString username, password;
    username = ui->namelineEdit->text();
    password = ui->passwordLineEdit->text();

    QByteArray hash = QCryptographicHash::hash(password.toLocal8Bit(), QCryptographicHash::Md5);
    QString decryptPassword = QTextCodec::codecForMib(106)->toUnicode(hash);

    if(!myDB.isOpen()){
        qDebug("Connection failed!");
        return;
    }

    QSqlQuery qry;
    if(qry.exec("SELECT username, password FROM users WHERE username=\'" + username +
                "\' AND password=\'" + decryptPassword + "\'"))
    {
        if(qry.next())
        {
            QString msg;
            QMessageBox::warning(this, "Login was succesful!", msg);
            qDebug("Login was succesful!");
        }else{
            QString msg;
            QMessageBox::warning(this, "Wrong username or password!", msg);
            qDebug("Wrong username or password!");
        }
    }
}


void Dialog::on_clearButton_clicked()
{
    ui->namelineEdit->setText("");
    ui->passwordLineEdit->setText("");
}


void Dialog::on_signButton_clicked()
{
    QString username, password;
    username = ui->usernameSignText->text();
    password = ui->passwordSignText->text();

    QByteArray hash = QCryptographicHash::hash(password.toLocal8Bit(), QCryptographicHash::Md5);
    QString encryptPassword = QTextCodec::codecForMib(106)->toUnicode(hash);

    QSqlQuery qry;
    qry.prepare("INSERT INTO users (username, password) "
                  "VALUES (:username, :password)");
    qry.bindValue(":username", username);
    qry.bindValue(":password", encryptPassword);

    if(qry.exec())
    {
        if(qry.next())
        {
            QString msg;
            QMessageBox::warning(this, "Sign was succesful!", msg);
            qDebug("Sign was succesful!");
        }else{
            QString msg;
            QMessageBox::warning(this, "Wrong username or password!", msg);
            qDebug("Wrong username or password!");
        }
    }
}


void Dialog::on_clearButton_2_clicked()
{
    ui->usernameSignText->setText("");
    ui->passwordSignText->setText("");
}


