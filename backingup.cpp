#include "backingup.h"
#include "ui_backingup.h"

backingup::backingup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::backingup)
{
    ui->setupUi(this);
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint|Qt::FramelessWindowHint);
    setFixedSize(this->width(),this->height());     // 固定窗口大小
}

backingup::~backingup()
{
    delete ui;
}
