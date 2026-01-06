//
// Created by Emre on 18.12.2025.
//

#ifndef FLEXIDICTIONARY_FLEXIDICTIONARY_H
#define FLEXIDICTIONARY_FLEXIDICTIONARY_H
#include <stdio.h>

typedef struct
{
    char ingilizce[50];
    char turkce[50];
    char kullanici_turkce[50];
    char kullanici_ingilizce[50];
    int sorgu_sayisi;

}Kelimelist;

//Karşılama kısmı için gerekli olan fonksiyon
void menu();

//seçimi döücek foksiyon
int secimiver();

//Dosyadaki bilgileri okuyup rame çekicek fonksiyon
int dosyaoku(Kelimelist* kelime, int kapasite);

void tumdosyayaz(Kelimelist* Kelime,int sayac);

#endif //FLEXIDICTIONARY_FLEXIDICTIONARY_H