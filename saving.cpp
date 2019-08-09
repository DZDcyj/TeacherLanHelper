#include "saving.h"
#include "ui_saving.h"
#include <QSettings>
static QTimer *qtimer=new QTimer;
static int progress=0;
static QSettings qsettings("HKEY_CURRENT_USER\\Software\\llsqt",QSettings::NativeFormat);
const int TRUE = 1;
const int FALSE = 2;
const int OPEN_MODE = 1;
static bool retry=false;
Saving::Saving(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Saving)
{
    ui->setupUi(this);
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint|Qt::FramelessWindowHint);
    setFixedSize(this->width(),this->height());     // 固定窗口大小
    if (qsettings.value("opensave")==QVariant::Invalid)
    {
        qsettings.setValue("opensave",FALSE);
    }
    else {
        if (qsettings.value("opensave").toInt()!=TRUE)
        {
            ui->label->setText(QString::fromLocal8Bit("正在保存……"));
        }
        else {
            retry = true;
            qsettings.setValue("opensave",FALSE);
        }
    }
    connect(qtimer,SIGNAL(timeout()),this,SLOT(addProgress()));
    qtimer->setInterval(10);
    setAttribute(Qt::WA_DeleteOnClose);
    qtimer->start();
}

Saving::~Saving()
{
    delete ui;
}

void Saving::addProgress()
{
    progress++;
    if (progress<=100)
        ui->progressBar->setValue(progress);
    else
    {
        if (retry)
        {
            this->reset();
            ui->label->setText(QString::fromLocal8Bit("正在保存……"));
            retry = false;
        }
        else
        {
            emit backtomenu();
            if(qsettings.value("mode").toInt()==OPEN_MODE)
                qsettings.setValue("opensave",TRUE);
            qtimer->stop();
            this->reset();
            this->accept();
        }
    }
}

void Saving::reset()
{
    progress=0;
}
