#ifndef ADMINMENU_H
#define ADMINMENU_H

#include <QDialog>
#include <QSettings>

namespace Ui {
class AdminMenu;
}

class AdminMenu : public QDialog
{
    Q_OBJECT

public:
    explicit AdminMenu(QWidget *parent = nullptr);
    ~AdminMenu();

private slots:
    void on_AutoRecover_clicked(bool checked);

private:
    Ui::AdminMenu *ui;
};

#endif // ADMINMENU_H
