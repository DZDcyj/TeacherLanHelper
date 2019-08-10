#include "backingup.h"
#include "ui_backingup.h"
static QDir dir;
static QString path=dir.currentPath();
static QString filepath=path+"/comments.txt";
static QString backuppath=path+"/bf.txt";
static bool from_open=false;
static QTimer *qtimer = new QTimer;
static int pro=0;
backingup::backingup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::backingup)
{
    ui->setupUi(this);
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint|Qt::FramelessWindowHint);
    setFixedSize(this->width(),this->height());     // 固定窗口大小
    connect(qtimer,SIGNAL(timeout()),this,SLOT(addprogress()));
    qtimer->setInterval(10);
    qtimer->start();
}

backingup::~backingup()
{
    delete ui;
}

void backingup::changetext()
{
    ui->label->setText(QString::fromLocal8Bit("正在恢复……"));
    ui->progressBar->setValue(0);
}

void backingup::addprogress()
{
    pro++;
    if(pro==101)
    {
        if (from_open)
            changetext();
        else
        {
            transferTextData(backuppath,filepath);
            finish();
        }
    }
    else
    {
        ui->progressBar->setValue(pro);
    }
}
void backingup::finish()
{
    mainwindow=new MainWindow;
    mainwindow->show();
    qtimer->stop();
    this->accept();
}

QString backingup::getTextFromFile(QString filepath)
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
void backingup::setTextToFile(QString filepath,QString str)
{
    QFile file(filepath);
    QTextStream txtOutput(&file);
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    txtOutput<<str;
    file.close();
}
void backingup::transferTextData(QString origin_filepath,QString target_filepath)
{
    QString data=getTextFromFile(origin_filepath);
    setTextToFile(target_filepath,data);
}
