#ifndef LANINFO_H
#define LANINFO_H

#include <QMainWindow>
#include <QMessageBox>
#include "signup.h"
#include "lanforum.h"
namespace Ui {
class LanInfo;
}

class LanInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit LanInfo(QWidget *parent = nullptr);
    SignUp *new_signup;
    LanForum *new_lanforum;
    ~LanInfo();

private slots:
    void on_Like_clicked();

    void on_SignUp_clicked();

    void on_Forum_clicked();

private:
    Ui::LanInfo *ui;
};

#endif // LANINFO_H
