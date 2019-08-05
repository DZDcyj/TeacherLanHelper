#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "about.h"
#include "updatelog.h"
#include "opensource.h"
#include "laninfo.h"
#include <QDesktopServices>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
    about *new_about;
    UpdateLog *new_updatelog;
    OpenSource *new_opensource;
    LanInfo *new_laninfo;
private slots:
    void on_About_clicked();

    void on_Check_clicked();

    void on_Update_clicked();

    void on_OpenSource_clicked();

    void on_AboutLan_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
