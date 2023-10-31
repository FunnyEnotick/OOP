#include "tourbook.h"
#include "./ui_tourbook.h"
#include "QDateTimeEdit"
#include "QDateTime"
#include "Clients.h"
#include <QSqlQuery>
#include <QSqlError>

QSqlQuery Tourbook::queryTo;

Tourbook::Tourbook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tourbook)
{
    ui->setupUi(this);
    queryTo.prepare("INSERT INTO book (name,surname,country,city,hotel,people,sum) "
                    "VALUES (:name,:surname,:country,:city,:hotel,:people,:sum)");
}
Tourbook::~Tourbook()
{
    queryTo.clear();
    delete ui;
}
void Tourbook::mySlot(const QString &text){
    queryTo.bindValue(":country", text);
    ui->textEdit->clear();
        QString resultString = "Направление путешествия - "+ text;
        ui->textEdit->append(resultString);
}
void Tourbook::mySlot2(const QString &text){
        queryTo.bindValue(":city", text);
    QString resultString;
        resultString = "Город путешествия - "+text;
    ui->textEdit->append(resultString);

}
void Tourbook::mySlot3(const QString &text){
    queryTo.bindValue(":hotel", text);
    QString resultString = "Отель выбран: " + text;
        ui->textEdit->append(resultString);
}
void Tourbook::mySlot4(const QString &text){
    queryTo.bindValue(":people", text);
    QString resultString = "Количество взрослых:" + text;
        ui->textEdit->append(resultString);

}
void Tourbook::mySlot5(const QString &text){
    QString resultString = "Количество детей:" + text;
        ui->textEdit->append(resultString);

}
void Tourbook::mySlot6(const QString &text){
    ui->textEdit->append("Количество номеров:"+ text);

}
void Tourbook::mySlot7(QDate &text,QDate &text1){
    QString resultString = "Дата начала путешествия: ";
    ui->textEdit->append(resultString);
    ui->textEdit->insertPlainText((text1).toString("dd.MM.yyyy"));
    QString resultString1 = "Дата конца путешествия: ";
    ui->textEdit->append(resultString1);
    ui->textEdit->insertPlainText((text).toString("dd.MM.yyyy"));
    QString during=QVariant(text1.daysTo(text)).toString();
    ui->textEdit->append("Длительность путешествия: "+during);
}
void Tourbook::mySlot8(QString &cnt, QDate &text,QDate &text1, int &text2){
    int during = QVariant(text1.daysTo(text)).toInt();
    int mlt = cnt.toInt();
    int summ = during * text2 * mlt;
    queryTo.bindValue(":sum", summ);
    QString su = QVariant(summ).toString();
    QString resultString = "Итоговая сумма : " + su;
    ui->textEdit->append(resultString);
}

void Tourbook::on_client_clicked()
{
    Clients *desk = new Clients;
    desk->show();
}

void Tourbook::on_buttonBox_accepted() {
    if (Clients::gotNumber != "") {
        QSqlQuery getNumData("SELECT name, surname FROM client WHERE phone = :phone");
        getNumData.bindValue(":phone", Clients::gotNumber);
        getNumData.exec();
        if (getNumData.next()) {
            queryTo.bindValue(":name",getNumData.value(0));
            queryTo.bindValue(":surname",getNumData.value(1));
        }
    } else return;
    queryTo.exec();
}
