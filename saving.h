#ifndef SAVING_H
#define SAVING_H

#include <QDialog>
#include <QTimer>

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

private slots:
    void addProgress();
    void reset();
signals:
    void backtomenu();
};

#endif // SAVING_H
