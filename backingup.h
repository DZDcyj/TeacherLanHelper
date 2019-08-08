#ifndef BACKINGUP_H
#define BACKINGUP_H

#include <QDialog>

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
};

#endif // BACKINGUP_H
