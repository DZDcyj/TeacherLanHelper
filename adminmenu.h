#ifndef ADMINMENU_H
#define ADMINMENU_H

#include <QDialog>
#include <QSettings>
#include "changepassword.h"

namespace Ui {
class AdminMenu;
}

class AdminMenu : public QDialog
{
    Q_OBJECT

public:
    explicit AdminMenu(QWidget *parent = nullptr);
    ~AdminMenu();

private slots:
    void on_AutoRecover_clicked(bool checked);

    void on_DataSave_clicked();

    void getSignal();

    void on_ChangePswd_clicked();

    void on_OpenMode_clicked();

    void on_Back_clicked();

private:
    Ui::AdminMenu *ui;

    ChangePassword *change;
signals:
    void backtomenu();
};

#endif // ADMINMENU_H
