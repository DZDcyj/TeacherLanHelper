#ifndef PROTECTORMAIN_H
#define PROTECTORMAIN_H

#include <QDialog>
#include <QTimer>
#include "mainwindow.h"
#include "backingup.h"
#include <QSettings>
#include <QMessageBox>
#include "adminmenu.h"
#include "adminlogin.h"
namespace Ui {
class protectormain;
}

class protectormain : public QDialog
{
    Q_OBJECT

public:
    explicit protectormain(QWidget *parent = nullptr);
    ~protectormain();

private:
    Ui::protectormain *ui;
    MainWindow *mainwindow;
    backingup *backingup;
    AdminLogin *adminlogin;

private slots:
   void secondminus();
   void on_Enter_clicked();
   void reset();
   void on_ToProtectMode_clicked();
   void getMode();
   void on_AdminMenu_clicked();
   void reshow();
};

#endif // PROTECTORMAIN_H
