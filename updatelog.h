#ifndef UPDATELOG_H
#define UPDATELOG_H

#include <QDialog>

namespace Ui {
class UpdateLog;
}

class UpdateLog : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateLog(QWidget *parent = nullptr);
    ~UpdateLog();

private:
    Ui::UpdateLog *ui;
};

#endif // UPDATELOG_H
