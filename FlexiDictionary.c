//
// Created by Emre on 18.12.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FlexiDictionary.h"

#include <ctype.h>

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
    printf("4-Çıkış yapmak için\n");
    printf("Lütfen Geçerli Bir seçim yapınız:");
    scanf("%d",&secim);
    getchar();
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
        while (sayac<kapasite && fscanf(dosya,"%49[^;];%49[^;];%49[^;];%49[^;];%d\n",kelime[sayac].ingilizce,kelime[sayac].turkce,kelime[sayac].kullanici_ingilizce,kelime[sayac].kullanici_turkce,&kelime[sayac].sorgu_sayisi)==5)
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

//kullanıcı tüm listeyi görmek istediğinde çalışan fonksiyon
void tumdosyayaz(Kelimelist* kelime,int sayac)
{
    int i;
    printf("SİSTEM         KULLANICI\n");
    //Kelimeler sırasıyla for ile yazılır
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

void kelimesorgu(Kelimelist* Kelime, int sayac)
{

    //bulundumu değişkeninn amacı for bitince eğer sayı artmadıysa kelimenin bulunmadığı anlamına gelip hata mesajı vermek içindir
    int bulundumu=0;
    //kelimeyi düzenlerken taşma olmasın diye
    int uzunluk;
    char aranan_kelime[50];

    printf("Karşılığını görmek istediğiniz kelimeyi yazınız(TR/ENG)\n");
    printf("Kelime:");
    //scanf kullanmadık çünkü scanf boşluk görünce durur ve kelimenin devamını almaz fgets ile boşluk dahil 50 kelime kapasite verdik
    fgets(aranan_kelime, 50, stdin);
    //Ama fgest kullanıncada kelimenin sonunda \n işareti otomatik konulur
    //Bundan kurtulmak içinse aşağadaki fonksiyonu kullandık \n gördüğün yere 0 yari null koy diyoruz ve sadece kelime kalıyor
    aranan_kelime[strcspn(aranan_kelime, "\n")] = 0;

    uzunluk=strlen(aranan_kelime);

    for (int i=0; i<uzunluk; i++)
    {
        if (i==0)
        {
            //ilk harf için büyük
            aranan_kelime[i] = toupper(aranan_kelime[i]);
        }
        else
        {
            //diğer harfler için küçük
            aranan_kelime[i] = tolower(aranan_kelime[i]);
        }
    }



    for (int i = 0; i < sayac; i++)
    {
        if (strcmp(aranan_kelime,Kelime[i].ingilizce)==0||
            strcmp(aranan_kelime,Kelime[i].turkce)==0||
            strcmp(aranan_kelime,Kelime[i].kullanici_ingilizce)==0||
            strcmp(aranan_kelime,Kelime[i].kullanici_turkce)==0)

        {
            printf("SİSTEM         KULLANICI\n");
            printf("%s = %s || %s = %s \n",Kelime[i].ingilizce,Kelime[i].turkce,Kelime[i].kullanici_ingilizce,Kelime[i].kullanici_turkce);

            Kelime[i].sorgu_sayisi=Kelime[i].sorgu_sayisi+1;
            printf("Bu kelimeyi tam olarak %d kere sorguladınız",Kelime[i].sorgu_sayisi);
            bulundumu++;
        }
    }
    if (bulundumu==0)
    {
        printf("Aramış olduğunuz kelime veritabanında bulunamadı olduğundan eminseniz lütfen tekrar deneyiniz.");
    }

}