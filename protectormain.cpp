#include "protectormain.h"
#include "ui_protectormain.h"

static QTimer *qtimer=new QTimer;
static int time_left = 5;
static bool isProtectMode = false;
static QSettings qsettings("HKEY_CURRENT_USER\\Software\\llsqt",QSettings::NativeFormat);
const int PROTECT_MODE=2;
const int OPEN_MODE=1;
protectormain::protectormain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::protectormain)
{
    ui->setupUi(this);
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint|Qt::FramelessWindowHint);
    setFixedSize(this->width(),this->height());     // 固定窗口大小
    getMode();
    qtimer->setInterval(1000);
    connect(qtimer,SIGNAL(timeout()),this,SLOT(secondminus()));
    qtimer->start();
}
void protectormain::getMode()
{
    if (qsettings.value("mode")!=NULL)
    {
        if(qsettings.value("mode")==OPEN_MODE)
        {
            isProtectMode=false;
        }
        else
        {
            isProtectMode=true;
        }
    }
    else
    {
        qsettings.setValue("mode",PROTECT_MODE);
        isProtectMode=true;
    }

    if (isProtectMode)
    {
        ui->ToProtectMode->setVisible(false);
        ui->Status->setText(QString::fromLocal8Bit("当前处于保护模式"));
        ui->Status->setStyleSheet("QLabel{color:black;}");
    }
    else
    {
        ui->Status->setText(QString::fromLocal8Bit("当前处于开放模式"));
        ui->Status->setStyleSheet("QLabel{color:red;}");
    }
}
protectormain::~protectormain()
{
    delete ui;
}

void protectormain::secondminus()
{
    time_left--;
    ui->CountDown->setText(tr("%1").arg(time_left));
    if (time_left<=0)
    {
        on_Enter_clicked();
    }
}
void protectormain::on_Enter_clicked()
{
    if (isProtectMode)
    {
        backingup = new class backingup;
        backingup->show();
    }
    else
    {
        mainwindow = new MainWindow;
        mainwindow->show();
    }
    connect(ui->Enter,SIGNAL(clicked()),this,SLOT(reset()));
    this->close();
    qtimer->stop();
    this->destroy();
}
void protectormain::reset()
{
    time_left=5;
    ui->CountDown->setText("5");
}

void protectormain::on_ToProtectMode_clicked()
{
    qsettings.setValue("mode",PROTECT_MODE);
    qtimer->stop();
    QMessageBox::information(this,QString::fromLocal8Bit("兰老师提示"),QString::fromLocal8Bit("已经切换到保护模式！"));
    qtimer->start();
    isProtectMode=false;
    getMode();
    reset();
}
void protectormain::reshow()
{
    this->show();
    this->reset();
    qtimer->start();
}

void protectormain::on_AdminMenu_clicked()
{
    connect(ui->AdminMenu,SIGNAL(clicked()),this,SLOT(reset()));
    adminlogin=new AdminLogin;
    adminlogin->show();
    connect(adminlogin,SIGNAL(back()),this,SLOT(reshow()));
    this->close();
    qtimer->stop();
    this->destroy();
}
