#include <stdio.h>
#include <windows.h>

#include "FlexiDictionary.h"

int main(void)
{
    int secim;
    int sayac; // bu sayaç listemdeki anlık kelime sayısını tutmak için var
    int kapasite=355;
    /* Projem başlangıç olarak 350 kelime ile kullanıma başlayacaktır.
     * Kullanıcı tarafından geliştirilebilir bir sözlük olduğundan dolayı.
     * Kapasitemi 355 kelime olarak ayraladım bu sınır aşıldığı zaman ramde bu duruma realloc fonksiyonu ile yeni tahsis işlemi yapılcaktır.
     * Bu da demek oluyor ki projem listenin durumuna göre sadece yeteri kadar ram kullanıyor.
     * Böylece hem donanım rahat çalışmış oluyor hemde veritabanın daha büyük olduğu süreçler için arama işlemlerinde zamandan kazanmış oluyor kullanıcı.
     */


    //Türkçe çalışmak için
    SetConsoleOutputCP(65001); // Ekranı UTF-8
    SetConsoleCP(65001);       // Klavyeyi de UTF-8

    Kelimelist* kelime;


    kelime = (Kelimelist*)malloc(kapasite * sizeof(Kelimelist));



    sayac=dosyaoku(kelime,kapasite);

    printf("\n");

    printf("\nDevam etmek icin ENTER tusuna basin...");
    getchar();

    do
    {
        //Döngü her başa döndüğünde eski mesajları silmek için
        system("cls");

        menu();
        secim = secimiver();

        if(secim==1)
        {
            tumdosyayaz(kelime,sayac);
            //her şey anında olmasın diye
            printf("\nAna menuye donmek icin ENTER tusuna basin...");
            getchar();
        }

        else if(secim==2)
        {
            kelimesorgu(kelime,sayac);

            printf("\nAna menuye donmek icin ENTER tusuna basin...");
            getchar();
        }
        else if(secim==3)
        {
            kelime=kelimeekle(kelime,&sayac,&kapasite);
            //her şey anında olmasın diye
            printf("\nAna menuye dönmek icin ENTER tuşuna basın...");
            getchar();

        }
        else if(secim==4)
        {
            dosyayikaydet(kelime,sayac);

            //cmd anında kapanmasın diye
            printf("Çıkış Yapılıyor ENTER tuşuna basın");
            break;
        }
        else
        {
            printf("Gecersiz secim! Lutfen tekrar deneyin.\n");
            // Hata mesajını görmesi için kısa bekleme
            Sleep(1500);
        }

    }while(1);


    getchar();
    free(kelime);
    return 0;
}