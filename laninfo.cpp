#include "laninfo.h"
#include "ui_laninfo.h"

static  QSettings settings("HKEY_CURRENT_USER\\Software\\llsqt",QSettings::NativeFormat);
LanInfo::LanInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LanInfo)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowCloseButtonHint|Qt::MSWindowsFixedSizeDialogHint);
    setFixedSize(this->width(),this->height());     // 固定窗口大小
    int likes=0;
    if (settings.value("likes")!=NULL)
    {
        likes=settings.value("likes").toInt();
    }
    else {
        settings.setValue("likes",0);
    }
    ui->Likes->setText(tr("%1").arg(likes));
}

LanInfo::~LanInfo()
{
    delete ui;
}

void LanInfo::on_Like_clicked()
{
    QString likes=ui->Likes->text();
    int newlikes=likes.toInt()+1;
    if (newlikes<10000000)
    {
        ui->Likes->setText(tr("%1").arg(newlikes));
        settings.setValue("likes",ui->Likes->text().toInt());
    }
    else
    {
        QString str1,str2;
        str1=QString::fromLocal8Bit("兰老师提示");
        str2=QString::fromLocal8Bit("兰老师已经不屑于接受你这微弱的一票！");
        QMessageBox::information(this,str1,str2,QMessageBox::Ok);
    }
}

void LanInfo::on_SignUp_clicked()
{
    new_signup=new SignUp;
    new_signup->show();
}

void LanInfo::on_Forum_clicked()
{
    new_lanforum=new LanForum;
    new_lanforum->show();
}
