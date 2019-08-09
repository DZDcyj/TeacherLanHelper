#ifndef SAVING_H
#define SAVING_H

#include <QDialog>

namespace Ui {
class Saving;
}

class Saving : public QDialog
{
    Q_OBJECT

public:
    explicit Saving(QWidget *parent = nullptr);
    ~Saving();

private:
    Ui::Saving *ui;
};

#endif // SAVING_H
