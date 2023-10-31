#include "DashboardWindow.h"
#include "ui_DashboardWindow.h"
#include "./tourbook.h"
#include <QDateTimeEdit>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
#include <QPainter>
#include <QPrinter>
#include <QPrintDialog>
DashboardWindow::DashboardWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DashboardWindow)
{
    ui->setupUi(this);
    ui->child->setVisible(false);
    ui->stackedWidget->setCurrentIndex(0);
    ui->Country->setCurrentIndex(0);
    ui->TownF->setCurrentIndex(0);
    ui->hotel->clear();
    ui->hotel->addItem("Отель");
    ui->hotel->addItem("Октябрьская");
    ui->hotel->addItem("Wawelberg");
    ui->hotel->addItem("Ибис");
    ui->hotel->addItem("А.Kosterev");
    ui->hotel->addItem("Akgun Istanbul");
    ui->hotel->addItem("Ibis");
    ui->hotel->addItem("Cappadocia Caves");
    ui->hotel->addItem("Kemal stone house");
    ui->TownF->clear();
    ui->TownF->addItem("Город");
    ui->TownF->addItem("Санкт-Петербург");
    ui->TownF->addItem("Москва");
    ui->TownF->addItem("Стамбул");
    ui->TownF->addItem("Каппадоккия");

}

DashboardWindow::~DashboardWindow()
{
    delete ui;
}

void DashboardWindow::on_Country_textActivated(const QString &arg1)
{


}
void DashboardWindow::on_Country_currentIndexChanged(int index)
{
    ui->stackedWidget->setCurrentIndex(0);
    if(ui->Country->currentIndex()==0){
        ui->TownF->clear();
        ui->TownF->addItem("Город");
        ui->TownF->addItem("Санкт-Петербург");
        ui->TownF->addItem("Москва");
        ui->TownF->addItem("Стамбул");
        ui->TownF->addItem("Каппадоккия");
    }
    if(ui->Country->currentIndex()==1){
        ui->TownF->clear();
        ui->TownF->addItem("Город");
        ui->TownF->addItem("Санкт-Петербург");
        ui->TownF->addItem("Москва");
        ui->hotel->clear();
        ui->hotel->addItem("Отель");
        ui->hotel->addItem("Октябрьская");
        ui->hotel->addItem("Wawelberg");
        ui->hotel->addItem("Ибис");
        ui->hotel->addItem("А.Kosterev");
    }
    if(ui->Country->currentIndex()==2){
        ui->TownF->clear();
        ui->TownF->addItem("Город");
        ui->TownF->addItem("Стамбул");
        ui->TownF->addItem("Каппадоккия");
        ui->hotel->clear();
        ui->hotel->addItem("Отель");
        ui->hotel->addItem("Akgun Istanbul");
        ui->hotel->addItem("Ibis");
        ui->hotel->addItem("Cappadocia Caves");
        ui->hotel->addItem("Kemal stone house");
    }

}


void DashboardWindow::on_checkBox_stateChanged(int arg1)
{
    if(ui->checkBox->isChecked()){
        ui->child->setVisible(true);
    } else{
        ui->child->setVisible(false);
    }
}


void DashboardWindow::on_logOutBtn_clicked()
{
    exit(EXIT_FAILURE);
}


void DashboardWindow::on_TownF_currentIndexChanged(int index)
{
    if(ui->TownF->currentText()=="Город"){
        ui->stackedWidget->setCurrentIndex(0);
        ui->hotel->clear();
        ui->hotel->addItem("Отель");
        ui->hotel->addItem("Октябрьская");
        ui->hotel->addItem("Wawelberg");
        ui->hotel->addItem("Ибис");
        ui->hotel->addItem("А.Kosterev");
        ui->hotel->addItem("Akgun Istanbul");
        ui->hotel->addItem("Ibis");
        ui->hotel->addItem("Cappadocia Caves");
        ui->hotel->addItem("Kemal stone house");
    }
    if(ui->TownF->currentText()=="Санкт-Петербург"){
        ui->stackedWidget->setCurrentIndex(1);
        ui->hotel->clear();
        ui->hotel->addItem("Отель");
        ui->hotel->addItem("Октябрьская");
        ui->hotel->addItem("Wawelberg");
    }
    if(ui->TownF->currentText()=="Москва"){
        ui->stackedWidget->setCurrentIndex(3);
        ui->hotel->clear();
        ui->hotel->addItem("Отель");
        ui->hotel->addItem("Ибис");
        ui->hotel->addItem("А.Kosterev");
    }
    if(ui->TownF->currentText()=="Стамбул"){
        ui->stackedWidget->setCurrentIndex(12);
        ui->hotel->clear();
        ui->hotel->addItem("Отель");
        ui->hotel->addItem("Akgun Istanbul");
        ui->hotel->addItem("Ibis");
    }
    if(ui->TownF->currentText()=="Каппадоккия"){
        ui->stackedWidget->setCurrentIndex(2);
        ui->hotel->clear();
        ui->hotel->addItem("Отель");
        ui->hotel->addItem("Cappadocia Caves");
        ui->hotel->addItem("Kemal stone house");
    }
}


void DashboardWindow::on_pushButton_clicked()
{
    Tourbook *dashboard = new Tourbook;
    dashboard->show();// создаем нашу форму
    connect(this, SIGNAL(mySignal(const QString &)), dashboard, SLOT(mySlot(const QString &)));
    connect(this, SIGNAL(mySignal2(const QString &)), dashboard, SLOT(mySlot2(const QString &)));
    connect(this, SIGNAL(mySignal3(const QString &)), dashboard, SLOT(mySlot3(const QString &)));
    connect(this, SIGNAL(mySignal4(const QString &)), dashboard, SLOT(mySlot4(const QString &)));
    connect(this, SIGNAL(mySignal5(const QString &)), dashboard, SLOT(mySlot5(const QString &)));
    connect(this, SIGNAL(mySignal6(const QString &)), dashboard, SLOT(mySlot6(const QString &)));
    connect(this, SIGNAL(mySignal7( QDate &, QDate &)), dashboard, SLOT(mySlot7( QDate &, QDate &)));
    connect(this, SIGNAL(mySignal8(QString &, QDate &,QDate &, int &)), dashboard, SLOT(mySlot8(QString &, QDate &,QDate &, int &)));
    QString c=ui->Country->currentText();
    QString t;
    t=ui->TownF->currentText();
    QString h;
    h=ui->hotel->currentText();
    QString l=ui->ludi->text();
    QString l2=ui->ludi_2->text();
    QString cl=ui->child->text();
    emit mySignal(c);
    emit mySignal2(t);
    emit mySignal3(h);
    emit mySignal4(l);
    emit mySignal5(cl);
    emit mySignal6(l2);
    emit mySignal7(*s,*f);
    QSqlQuery query;
    QString str;
    int a1 = 1, a2 = 1;
    query.prepare("SELECT cost FROM hotel_cost WHERE hotel = (:hotel)");
        str = ui->hotel->currentText();
        query.bindValue(":hotel", str);
        query.exec();
        if (query.next()) {
            a1=query.value(0).toInt();
        } else {

        }

        query.prepare("SELECT cost FROM city_cost WHERE city = (:city)");
        str = ui->TownF->currentText();
        query.bindValue(":city", str);
        query.exec();
        if (query.next()) {
            a2=query.value(0).toInt();
        } else {

        }
        int a3=a1+a2;
    emit mySignal8(l2,*s,*f,a3);
}


void DashboardWindow::on_dateEdit_editingFinished()
{
    *date=ui->dateEdit->date();
    *f=*date;
}



void DashboardWindow::on_dateEdit_2_editingFinished()
{
    *date=ui->dateEdit_2->date();
    *s=*date;
    if (*f>*s){
        ui->dateEdit->setDate(*s);
        ui->dateEdit_2->setDate(*f);
        *s=*f;
        *f=*date;
    }
}


void DashboardWindow::on_hotel_currentIndexChanged(int index)
{
    if(ui->hotel->currentText()=="Октябрьская"){
        ui->stackedWidget->setCurrentIndex(4);
        ui->stars->setValue(4);
    };
    if(ui->hotel->currentText()=="Wawelberg"){
        ui->stackedWidget->setCurrentIndex(5);
        ui->stars->setValue(5);
    };
    if(ui->hotel->currentText()=="Ибис"){
        ui->stackedWidget->setCurrentIndex(6);
        ui->stars->setValue(3);
    };
    if(ui->hotel->currentText()=="А.Kosterev"){
        ui->stackedWidget->setCurrentIndex(7);
        ui->stars->setValue(2);
    };
    if(ui->hotel->currentText()=="Akgun Istanbul"){
        ui->stackedWidget->setCurrentIndex(8);
        ui->stars->setValue(5);
    };
    if(ui->hotel->currentText()=="Ibis"){
        ui->stackedWidget->setCurrentIndex(9);
        ui->stars->setValue(3);
    };
    if(ui->hotel->currentText()=="Cappadocia Caves"){
        ui->stackedWidget->setCurrentIndex(10);
        ui->stars->setValue(4);
    };
    if(ui->hotel->currentText()=="Kemal stone hous"){
        ui->stackedWidget->setCurrentIndex(11);
        ui->stars->setValue(2);
    };
}
void PrintTable( QPrinter* printer, QSqlQuery&  Query ) {
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = Query.size();
    const int columnCount = Query.record().count();

    out <<  "<html>\n"
           "<head>\n"
           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>%1</title>\n").arg("TITLE OF TABLE")
        <<  "</head>\n"
           "<body bgcolor=#ffffff link=#5000A0>\n"
           "<table border=1 cellspacing=0 cellpadding=2>\n";

    // headers
    out << "<thead><tr bgcolor=#f0f0f0>";
    for (int column = 0; column < columnCount; column++)
        out << QString("<th>%1</th>").arg(Query.record().fieldName(column));
    out << "</tr></thead>\n";

    while (Query.next()) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            QString data = Query.value(column).toString();
            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
        }
        out << "</tr>\n";
    }

    out <<  "</table>\n"
           "</body>\n"
           "</html>\n";

    QTextDocument document;
    document.setHtml(strStream);
    document.print(printer);

}




void DashboardWindow::on_Pdf1_clicked()
{
    QPrinter printer(QPrinter::HighResolution);
       printer.setOutputFormat(QPrinter::PdfFormat);
       QPrintDialog dlg(&printer, 0);
       if(dlg.exec() == QDialog::Accepted) {
           QSqlQuery qr("SELRCT *FROM book");
           PrintTable(&printer, qr);
       }
}

