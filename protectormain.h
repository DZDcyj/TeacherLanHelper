#ifndef PROTECTORMAIN_H
#define PROTECTORMAIN_H

#include <QDialog>
#include <QTimer>
#include "mainwindow.h"

namespace Ui {
class protectormain;
}

class protectormain : public QDialog
{
    Q_OBJECT

public:
    explicit protectormain(QWidget *parent = nullptr);
    ~protectormain();

private:
    Ui::protectormain *ui;
    MainWindow *mainwindow;

private slots:
   void secondminus();
   void on_Enter_clicked();
   void reset();
};

#endif // PROTECTORMAIN_H
