#include "tworzenie_postaci_123.h"
#include "ui_tworzenie_postaci_123.h"
#include "rozgrywka123.h"
#include "QFile"
#include "QTextStream"
#include "QDebug"
#include <iostream>
#include <cstdlib>

class Postac
{
   public:
   QString imie = "brak";
   int sila;
   int predkosc;
   int hp;
   int hp_max;
   int mana;
   int mana_max;
   int pkt;
   int klasa;
   int blokada_edycji;
   int lvl_postaci;
   int lvl_word;

   int wybor_klasy()
   {
   if (klasa == 1 && blokada_edycji == 0)
   {
   mana = mana + 15;
   mana_max = mana;
   hp = hp + 15;
   hp_max = hp;
   blokada_edycji =1;
   }
   if (klasa == 2 && blokada_edycji == 0) {
   sila = sila + 10;
   predkosc = predkosc + 15;
   blokada_edycji = 1;
   }
   }

   int regeneracja_mama()
   {
   if(mana_max<mana){
   mana++;
   }
   }
   int lvl_swiata()
   {
   lvl_postaci++;
   pkt++;
   if(lvl_postaci==10){
   lvl_word++;
   lvl_postaci=lvl_postaci-10;
   }
   }
   int nastawy()
   {
       sila =5;
       predkosc = 10;
       hp = 20;
       hp_max = hp;
       mana = 10;
       mana_max = mana;
       pkt = 20;
       lvl_postaci = 0;
       lvl_word = 0;
       blokada_edycji =0;
   }

   int pkt_sila_plus()
    {
    if (pkt > 0)
    {
    sila++;
    pkt--;
    }
return (sila, pkt);
}
   int pkt_sila_minus()
   {
   if (blokada_edycji == 0 && sila > 0)
   {
   sila--;
   pkt++;
   return (sila, pkt);
   }
   }

   int pkt_predkosc_plus()
   {
   if (pkt > 0)
   {
   predkosc++;
   pkt--;
   }
   return (predkosc, pkt);
   }

   int pkt_predkosc_minus()
   {
   if (blokada_edycji == 0 && predkosc >0)
   {
   predkosc--;
   pkt++;
   return (predkosc, pkt);
   }
   }

   int pkt_hp_plus()
   {
   if (pkt > 0)
   {
   hp++;
   hp_max++;
   pkt--;
   }
   return (hp, hp_max, pkt);
   }

   int pkt_hp_minus()
   {
   if (blokada_edycji == 0 && hp > 1)
   {
   hp--;
   hp_max--;
   pkt++;
   }
   return (hp, hp_max, pkt);
   }

   int pkt_mana_plus()
   {
   if (pkt > 0)
   {
   mana++;
   mana_max++;
   pkt--;
   }
   return (mana, mana_max, pkt);
   }

   int pkt_mana_minus()
   {
   if (blokada_edycji == 0 && mana > 0)
   {
   mana_max--;
   mana--;
   pkt++;
   return (mana, mana_max, pkt);
   }
   }

   int tworzenie_pajaka()
   {
       sila =1 + (std::rand() % 4) + (std::rand() % 5)*lvl_word;
       predkosc =(std::rand() % 10) + (std::rand() % 10)*lvl_word;
       hp = 15 + (std::rand() % 5) + (std::rand() % 20)*lvl_word;
   }
   int tworzenie_olbrzyma()
   {
       sila =10 + (std::rand() % 7) + (std::rand() % 7)*lvl_word;
       predkosc =(std::rand() % 7) + (std::rand() % 6)*lvl_word;
       hp = 30 + (std::rand() % 10) + (std::rand() % 10)*lvl_word;
   }
   int tworzenie_wampira()
   {
       sila =9 + (std::rand() % 6) + (std::rand() % 6)*lvl_word;
       predkosc =(std::rand() % 15) + (std::rand() % 15)*lvl_word;
       hp = 12 + (std::rand() % 5) + (std::rand() % 20)*lvl_word;
   }

   friend int walka(Postac &gracz1, Postac &mob);
   friend int czarowanie(Postac &gracz1, Postac &mob);
   friend int wybor_ataku(Postac &gracz1);
   friend int uzycie_wybranego_ataku(Postac &gracz1, Postac &mob);
   friend int atak_enemy(Postac &gracz1, Postac &mob);
};
