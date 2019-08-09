#include "adminmenu.h"
#include "ui_adminmenu.h"

static QSettings qsettings("HKEY_CURRENT_USER\\Software\\llsqt",QSettings::NativeFormat);
const int TRUE = 1;
const int FALSE = 2;
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
