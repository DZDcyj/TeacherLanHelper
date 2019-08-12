#include "lanforum.h"
#include "ui_lanforum.h"
static QDir dir;
static QString path=dir.currentPath();
static QString filepath=path+"/comments.txt";
LanForum::LanForum(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LanForum)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowCloseButtonHint|Qt::MSWindowsFixedSizeDialogHint);
    setFixedSize(this->width(),this->height());     // 固定窗口大小
    QFile comments(filepath);
    if(comments.exists())
    {
        comments.open(QIODevice::ReadOnly|QIODevice::Text);
        QByteArray comment=comments.readAll();
        QString realComment=QString::fromLocal8Bit(comment);
        ui->Forum->setText(realComment);
        comments.close();
    }
    else
    {
        comments.open(QIODevice::WriteOnly);
        comments.close();
    }
}

LanForum::~LanForum()
{
    delete ui;
}


void LanForum::on_PutUp_clicked()
{
    QDir dir;
    QString path;
    path=dir.currentPath();
    QString comment,nickname;
    comment=ui->Message->toPlainText();
    nickname=ui->afterName->toPlainText();
    if(ui->Sensei->isChecked())
        nickname+=QString::fromLocal8Bit("先生");
    else if(ui->Classmate->isChecked())
        nickname+=QString::fromLocal8Bit("同学");
    else if(ui->Teacher->isChecked())
        nickname+=QString::fromLocal8Bit("老师");
    QString finalcomment=comment+QString::fromLocal8Bit("——")+nickname;
    QFile comments(filepath);
    QTextStream txtOutput(&comments);
    comments.open(QIODevice::Append|QIODevice::WriteOnly|QIODevice::Text);
    txtOutput<<endl<<finalcomment;
    comments.close();
    QFile Readcomments(filepath);
    Readcomments.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray Readcomment=Readcomments.readAll();
    QString realComment=QString::fromLocal8Bit(Readcomment);
    ui->Forum->setText(realComment);
    Readcomments.close();
    ui->Message->clear();
    ui->afterName->clear();
    ui->None->setChecked(true);
}

void LanForum::on_Clear_clicked()
{
    QFile comments(filepath);
    QTextStream txtOutput(&comments);
    comments.open(QIODevice::WriteOnly|QIODevice::Text);
    comments.close();
    comments.open(QIODevice::ReadOnly|QIODevice::Text);
    ui->Forum->setText(QString::fromLocal8Bit(comments.readAll()));
    comments.close();
}
