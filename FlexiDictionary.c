//
// Created by Emre on 18.12.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FlexiDictionary.h"

void menu()
{
    printf("\n   FLEXI DICTIONARY\n");
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

int dosyaoku(Kelimelist* kelime, int kapasite)
{
    FILE *dosya;

    dosya = fopen("dictionary.txt","r");

    int sayac=0;

    if(dosya != NULL){
        /*While döngüsünün şartına güvenlik önlemi aldık 2 tane
         *ilk olarak sayacımız kapasiteden az mı bunun amacı genişletme işlemi doğru şekilde yapılmış mı ? veri kaybını önelemek için önlem
         *İkinci olarak == 4 dememin sebebi fscanf'in dosya içinde 4 tane değer okuması lazım okuyamadığı takdirde okuma işlemeini durdurur
         *Bu basit gözüken önlemler programın çalışırken ya da veritabanına dışardan bir müdahele yapıldığında programın bozulmasını engellemek içindir.
         */
        while (sayac<kapasite && fscanf(dosya,"%49[^;];%49[^;];%49[^;];%49[^\n]\n",kelime[sayac].ingilizce,kelime[sayac].turkce,kelime[sayac].kullanici_ingilizce,kelime[sayac].kullanici_turkce)==4)
        {
            sayac++;

        }
        if(sayac>=kapasite)
        {
            printf("Uyarı: Kapasite dolduğu için tüm kelimeler yüklenemedi");
        }
        fclose(dosya);
        printf("%d kelime veritabanına yüklendi",sayac);

    }
    else
    {
        printf("No dictionary found");
    }
    return sayac;
}

void tumdosyayaz(Kelimelist* kelime,int sayac)
{
    int i;
    printf("SİSTEM         KULLANICI\n");
    for(i=0;i<sayac;i++)
    {
        if (strcmp("-",kelime[i].kullanici_ingilizce)==0)
        {
            printf("%s = %s || \n",kelime[i].ingilizce,kelime[i].turkce);
        }

        else
        {
            printf("%s = %s || %s = %s \n",kelime[i].ingilizce,kelime[i].turkce,kelime[i].kullanici_ingilizce,kelime[i].kullanici_turkce);
        }
    }

}