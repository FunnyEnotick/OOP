#include "LoginWindow.h"
#include "./ui_LoginWindow.h"
#include "Views/DashboardWindow.h"


LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
    , _authService(new AuthService)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

bool LoginWindow::isValidLoginForm()
{
    if (ui->loginSignInTxt->text().isEmpty()) {
        QMessageBox::critical(this, "Ошибка авторизации", "Введите логин!");
        return false;
    }
    if (ui->passwordSignInTxt->text().isEmpty()) {
        QMessageBox::critical(this, "Ошибка авторизации", "Введите пароль!");
        return false;
    }
    return true;
}

bool LoginWindow::isValidRegisterForm()
{
    if (ui->loginSignUpTxt->text().isEmpty()) {
        QMessageBox::critical(this, "Ошибка авторизации", "Введите логин!");
        return false;
    }
    if (ui->passwordSignUpTxt->text().isEmpty()) {
        QMessageBox::critical(this, "Ошибка авторизации", "Введите пароль!");
        return false;
    }
    if (ui->confirmPasswordSignUpTxt->text().isEmpty()) {
        QMessageBox::critical(this, "Ошибка авторизации", "Подтвердите пароль!");
        return false;
    }
    if (ui->passwordSignUpTxt->text() != ui->confirmPasswordSignUpTxt->text()) {
        QMessageBox::critical(this, "Ошибка авторизации", "Пароли должны быть одинаковыми!");
        return false;
    }
    return true;
}


void LoginWindow::on_signInBtn_clicked()
{
    QString login = ui->loginSignInTxt->text();
    QString password = ui-> passwordSignInTxt->text();
    if (isValidLoginForm()) {
        if (_authService->isExistUser(login, password)) {
            DashboardWindow *dashboard = new DashboardWindow;
            dashboard->setWindowTitle("Личный кабинет администратора");
            dashboard->show();
            this->close();
        } else {
            QMessageBox::critical(this, "Ошибка авторизации", "Вы ввели не правильный логин или пароль!");
        }
    }
}


void LoginWindow::on_signUpBtn_clicked()
{
    QString login = ui->loginSignUpTxt->text();
    QString password = ui-> passwordSignUpTxt->text();
    if (isValidRegisterForm()) {
        if (_authService->addAdmin(login, password)) {
            QMessageBox::information(this, "Регистрация", "Вы успешно зарегестрировались! Войдите в учетную запись!");
            ui->stackedWidget->setCurrentIndex(0);
        } else {
            QMessageBox::critical(this, "Упс... что-то пошло не так", "Не получилось зарегестрироваться. Удалите приложение!");
        }
    }
}


void LoginWindow::on_goToSignInBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void LoginWindow::on_goToSignUpBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

