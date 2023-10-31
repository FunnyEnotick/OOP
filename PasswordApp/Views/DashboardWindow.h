#ifndef DASHBOARDWINDOW_H
#define DASHBOARDWINDOW_H

#include <QMainWindow>
#include "QDateTimeEdit"

namespace Ui {
class DashboardWindow;
}

class DashboardWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DashboardWindow(QWidget *parent = nullptr);
    ~DashboardWindow();

private slots:



    void on_Country_textActivated(const QString &arg1);

    void on_Country_currentIndexChanged(int index);

    void on_checkBox_stateChanged(int arg1);

    void on_logOutBtn_clicked();


    void on_TownF_currentIndexChanged(int index);


    void on_pushButton_clicked();
    void on_dateEdit_editingFinished();

    void on_dateEdit_2_editingFinished();

    void on_hotel_currentIndexChanged(int index);

    void on_Pdf1_clicked();

signals:
    void mySignal(const QString &text);
    void mySignal2(const QString &text);
    void mySignal3(const QString &text);
    void mySignal4(const QString &text);
    void mySignal5(const QString &text);
    void mySignal6(const QString &text);
    void mySignal7(QDate &text,QDate &text1);
    void mySignal8(QString &cnt, QDate &text,QDate &text1, int &text2);

private:
    Ui::DashboardWindow *ui;
    QDate *f=new QDate;
    QDate *s=new QDate;
    QDate *date=new QDate;
};

#endif // DASHBOARDWINDOW_H
