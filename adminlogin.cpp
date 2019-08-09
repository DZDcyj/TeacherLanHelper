#include "adminlogin.h"
#include "ui_adminlogin.h"
#include <QSettings>
#include <QDebug>
#include <QCryptographicHash>
const QString default_pswd = "admin";
static QSettings qsettings("HKEY_CURRENT_USER\\Software\\llsqt",QSettings::NativeFormat);
static QString pswd;
AdminLogin::AdminLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminLogin)
{
    ui->setupUi(this);
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint|Qt::FramelessWindowHint);
    setFixedSize(this->width(),this->height());     // 固定窗口大小
    if(qsettings.value("adminpswd")==QVariant::Invalid)
    {
        QString md5defaultpswd;
        QByteArray ba,bb;
        QCryptographicHash md(QCryptographicHash::Md5);
        ba.append(default_pswd);
        md.addData(ba);
        bb=md.result();
        md5defaultpswd.append(bb.toHex());
        qsettings.setValue("adminpswd",md5defaultpswd);
        pswd=md5defaultpswd;
    }
    else {
        pswd=qsettings.value("adminpswd").toString();
    }
}

AdminLogin::~AdminLogin()
{
    delete ui;
}

void AdminLogin::getPswd()
{

}

void AdminLogin::on_OK_clicked()
{
    QString nowpswd=ui->pswd->text();
    QString md5pswd;
    QByteArray ba,bb;
    QCryptographicHash md(QCryptographicHash::Md5);
    ba.append(nowpswd);
    md.addData(ba);
    bb=md.result();
    md5pswd.append(bb.toHex());
    if (md5pswd!=pswd)
    {
        ui->Status->setText(QString::fromLocal8Bit("密码输入有误！"));
        ui->Status->setStyleSheet("QLabel{color:red;}");
    }
    else {
        adminmenu=new AdminMenu;
        adminmenu->show();
        connect(adminmenu,SIGNAL(backtomenu()),this,SLOT(on_Cancel_clicked()));
        this->accept();
    }
}

void AdminLogin::on_Cancel_clicked()
{
    this->reject();
    emit back();
}
