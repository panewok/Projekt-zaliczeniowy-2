#include "tworzenie_postaci_123.h"
#include "ui_tworzenie_postaci_123.h"
#include "rozgrywka123.h"
#include "QFile"
#include "QTextStream"
#include "QDebug"
#include "obiekty.h"
#include <iostream>
#include <cstdlib>

Tworzenie_Postaci_123::Tworzenie_Postaci_123(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Tworzenie_Postaci_123)
{
    ui->setupUi(this);
    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/QT/projekty/Baza danych/Zapis.db");
    if(!mydb.open()){
    ui->textBrowser_18->append("Zapis nie możliwy");
    }
    else {
    ui->textBrowser_18->append("Zapis możliwy");
    }
}
QString czar;
int brak_many;
int nr_czaru;
QString sprawdzenie_ataku;
int atak;
//pochowek gracza;
Postac gracz;
Postac enemy;
int walka(Postac &gracz1, Postac &mob){
if (gracz1.hp >0){
if (gracz1.predkosc >= mob.predkosc){
//uzycie_wybranego_ataku(gracz, enemy);
mob.hp=mob.hp-gracz1.sila;
        if(mob.hp > 0){
        atak_enemy(gracz, enemy);
            if(gracz1.hp <= 0){
            gracz1.hp =0;
            return gracz1.hp;
            }
        }
        else {
        gracz.lvl_swiata();
        gracz.regeneracja_mama();
        return mob.hp;
        }
        }
else {
atak_enemy(gracz, enemy);
if (gracz1.hp > 0){
//uzycie_wybranego_ataku(gracz, enemy);
mob.hp=mob.hp-gracz1.sila;
    if (mob.hp > 0){
    return gracz1.hp, mob.hp;
    }
    else {
    gracz.lvl_swiata();
    gracz.regeneracja_mama();
    }
}
else {
gracz1.hp =0;
return gracz1.hp;
}
}
}
}
int czarowanie(Postac &gracz1, Postac &mob){
if(gracz1.hp >0 && mob.hp > 0){
brak_many=0;
nr_czaru=0;
if (czar == "Kula ognia" && gracz1.mana >= 3){
nr_czaru = 1;
mob.hp = mob.hp - 6 + 6*gracz1.lvl_word;
gracz1.mana = gracz1.mana - 3;
if (mob.hp <= 0){
gracz.regeneracja_mama();
gracz.lvl_swiata();
}
}
else if (czar == "Błyskawica" && gracz1.mana >= 4){
nr_czaru = 2;
mob.hp = mob.hp - 8 + 8*gracz1.lvl_word;
gracz1.mana = gracz1.mana - 4;
if (mob.hp <= 0){
gracz.regeneracja_mama();
gracz.lvl_swiata();
}
}
else if (czar == "Pomniejsze leczenie 10hp" && gracz1.mana >=3){
nr_czaru =3;
gracz1.hp = gracz1.hp + 10 + 5*gracz1.lvl_word;
gracz1.mana = gracz1.mana - 3;
    if (gracz1.hp > gracz1.hp_max){
    gracz1.hp = gracz1.hp_max;
    }
}
else if (czar == "Całkowite leczenie" && gracz1.mana >=10){
nr_czaru=4;
gracz1.hp = gracz1.hp + 10 + 5*gracz1.lvl_word;
gracz1.mana = gracz1.mana - 10;
    if (gracz1.hp > gracz1.hp_max){
    gracz1.hp = gracz1.hp_max;
    }
}
else if (czar == "Ziemny pocisk" && gracz1.mana >= 7){
nr_czaru=5;
mob.hp = mob.hp - 12 + 12*gracz1.lvl_word;
gracz1.mana = gracz1.mana - 7;
if (mob.hp <= 0){
gracz.regeneracja_mama();
gracz.lvl_swiata();
}
}
else {
brak_many++;
}
}
return (gracz1.hp, gracz1.mana, brak_many, nr_czaru, mob.hp);
}
int atak_enemy(Postac &gracz1, Postac &mob){
gracz1.hp = gracz1.hp - mob.sila;
}
int wybor_ataku(Postac &gracz1){
if(sprawdzenie_ataku == "Szybki atak"){
atak = 1;
gracz1.predkosc = gracz1.predkosc + 10;
}
if (sprawdzenie_ataku == "Silny atak") {
atak = 2;
}
if (sprawdzenie_ataku == "Strzał z łuku"){
atak =3;
}
return atak, gracz1.predkosc;
}
//int uzycie_wybranego_ataku(Postac &gracz1, Postac &mob){
//if(atak == 1 && mob.hp > 0 && gracz1.hp > 0){
//mob.hp = mob.hp - gracz1.sila;
//gracz1.predkosc = gracz1.predkosc - 10;
//atak=0;
//return mob.hp;
//}
//if (atak == 2) {
//mob.hp = mob.hp - gracz1.sila + 5;
//atak=0;
//return mob.hp;
//}
//if (atak == 3){
//    atak=0;
//    if (atak == 3 && 2*gracz1.predkosc >= mob.predkosc){
//    mob.hp = mob.hp - 2*gracz1.sila;
//    return mob.hp;
//    }
//    else {
//    mob.hp = mob.hp - gracz1.sila;
//    return mob.hp;
//    }
//}
//}
Tworzenie_Postaci_123::~Tworzenie_Postaci_123()
{
    delete ui;
}
void Tworzenie_Postaci_123::on_pushButton_clicked()
{
    gracz.pkt_sila_plus();
    ui->textBrowser_2->setText(QString::number(gracz.pkt));
    ui->textBrowser_3->setText(QString::number(gracz.sila));
    ui->textBrowser_17->setText(QString::number(gracz.pkt));
}


void Tworzenie_Postaci_123::on_pushButton_2_clicked()
{
    gracz.pkt_sila_minus();
    ui->textBrowser_2->setText(QString::number(gracz.pkt));
    ui->textBrowser_3->setText(QString::number(gracz.sila));
}


void Tworzenie_Postaci_123::on_pushButton_3_clicked()
{
    gracz.pkt_predkosc_plus();
    ui->textBrowser_2->setText(QString::number(gracz.pkt));
    ui->textBrowser_4->setText(QString::number(gracz.predkosc));
    ui->textBrowser_17->setText(QString::number(gracz.pkt));
}


void Tworzenie_Postaci_123::on_pushButton_4_clicked()
{
    gracz.pkt_predkosc_minus();
    ui->textBrowser_2->setText(QString::number(gracz.pkt));
    ui->textBrowser_4->setText(QString::number(gracz.predkosc));
}


void Tworzenie_Postaci_123::on_pushButton_5_clicked()
{
    gracz.pkt_hp_plus();
    ui->textBrowser_2->setText(QString::number(gracz.pkt));
    ui->textBrowser_5->setText(QString::number(gracz.hp_max));
    ui->textBrowser_17->setText(QString::number(gracz.pkt));
}


void Tworzenie_Postaci_123::on_pushButton_6_clicked()
{
    gracz.pkt_hp_minus();
    ui->textBrowser_2->setText(QString::number(gracz.pkt));
    ui->textBrowser_5->setText(QString::number(gracz.hp_max));
}


void Tworzenie_Postaci_123::on_pushButton_7_clicked()
{
    gracz.pkt_mana_plus();
    ui->textBrowser_2->setText(QString::number(gracz.pkt));
    ui->textBrowser_6->setText(QString::number(gracz.mana_max));
    ui->textBrowser_17->setText(QString::number(gracz.pkt));
}


void Tworzenie_Postaci_123::on_pushButton_8_clicked()
{
    gracz.pkt_mana_minus();
    ui->textBrowser_2->setText(QString::number(gracz.pkt));
    ui->textBrowser_6->setText(QString::number(gracz.mana));
}


void Tworzenie_Postaci_123::on_pushButton_11_clicked()
{
    if(gracz.blokada_edycji ==0)
    {
    gracz.klasa = 1;
    ui->textBrowser_13->setText("Mag");
}
}


void Tworzenie_Postaci_123::on_pushButton_10_clicked()
{
    if(gracz.blokada_edycji ==0)
    {
    gracz.klasa = 2;
    ui->textBrowser_13->setText("Wojownik");
    }
}


void Tworzenie_Postaci_123::on_pushButton_12_clicked()
{
    gracz.imie = ui->lineEdit_imie->text();
    gracz.wybor_klasy();
    ui->textBrowser_4->setText(QString::number(gracz.predkosc));
    ui->textBrowser_6->setText(QString::number(gracz.mana_max));
    ui->textBrowser_3->setText(QString::number(gracz.sila));
    ui->textBrowser_5->setText(QString::number(gracz.hp_max));

    ui->textBrowser_25->setText(QString::number(gracz.hp) + "/" + QString::number(gracz.hp_max));
    ui->textBrowser_27->setText(QString::number(gracz.mana) + "/" + QString::number(gracz.mana_max));
    ui->textBrowser_19->setText(QString::number(gracz.lvl_word));
    ui->textBrowser_17->setText(QString::number(gracz.pkt));

}


void Tworzenie_Postaci_123::on_textEdit_textChanged()
{

}


void Tworzenie_Postaci_123::on_pushButton_13_clicked() // zapis
{
    gracz.imie = ui->lineEdit_imie->text();
    QSqlQuery query;
    query.exec("UPDATE Zapis SET sila = "+QString::number(gracz.sila)+"");
    query.exec("UPDATE Zapis SET predkosc = "+QString::number(gracz.predkosc)+"");
    query.exec("UPDATE Zapis SET hp = "+QString::number(gracz.hp)+"");
    query.exec("UPDATE Zapis SET hp_max = "+QString::number(gracz.hp_max)+"");
    query.exec("UPDATE Zapis SET mana = "+QString::number(gracz.mana)+"");
    query.exec("UPDATE Zapis SET mana_max = "+QString::number(gracz.mana_max)+"");
    query.exec("UPDATE Zapis SET lvl = "+QString::number(gracz.lvl_postaci)+"");
    query.exec("UPDATE Zapis SET lvl_word = "+QString::number(gracz.lvl_word)+"");
    query.exec("UPDATE Zapis SET klasa = "+QString::number(gracz.klasa)+"");
    query.exec("UPDATE Zapis SET blokada = "+QString::number(gracz.blokada_edycji)+"");
    query.exec("UPDATE Zapis SET pkt = "+QString::number(gracz.pkt)+"");
    query.exec("UPDATE Zapis SET imie = '"+gracz.imie+"'");
    ui->textBrowser_18->append("Zapis postaci poprawny");
}


void Tworzenie_Postaci_123::on_pushButton_19_clicked()
{
    gracz.nastawy();
    ui->textBrowser_18->setText("");
    ui->textBrowser_2->setText(QString::number(gracz.pkt));
    ui->textBrowser_3->setText(QString::number(gracz.sila));
    ui->textBrowser_4->setText(QString::number(gracz.predkosc));
    ui->textBrowser_5->setText(QString::number(gracz.hp));
    ui->textBrowser_6->setText(QString::number(gracz.mana));
}


void Tworzenie_Postaci_123::on_pushButton_15_clicked() // WALKA
{
    sprawdzenie_ataku = ui->comboBox->currentText();
    wybor_ataku(gracz);
    walka(gracz, enemy);
    ui->textBrowser_2->setText(QString::number(gracz.pkt));
    ui->textBrowser_25->setText(QString::number(gracz.hp) + "/" + QString::number(gracz.hp_max));
    ui->textBrowser_27->setText(QString::number(gracz.mana) + "/" + QString::number(gracz.mana_max));
    ui->textBrowser_19->setText(QString::number(gracz.lvl_word));
    ui->textBrowser_17->setText(QString::number(gracz.pkt));
    if(enemy.hp > 0 && gracz.hp > 0){
    ui->textBrowser_18->append("Pozostałe życie potwora: " + QString::number(enemy.hp));
    }
    if(enemy.hp <= 0 && gracz.hp > 0) {
    ui->textBrowser_18->append("Pokonano przeciwnika, otrzymujesz punkt rozwoju postaci");
    }
    if(gracz.hp <= 0) {
    ui->textBrowser_18->append("Twój bohater " + (gracz.imie) + " został pokonany, stwórz nowego bohatera i ponownie rozpocznij rozgrywkę <br/> <br/> <br/> <br/>");
    }


}


void Tworzenie_Postaci_123::on_pushButton_16_clicked() // pierwsza lokacja
{
    enemy.tworzenie_pajaka();
    ui->textBrowser_18->append("Spotkano pająka o statystykach");
    ui->textBrowser_18->append("Życie: " + QString::number(enemy.hp));
    ui->textBrowser_18->append("Siła: " + QString::number(enemy.sila));
    ui->textBrowser_18->append("Prędkość: " + QString::number(enemy.predkosc));
}


void Tworzenie_Postaci_123::on_textBrowser_18_textChanged() // zbędne
{

}


void Tworzenie_Postaci_123::on_pushButton_14_clicked() // czary
{
    czar = ui->comboBox->currentText();
    czarowanie(gracz, enemy);
    if(brak_many > 0){
    ui->textBrowser_18->append("Brak many");
    }
    else if (nr_czaru == 1) {
    ui->textBrowser_18->append("Użyto czaru: Kula ognia, zadano " + QString::number(6 + 6*gracz.lvl_word) + " obrażeń, koszt czaru " + QString::number(3) + "punktów many <br/>");
    if(enemy.hp > 0){
    ui->textBrowser_18->append("Pozostałe życie potwora: " + QString::number(enemy.hp));
    }
    else{
    ui->textBrowser_18->append("Pokonano przeciwnika, otrzymujesz punkt rozwoju postaci");
    ui->textBrowser_19->setText(QString::number(gracz.lvl_word));
    ui->textBrowser_17->setText(QString::number(gracz.pkt));
    }
    }
    else if (nr_czaru == 2) {
    ui->textBrowser_18->append("Użyto czaru: Błyskawica, zadano " + QString::number(8 + 8*gracz.lvl_word) + " obrażeń, koszt czaru " + QString::number(4) + "punktów many <br/>");
    if(enemy.hp > 0){
    ui->textBrowser_18->append("Pozostałe życie potwora: " + QString::number(enemy.hp));
    }
    else{
    ui->textBrowser_18->append("Pokonano przeciwnika, otrzymujesz punkt rozwoju postaci");
    ui->textBrowser_19->setText(QString::number(gracz.lvl_word));
    ui->textBrowser_17->setText(QString::number(gracz.pkt));
    }
    }
    else if (nr_czaru == 3) {
    ui->textBrowser_18->append("Użyto czaru: Pomniejsze leczenie, przywrócono " + QString::number(10 + 5*gracz.lvl_word) + " hp, koszt czaru " + QString::number(3) + "punktów many <br/>");
    }
    else if (nr_czaru == 4) {
    ui->textBrowser_18->append("Użyto czaru: Całkowite leczenie, przywrócono zdrowie do maksymalnego poziomu " + QString::number(gracz.hp_max) + " hp, koszt czaru " + QString::number(10) + "punktów many <br/>");
    }
    else if (nr_czaru == 5) {
    ui->textBrowser_18->append("Użyto czaru: Ziemny pocisk, zadano " + QString::number(12 + 12*gracz.lvl_word) + " hp, koszt czaru " + QString::number(7) + "punktów many <br/>");
    if(enemy.hp > 0){
    ui->textBrowser_18->append("Pozostałe życie potwora: " + QString::number(enemy.hp));
    }
    else{
    ui->textBrowser_18->append("Pokonano przeciwnika, otrzymujesz punkt rozwoju postaci");
    ui->textBrowser_19->setText(QString::number(gracz.lvl_word));
    ui->textBrowser_17->setText(QString::number(gracz.pkt));
    }
    }
    ui->textBrowser_27->setText(QString::number(gracz.mana) + "/" + QString::number(gracz.mana_max));
}


void Tworzenie_Postaci_123::on_pushButton_18_clicked() // druga lokacja
{
    enemy.tworzenie_olbrzyma();
    ui->textBrowser_18->append("Spotkano olbrzyma o statystykach");
    ui->textBrowser_18->append("Życie: " + QString::number(enemy.hp));
    ui->textBrowser_18->append("Siła: " + QString::number(enemy.sila));
    ui->textBrowser_18->append("Prędkość: " + QString::number(enemy.predkosc));
}


void Tworzenie_Postaci_123::on_pushButton_17_clicked() // trzecia lokacja
{
    enemy.tworzenie_wampira();
    ui->textBrowser_18->append("Spotkano wampira o statystykach");
    ui->textBrowser_18->append("Życie: " + QString::number(enemy.hp));
    ui->textBrowser_18->append("Siła: " + QString::number(enemy.sila));
    ui->textBrowser_18->append("Prędkość: " + QString::number(enemy.predkosc));
}


void Tworzenie_Postaci_123::on_pushButton_9_clicked()
{
    mydb.close();
}


void Tworzenie_Postaci_123::on_pushButton_20_clicked() // wczytanie
{
QSqlQuery query;
query.exec("SELECT * FROM Zapis");
while (query.next()) {
gracz.imie = query.value(0).toString();
gracz.sila = query.value(1).toInt();
gracz.predkosc = query.value(2).toInt();
gracz.hp = query.value(3).toInt();
gracz.hp_max = query.value(4).toInt();
gracz.mana = query.value(5).toInt();
gracz.mana_max = query.value(6).toInt();
gracz.lvl_postaci = query.value(7).toInt();
gracz.lvl_word = query.value(8).toInt();
gracz.klasa = query.value(9).toInt();
gracz.blokada_edycji = query.value(10).toInt();
gracz.pkt = query.value(11).toInt();
ui->textBrowser_18->append("Wczytano posatć");
ui->textBrowser_2->setText(QString::number(gracz.pkt));
ui->textBrowser_3->setText(QString::number(gracz.sila));
ui->textBrowser_4->setText(QString::number(gracz.predkosc));
ui->textBrowser_5->setText(QString::number(gracz.hp_max));
ui->textBrowser_6->setText(QString::number(gracz.mana_max));
if(gracz.klasa == 1){
ui->textBrowser_13->setText("Mag");
}
if(gracz.klasa == 2){
ui->textBrowser_13->setText("Wojownik");
}
ui->textBrowser_25->setText(QString::number(gracz.hp) + "/" + QString::number(gracz.hp_max));
ui->textBrowser_27->setText(QString::number(gracz.mana) + "/" + QString::number(gracz.mana_max));
ui->textBrowser_19->setText(QString::number(gracz.lvl_word));
ui->textBrowser_17->setText(QString::number(gracz.pkt));
ui->lineEdit_imie->setText(gracz.imie);
}
}

