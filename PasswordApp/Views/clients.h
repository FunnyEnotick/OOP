#ifndef CLIENTS_H
#define CLIENTS_H

#include <QDialog>

namespace Ui {
class Clients;
}

class Clients : public QDialog
{
    Q_OBJECT

public:
    static QString gotNumber;
    explicit Clients(QWidget *parent = nullptr);
    ~Clients();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Clients *ui;
};


#endif // CLIENTS_H
