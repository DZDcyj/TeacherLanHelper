#include "saving.h"
#include "ui_saving.h"
#include <QSettings>
#include <QFile>
#include <QTextStream>
#include <QDir>
static QTimer *qtimer=new QTimer;
static int progress=0;
static QSettings qsettings("HKEY_CURRENT_USER\\Software\\llsqt",QSettings::NativeFormat);
static QDir dir;
static QString path=dir.currentPath();
static QString filepath=path+"/comments.txt";
static QString backuppath=path+"/bf.txt";
static bool retry=false;
const int TRUE = 1;
const int FALSE = 2;
const int OPEN_MODE = 1;
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
            transferTextData(filepath,backuppath);
            this->reset();
            this->accept();
        }
    }
}

void Saving::reset()
{
    progress=0;
}

QString Saving::getTextFromFile(QString filepath)
{
    QFile file(filepath);
    if(file.exists())
    {
        file.open(QIODevice::ReadOnly|QIODevice::Text);
        QByteArray string=file.readAll();
        QString realString=QString::fromLocal8Bit(string);
        return realString;
    }
    else
    {
        file.open(QIODevice::WriteOnly);
        file.close();
        return "";
    }
}
void Saving::setTextToFile(QString filepath,QString str)
{
    QFile file(filepath);
    QTextStream txtOutput(&file);
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    txtOutput<<str;
    file.close();
}
void Saving::transferTextData(QString origin_filepath,QString target_filepath)
{
    QString data=getTextFromFile(origin_filepath);
    setTextToFile(target_filepath,data);
}
