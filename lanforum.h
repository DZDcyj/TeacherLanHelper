﻿#ifndef LANFORUM_H
#define LANFORUM_H

#include <QDialog>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QDir>
namespace Ui {
class LanForum;
}

class LanForum : public QDialog
{
    Q_OBJECT

public:
    explicit LanForum(QWidget *parent = nullptr);
    ~LanForum();


private slots:

    void on_PutUp_clicked();


    void on_Clear_clicked();

private:
    Ui::LanForum *ui;
};

#endif // LANFORUM_H
