#include "backingup.h"
#include "ui_backingup.h"

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
            finish();
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
