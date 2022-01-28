#ifndef ROZGRYWKA_H
#define ROZGRYWKA_H

#include <QMainWindow>

namespace Ui {
class Rozgrywka;
}

class Rozgrywka : public QMainWindow
{
    Q_OBJECT

public:
    explicit Rozgrywka(QWidget *parent = nullptr);
    ~Rozgrywka();

private:
    Ui::Rozgrywka *ui;
};

#endif // ROZGRYWKA_H
