#include "changepassword.h"
#include "ui_changepassword.h"
#include <QCryptographicHash>
static QSettings qsettings("HKEY_CURRENT_USER\\Software\\llsqt",QSettings::NativeFormat);
static QString originalpassword;
ChangePassword::ChangePassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangePassword)
{
    ui->setupUi(this);
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint|Qt::FramelessWindowHint);
    setFixedSize(this->width(),this->height());     // 固定窗口大小
    originalpassword=qsettings.value("adminpswd").toString();
}

ChangePassword::~ChangePassword()
{
    delete ui;
}

void ChangePassword::on_OK_clicked()
{
    QString oripswd=ui->ori_pswd->text();
    QString newpswd=ui->new_pswd->text();
    QString md5ori=md5Text(oripswd);
    QString md5new=md5Text(newpswd);
    if(!newpswd.isEmpty())
    {
        if(md5ori==originalpassword)
        {
            qsettings.setValue("adminpswd",md5new);
            QMessageBox::information(this,QString::fromLocal8Bit("提醒"),QString::fromLocal8Bit("密码修改成功！你的新密码是: ")+newpswd);
            originalpassword=qsettings.value("adminpswd").toString();
        }
        else {
            QMessageBox::critical(this,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("旧密码输入错误！"));
        }
    }
    else
    {
        QMessageBox::critical(this,QString::fromLocal8Bit("警告"),QString::fromLocal8Bit("新密码不能为空！"));
    }
}

QString ChangePassword::md5Text(QString text)
{
    QString md5pswd;
    QByteArray ba,bb;
    QCryptographicHash md(QCryptographicHash::Md5);
    ba.append(text);
    md.addData(ba);
    bb=md.result();
    md5pswd.append(bb.toHex());
    return md5pswd;
}
