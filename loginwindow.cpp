#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    db = new DatabaseManager("data/health_tracker.db");
}

LoginWindow::~LoginWindow() {
    delete ui;
}

void LoginWindow::on_btnLogin_clicked() {
    QString username = ui->txtUser->text();
    QString password = ui->txtPass->text();

    auto user = db->getUserByUsername(username);

    if (!user.has_value()) {
        QMessageBox::warning(this, "Error", "Usuario no encontrado");
        return;
    }

    if (user->passwordHash != password) {  // (simplificado)
        QMessageBox::warning(this, "Error", "Contraseña incorrecta");
        return;
    }

    MainWindow *m = new MainWindow(*user);
    m->show();
    this->close();
}
