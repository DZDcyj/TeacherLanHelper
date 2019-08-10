#include "protectormain.h"
#include "ui_protectormain.h"

static QTimer *qtimer=new QTimer;
static int time_left = 5;
static bool isProtectMode = false;
static QSettings qsettings("HKEY_CURRENT_USER\\Software\\llsqt",QSettings::NativeFormat);
const int PROTECT_MODE=2;
const int OPEN_MODE=1;
const int TRUE = 1;
protectormain::protectormain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::protectormain)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_QuitOnClose);
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint|Qt::FramelessWindowHint);
    setFixedSize(this->width(),this->height());     // 固定窗口大小
    if (qsettings.value("autoChange").toInt()==TRUE&&qsettings.value("mode").toInt()==OPEN_MODE)
    {
        saveFromOpen();
        qsettings.setValue("mode",PROTECT_MODE);
    }
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
        ui->KeepData->setVisible(true);
        ui->Status->setText(QString::fromLocal8Bit("当前处于保护模式"));
        ui->Status->setStyleSheet("QLabel{color:black;}");
    }
    else
    {
        ui->ToProtectMode->setVisible(true);
        ui->KeepData->setVisible(false);
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
    qtimer->stop();
    this->accept();
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
    saveFromOpen();
    qtimer->start();
    isProtectMode=false;
    getMode();
    reset();
}
void protectormain::reshow()
{
    this->show();
    this->reset();
    getMode();
    qtimer->start();
    qtimer->setInterval(1000);
}

void protectormain::on_AdminMenu_clicked()
{
    connect(ui->AdminMenu,SIGNAL(clicked()),this,SLOT(reset()));
    adminlogin=new AdminLogin;
    adminlogin->show();
    connect(adminlogin,SIGNAL(back()),this,SLOT(reshow()));
    connect(adminlogin,SIGNAL(reset()),this,SLOT(reset()));
    this->reset();
    qtimer->stop();
    this->accept();
}

void protectormain::saveFromOpen()
{
    save = new Saving;
    save->setModal(true);
    this->reset();
    save->show();
}

void protectormain::on_KeepData_clicked()
{
    connect(ui->KeepData,SIGNAL(clicked()),this,SLOT(reset()));
    datakeeplogin=new dataKeepLogin;
    datakeeplogin->show();
    connect(datakeeplogin,SIGNAL(back()),this,SLOT(reshow()));
    connect(datakeeplogin,SIGNAL(reset()),this,SLOT(reset()));
    connect(datakeeplogin,SIGNAL(openLan()),this,SLOT(directOpen()));
    this->reset();
    qtimer->stop();
    this->accept();
}

void protectormain::directOpen()
{
    mainwindow = new MainWindow;
    mainwindow->show();
    qtimer->stop();
    this->accept();
}
