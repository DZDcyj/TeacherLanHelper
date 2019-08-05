#ifndef OPENSOURCE_H
#define OPENSOURCE_H

#include <QDialog>
#include <QDesktopServices>
#include <QString>
#include <QUrl>
#include <QFile>
#include <QWindow>
namespace Ui {
class OpenSource;
}

class OpenSource : public QDialog
{
    Q_OBJECT

public:
    explicit OpenSource(QWidget *parent = nullptr);
    ~OpenSource();

private slots:

    void on_OpenCourse_clicked();


    void on_BothOpen_clicked();

    void on_OpenPath_clicked();

private:
    Ui::OpenSource *ui;
};

#endif // OPENSOURCE_H
