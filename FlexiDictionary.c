#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FlexiDictionary.h"

void menu()
{
    printf("   FLEXI DICTIONARY\n");
    printf("----------------------\n");
    printf("---------MENU---------\n");
    printf("----------------------\n\n\n");
}

int secimiver()
{
    int secim;
    printf("1-Tüm sözlüğü görüntülemek için\n");
    printf("2-Kelime sorgusu yapmak için\n");
    printf("3-Kelime eklemek için\n");
    printf("Lütfen Geçerli Bir seçim yapınız:");
    scanf("%d",&secim);
    return secim;
}