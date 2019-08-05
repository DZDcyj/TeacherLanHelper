#include "signup.h"
#include "ui_signup.h"

SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
    Qt::WindowFlags flags;
    flags|=Qt::WindowMaximizeButtonHint|Qt::MSWindowsFixedSizeDialogHint;
    setWindowFlags(flags);      // 禁止改变窗口大小(取消了最大化按钮)
    setFixedSize(this->width(),this->height());     // 固定窗口大小
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_pushButton_clicked()
{
    QString str1,str2;
    str1=QString::fromLocal8Bit("恭喜");
    str2=QString::fromLocal8Bit("您已成功报名化学精品班，可喜可贺，可喜可贺！报名费大洋100元/课，每次2小时");
    QMessageBox::information(this,str1,str2);
}
