#include "lanforum.h"
#include "ui_lanforum.h"

LanForum::LanForum(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LanForum)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowCloseButtonHint|Qt::MSWindowsFixedSizeDialogHint);
    setFixedSize(this->width(),this->height());     // 固定窗口大小
    QFile comments("/comments");
    comments.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray comment=comments.readAll();
    QString realComment=QString::fromLocal8Bit(comment);
    ui->Forum->setText(realComment);
    comments.close();
}

LanForum::~LanForum()
{
    delete ui;
}


void LanForum::on_PutUp_clicked()
{
    // TODO
    QString comment,nickname;
    comment=ui->Message->toPlainText();
    nickname=ui->afterName->toPlainText();
    if(ui->Sensei->isChecked())
        nickname+=QString::fromLocal8Bit("先生");
    else if(ui->Classmate->isChecked())
        nickname+=QString::fromLocal8Bit("同学");
    else if(ui->Teacher->isChecked())
        nickname+=QString::fromLocal8Bit("老师");
    QString finalcomment=comment+QString::fromLocal8Bit("  ——")+nickname;
    QString runPath = QCoreApplication::applicationDirPath();
    QFile comments(runPath+"/comments.txt");
    comments.open(QIODevice::WriteOnly|QIODevice::Text);
}
