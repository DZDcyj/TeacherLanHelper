#include "opensource.h"
#include "ui_opensource.h"


OpenSource::OpenSource(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenSource)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowCloseButtonHint|Qt::MSWindowsFixedSizeDialogHint);
    setFixedSize(this->width(),this->height());     // 固定窗口大小
    QString fileName=QString::fromLocal8Bit("E:/化学/new.hht");
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        ui->OpenCourse->setEnabled(false);
        ui->BothOpen->setEnabled(false);
    }
}

OpenSource::~OpenSource()
{
    delete ui;
}


void OpenSource::on_OpenCourse_clicked()
{
    QDesktopServices::openUrl(QUrl(QString::fromLocal8Bit("file:///E:/化学/new.hht")));
}



void OpenSource::on_BothOpen_clicked()
{
    QDesktopServices::openUrl(QUrl(QString::fromLocal8Bit("file:///E:/化学")));
    QDesktopServices::openUrl(QUrl(QString::fromLocal8Bit("file:///E:/化学/new.hht")));
}

void OpenSource::on_OpenPath_clicked()
{
    QDesktopServices::openUrl(QUrl(QString::fromLocal8Bit("file:///E:/化学")));
}
