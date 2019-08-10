#ifndef BACKINGUP_H
#define BACKINGUP_H

#include <QDialog>
#include <QTimer>
#include "mainwindow.h"
namespace Ui {
class backingup;
}

class backingup : public QDialog
{
    Q_OBJECT

public:
    explicit backingup(QWidget *parent = nullptr);
    ~backingup();

private:
    Ui::backingup *ui;
    MainWindow *mainwindow;

private slots:
    void changetext();
    void finish();
    void addprogress();
    QString getTextFromFile(QString filepath);
    void setTextToFile(QString filepath,QString str);
    void transferTextData(QString origin_filepath,QString target_filepath);
};

#endif // BACKINGUP_H
