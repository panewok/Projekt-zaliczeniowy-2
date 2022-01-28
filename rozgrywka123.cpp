#include "rozgrywka123.h"
#include "ui_rozgrywka123.h"
#include "rozgrywka123.h"
#include "QFile"
#include "QFile"
#include "QTextStream"
#include "QDebug"
#include "QString"
#include "QSettings"
#include "QVariant"

Rozgrywka123::Rozgrywka123(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rozgrywka123)
{
    ui->setupUi(this);

}


class Walka
{
public:
QString imie = "brak";
int sila =5;
int predkosc = 10;
int hp = 20;
int mana = 10;
int pkt = 20;
};

Rozgrywka123::~Rozgrywka123()
{
    delete ui;
}

void Rozgrywka123::on_pushButton_clicked()
{

}


void Rozgrywka123::on_pushButton_5_clicked()
{
    QString box = ui->comboBox->currentText();
    if( box == "czar 1")
    {
        ui->textBrowser_5->setText("czar 1");
    }

}

