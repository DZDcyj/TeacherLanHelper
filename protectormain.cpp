#include "protectormain.h"
#include "ui_protectormain.h"

static QTimer *qtimer=new QTimer;
static int time_left = 5;
protectormain::protectormain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::protectormain)
{
    ui->setupUi(this);
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint|Qt::FramelessWindowHint);
    setFixedSize(this->width(),this->height());     // 固定窗口大小
    qtimer->setInterval(1000);
    connect(qtimer,SIGNAL(timeout()),this,SLOT(secondminus()));
    qtimer->start();
}

protectormain::~protectormain()
{
    delete ui;
}

void protectormain::secondminus()
{
    time_left--;
    ui->CountDown->setText(tr("%1").arg(time_left));
    if (time_left==0)
    {
        on_Enter_clicked();
    }
}
void protectormain::on_Enter_clicked()
{
    mainwindow = new MainWindow;
    //mainwindow->show();
    connect(ui->Enter,SIGNAL(clicked()),this,SLOT(reset()));
}
void protectormain::reset()
{
    time_left=5;
    qtimer->stop();
    ui->CountDown->setText("5");
}
