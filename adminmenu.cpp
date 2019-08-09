#include "adminmenu.h"
#include "ui_adminmenu.h"
#include "saving.h"
static QSettings qsettings("HKEY_CURRENT_USER\\Software\\llsqt",QSettings::NativeFormat);
const int TRUE = 1;
const int FALSE = 2;
const int OPEN_MODE=1;
AdminMenu::AdminMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminMenu)
{
    ui->setupUi(this);
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint|Qt::FramelessWindowHint);
    setFixedSize(this->width(),this->height());     // 固定窗口大小
    int status = qsettings.value("autoChange").toInt();
    if(status==TRUE)
    {
        ui->AutoRecover->setChecked(true);
    }
    else if(status == FALSE)
    {
        ui->AutoRecover->setChecked(false);
    }
    else
    {
        qsettings.setValue("autoChange",TRUE);
        ui->AutoRecover->setChecked(true);
    }
}

AdminMenu::~AdminMenu()
{
    delete ui;
}

void AdminMenu::on_AutoRecover_clicked(bool checked)
{
    if (checked)
        qsettings.setValue("autoChange",TRUE);
    else
        qsettings.setValue("autoChange",FALSE);
}

void AdminMenu::on_DataSave_clicked()
{
    this->accept();
    qsettings.setValue("opensave",FALSE);
    Saving *save=new Saving;
    connect(save,SIGNAL(backtomenu()),this,SLOT(getSignal()));
    save->show();
}

void AdminMenu::getSignal()
{
    emit backtomenu();
}

void AdminMenu::on_ChangePswd_clicked()
{
    change=new ChangePassword;
    change->setModal(true);
    change->show();
}

void AdminMenu::on_OpenMode_clicked()
{
    qsettings.setValue("mode",OPEN_MODE);
    qsettings.setValue("opensave",TRUE);
    emit backtomenu();
    this->accept();
}
