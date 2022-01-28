#include "rozgrywka.h"
#include "ui_rozgrywka.h"

Rozgrywka::Rozgrywka(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Rozgrywka)
{
    ui->setupUi(this);
}

Rozgrywka::~Rozgrywka()
{
    delete ui;
}
