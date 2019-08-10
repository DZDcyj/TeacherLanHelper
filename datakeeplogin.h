#ifndef DATAKEEPLOGIN_H
#define DATAKEEPLOGIN_H

#include <QDialog>

namespace Ui {
class dataKeepLogin;
}

class dataKeepLogin : public QDialog
{
    Q_OBJECT

public:
    explicit dataKeepLogin(QWidget *parent = nullptr);
    ~dataKeepLogin();

private slots:
    void on_OK_clicked();

    void on_Cancel_clicked();

private:
    Ui::dataKeepLogin *ui;

signals:
    void reset();
    void back();
    void openLan();
};

#endif // DATAKEEPLOGIN_H
