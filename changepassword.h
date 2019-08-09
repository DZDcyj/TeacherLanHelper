#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

#include <QDialog>
#include <QMessageBox>
#include <QSettings>

namespace Ui {
class ChangePassword;
}

class ChangePassword : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePassword(QWidget *parent = nullptr);
    ~ChangePassword();

private slots:
    void on_OK_clicked();

private:
    Ui::ChangePassword *ui;

private slots:
    QString md5Text(QString text);
};

#endif // CHANGEPASSWORD_H
