#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include <QDialog>
#include "adminmenu.h"


namespace Ui {
class AdminLogin;
}

class AdminLogin : public QDialog
{
    Q_OBJECT

public:
    explicit AdminLogin(QWidget *parent = nullptr);
    ~AdminLogin();

private:
    Ui::AdminLogin *ui;
    AdminMenu *adminmenu;

private slots:
    void getPswd();
    void on_OK_clicked();

    void on_Cancel_clicked();

signals:
    void reset();
    void back();
};

#endif // ADMINLOGIN_H
