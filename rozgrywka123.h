#ifndef ROZGRYWKA123_H
#define ROZGRYWKA123_H

#include <QDialog>

namespace Ui {
class Rozgrywka123;
}

class Rozgrywka123 : public QDialog
{
    Q_OBJECT

public:
    explicit Rozgrywka123(QWidget *parent = nullptr);
    ~Rozgrywka123();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Rozgrywka123 *ui;
};

#endif // ROZGRYWKA123_H
