#include "saving.h"
#include "ui_saving.h"

Saving::Saving(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Saving)
{
    ui->setupUi(this);
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint|Qt::FramelessWindowHint);
    setFixedSize(this->width(),this->height());     // 固定窗口大小
}

Saving::~Saving()
{
    delete ui;
}
