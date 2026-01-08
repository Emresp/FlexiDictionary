
# FlexiDictionary

FlexiDictionary, C programlama dili ile geliştirilmiş, dinamik bellek yönetimi (malloc/realloc) kullanan, kişiselleştirilebilir ve kalıcı (persistent) bir İngilizce-Türkçe sözlük uygulamasıdır. Kullanıcıların kendi kelimelerini ekleyebildiği, sistemdeki mevcut kelimelere notlar düşebildiği ve tüm verilerin dosya tabanında (TXT) saklandığı hibrit bir yapıya sahiptir.

## Özellikler

- 💾 **Tam Kalıcılık (File Persistence):** Program kapanırken RAM'deki güncel verileri (eklenen/değişen) dosyaya geri yazar.
- 🧠 **Dinamik Bellek Yönetimi:** Sabit bir dizi yerine `realloc` ile hafıza (RAM) ihtiyaca göre otomatik genişletilir.
- ⚡ **Hibrit Ekleme Sistemi:** Kelime sistemde varsa günceller, yoksa yeni kayıt açar.
- 🔍 **Akıllı Arama:** Girilen kelimeyi hem İngilizce hem Türkçe hem de Kullanıcı notlarında arar.
- 🇹🇷 **UTF-8 Desteği:** Türkçe karakterler (ç, ğ, ı, ö, ş, ü) sorunsuz desteklenir.
- ✨ **Temiz Arayüz (UX):** Her işlemden sonra ekran temizlenir ve sonuçlar okunaklı sunulur.

  
## Kullanılan Teknolojiler

**Dil:** C 

**IDE:** CLion / CMake

**Yapılar:** Structs, Pointers, File I/O

**Kütüphaneler:** stdio.h, stdlib.h, string.h, windows.h

  
## Yükleme 

benim projem'i github üzerinden kurabilirsiniz

```bash 
git clone https://github.com/Emresp/FlexiDictionary.git
cd FlexiDictionary
```
    
## Kullanım/Örnekler

Program ana menüsü üzerinden 4 temel işlem yapılabilir:

1. **Listele:** Tüm sözlüğü (Sistem ve Kullanıcı verileri dahil) ekrana döker.
2. **Sorgula:** Kelimenin anlamını ve kaç kez arandığını gösterir.

3. **Ekle:** - Kelime veritabanında YOKSA: Yeni kayıt açar.

   - Kelime veritabanında VARSA: Sadece kullanıcı notu kısmını günceller.
4. **Çıkış:** Tüm verileri kaydeder ve programı kapatır.

  
## Yazar

- [@Emresp](https://github.com/Emresp) - Yazılım Müh. 1. Sınıf Öğrencisi (github)
- [@Emre Ayözcan](www.linkedin.com/in/emre-ayözcan-571ba3387) - Yazılım Müh. 1. Sınıf Öğrencisi (Linkedin)

  