#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Qt::WindowFlags flags;
    flags|=Qt::WindowMaximizeButtonHint|Qt::MSWindowsFixedSizeDialogHint;
    setWindowFlags(flags);      // 禁止改变窗口大小(取消了最大化按钮)
    setFixedSize(this->width(),this->height());     // 固定窗口大小
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_About_clicked()
{
    new_about = new about;
    new_about->show();
}

void MainWindow::on_Check_clicked()
{
    //QString fileName=QFileDialog::getOpenFileName(this,tr("选择文件"),".",tr("课件文件(*.hht)"));
    QString fileName=QString::fromLocal8Bit("E:/化学/new.hht");// TODO:后续可以加入选择课件选项
    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        QString infoList;
        QString origin_size=QString::fromLocal8Bit("课件大小: ");
        if (!file.open(QIODevice::ReadOnly))
        {
           ui->Solution->setText(QString::fromLocal8Bit("课件 %1 不存在。").arg(fileName));
           ui->SourceSize->setText(origin_size+"NaN");
        }
        else
        {
            file.close();
            QFileInfo info(fileName);
            if(info.exists())
            {
               ui->SourceSize->setText(origin_size+tr("%1 KB").arg(info.size()/1024));
               long long size=info.size()/1024;
               if (size<300)
               {
                   ui->Solution->setText(QString::fromLocal8Bit("请保存数据后重启Hiteboard软件或重新插拔设备。"));
               }
               else if(size>=300 && size < 500)
               {
                   ui->Solution->setText(QString::fromLocal8Bit("课件文件较大，建议写完该部分后保存重建。"));
               }
               else if(size > 500)
               {
                   ui->Solution->setText(QString::fromLocal8Bit("课件文件太大，请重建一个。"));
               }
            }
        }
    }
}



void MainWindow::on_Update_clicked()
{
    new_updatelog=new UpdateLog;
    new_updatelog->show();
}

void MainWindow::on_OpenSource_clicked()
{
    new_opensource=new OpenSource;
    new_opensource->show();
}

void MainWindow::on_AboutLan_clicked()
{
    new_laninfo=new LanInfo;
    new_laninfo->show();
}
