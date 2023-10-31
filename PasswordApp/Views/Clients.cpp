#include "clients.h"
#include "ui_clients.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>


QString Clients::gotNumber;

Clients::Clients(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Clients)
{
    ui->setupUi(this);

}

Clients::~Clients()
{
    gotNumber = "";
    delete ui;
}

void Clients::on_buttonBox_accepted()
{
    QSqlQuery query, queryIns;
    query.prepare("SELECT phone FROM client WHERE phone = :phone");
    query.bindValue(":phone", ui->lineEdit_4->text());
    query.exec();
    if (query.next()) {
        QMessageBox::information(this,"Скидка","Клиент существует. Предоставлена скидка 5%");
    } else {
        queryIns.prepare("INSERT INTO client (name,surname, patronymic,phone,email) VALUES (:name,:surname, :patronymic,:phone,:email)");
        queryIns.bindValue(":name", ui->lineEdit->text());
        queryIns.bindValue(":surname", ui->lineEdit_2->text());
        queryIns.bindValue(":patronymic", ui->lineEdit_3->text());
        queryIns.bindValue(":phone", ui->lineEdit_4->text());
        queryIns.bindValue(":email", ui->lineEdit_5->text());
        if (queryIns.exec()) {
            QMessageBox::information(this,"Успех","Клиент создан. Скидка будет предоставлена со следующего заказа.");
        }
    }
    gotNumber = ui->lineEdit_4->text();
}

