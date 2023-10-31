#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QScopedPointer>

#include "Services/AuthServiceInterface.h"
#include "Services/AuthService.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_signInBtn_clicked();

    void on_signUpBtn_clicked();

    void on_goToSignInBtn_clicked();

    void on_goToSignUpBtn_clicked();

private:
    Ui::LoginWindow *ui;
    QScopedPointer<AuthServiceInterface> _authService;
    bool isValidLoginForm();
    bool isValidRegisterForm();
};
#endif // LOGINWINDOW_H
