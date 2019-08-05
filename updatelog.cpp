#include "updatelog.h"
#include "ui_updatelog.h"

UpdateLog::UpdateLog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateLog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowCloseButtonHint|Qt::MSWindowsFixedSizeDialogHint);
    setFixedSize(this->width(),this->height());     // 固定窗口大小
}

UpdateLog::~UpdateLog()
{
    delete ui;
}
