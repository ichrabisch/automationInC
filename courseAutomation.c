#include <stdio.h>
#include <stdlib.h>
//STRUCT'LAR 
struct KISI{
        char ad_soyad[50];
        int yas;
};

struct KURS
{
        char kurs[10];
        int seviye;
};

typedef struct BILGILER
{
        struct KISI ogrenci;
        int id;
        struct KURS muzik;
}Bilgiler;

//struct BILGILER *ptr;
Bilgiler bilgi, *ptr;
struct KURS *psec;
int indexOgrenci = 0, sec_id;
//FONKSIYONLAR
void kursGor()
{
        int s_k;
        struct KURS p1={"Piyano", 1}, p2={"Piyano", 2}, p3={"Piyano", 3};
        struct KURS k1={"Keman", 1}, k2={"Keman", 2}, k3={"Keman", 3};
        struct KURS g1={"Gitar", 1}, g2={"Gitar", 2}, g3={"Gitar", 3};
        printf("1- %s seviye: %d \t 2- %s seviye: %d \t 3- %s seviye: %d \n", p1.kurs, p1.seviye, p2.kurs, p2.seviye, p3.kurs,p3.seviye);
        printf("4- %s seviye: %d \t 5- %s seviye: %d \t 6- %s seviye: %d \n", k1.kurs, k1.seviye, k2.kurs, k2.seviye, k3.kurs,k3.seviye);
        printf("7- %s seviye: %d \t 8- %s seviye: %d \t 9- %s seviye: %d \n", g1.kurs, g1.seviye, g2.kurs, g2.seviye, g3.kurs, g3.seviye);

        printf("Kurslarimizin tamami bu kadardir.\n");

}

void kursFiyat()
{
        int fiyat_kurs, yas_bilg;
        int fiyat1=150, fiyat2=300, fiyat3= 450;
        printf("\nFiyatini ogrenmek istediginiz kursu seciniz:\n");
        kursGor();
        printf("Seciminiz: ");
        scanf("%d", &fiyat_kurs);
        printf("\n-Fiyatlandirma icin yas girilmesi gerekmektedir!\nYas giriniz:\n");
        scanf("%d", &yas_bilg);

        if (fiyat_kurs==1 || fiyat_kurs==4 || fiyat_kurs== 7)
        {
                if(yas_bilg<=20)
                {
                        printf("\nAylik kurs fiyati: %d TL\n", fiyat1-50);
                }
                else{
                        printf("\nAylik kurs fiyati: %d TL\n", fiyat1);
                }
        }
        else if(fiyat_kurs==2 || fiyat_kurs==5 || fiyat_kurs== 8)
        {
                if(yas_bilg<=20)
                {
                        printf("\nAylik kurs fiyati: %d TL\n", fiyat2-50);
                }
                else{
                        printf("\nAylik kurs fiyati: %d TL\n", fiyat2);
                }
        }
        else if(fiyat_kurs==3 || fiyat_kurs==6 || fiyat_kurs== 9)
        {
               if(yas_bilg<=20)
                {
                        printf("\nAylik kurs fiyati: %d TL\n", fiyat3-50);
                }
                else{
                        printf("\nAylik kurs fiyati: %d TL\n", fiyat3);
                }
        }
        else
        {
                printf("\nKurs bulunamadi!");
        }
}

void ogrenciEkle()
{
        int age, num;
        printf("Kayit islemine hos geldiniz :) \n");
        printf("Lutfen ogrenci adi ve soyadini aralarinda '_' karakteri olacak sekilde  giriniz:");
        scanf("%s", &bilgi.ogrenci.ad_soyad);
        printf("\nLutfen ogrenci yas giriniz giriniz:");
        scanf("%d", &age);
        printf("\nLutfen ogrenci icin id giriniz: ");
        scanf("%d", &num);

        bilgi.id = num;
        bilgi.ogrenci.yas = age;

        //siradaki bos index alinir.
        int i = indexOgrenci;
        //daha sonraki kayit icin, boş index deger 1 arttirilir.
        indexOgrenci = indexOgrenci+1;
        //bos indexteki id degerine atama yapilir.
        (ptr+i)->id = bilgi.id;
        //bos indexteki ogrenci alanina atama yapilir.
        (ptr+i)->ogrenci = bilgi.ogrenci;
        printf("\nKayit islemi basarili!\n");
}

void ogrenciListele()
{
        for (int i = 0; i < indexOgrenci; i++)
        {
                if ((ptr+i)->id > 0)
                {
                        printf("\nOgrenci ID: %d\n", (ptr+i)->id);
                        printf("Ogrenci Ad Soyad: %s\n", (ptr+i)->ogrenci.ad_soyad);
                        printf("Ogrenci Yas: %d\n", (ptr+i)->ogrenci.yas);
                }
        }
        printf("\n\n***NOT***\n");
        printf("Kurslarimizi goruntulemek icin ana menuye gidiniz.\n");
        printf("Kurs fiyat bilgisi icin ana menuye gidiniz.\n\n");
        printf("\nButun kayitli ogrenciler listelenmistir!\n");
}

void ogrenciBilgiGuncelle()
{
        int guncelle_id;
        printf("Guncellenecek ogrenci id giriniz:");
        scanf("%d", &guncelle_id);

        for (int i = 0; i < indexOgrenci; i++)
        {
                if ((ptr+i)->id == guncelle_id)
                {
                        int age;
                        printf("Lutfen guncellenecek ogrenci adi ve soyadini aralarinda '_' karakteri olacak sekilde  giriniz:");
                        scanf("%s", (ptr+i)->ogrenci.ad_soyad);
                        printf("\nLutfen guncellenecek ogrenci yas giriniz giriniz:");
                        scanf("%d", &age);

                        (ptr+i)->ogrenci.yas = age;
                }
        }

        printf("\nBilgiler guncellenmistir!\n");
}

void ogrenciSil()
{
        int sil_id;
        printf("Silinecek ogrenci id giriniz:");
        scanf("%d", &sil_id);

        for (int i = 0; i < indexOgrenci; i++)
        {
                if ((ptr+i)->id == sil_id)
                {
                        (ptr+i)->id = 0;
                }
        }
        printf("\nSilme islemi basarili.\n");
}

int main()
{
        int control=1;
        int x;
        printf("\n***************************\n");
        printf("*MUZIK KURSUNA HOSGELDINIZ*");
        printf("\n***************************\n");
        ptr = (Bilgiler *) malloc(sizeof(Bilgiler));
        psec = (struct KURS *) malloc(sizeof(struct KURS));

        while (control!=0)
        {
        printf("\n");
        printf("Yapmak istediginiz islemi seciniz:\n");
        printf("Ogrenci eklemek icin 1 i\n");
        printf("Kayitli ogrencileri listelemek icin 2 yi\n");
        printf("Kayitli bilgi guncellemek icin 3 u\n");
        printf("Kayitli ogrenci silmek icin 4 u\n");
        printf("Kurslarimizi goruntulemek icin 5 i\n");
        printf("Kurs fiyat bilgisi almak icin 6 yi\n");
        printf("tuslayiniz->");
        scanf("%d", &x);
        if (x==1)
        {
                ogrenciEkle();
        }
        else if (x==2)
        {
                ogrenciListele();
        }
        else if (x==3)
        {
                ogrenciBilgiGuncelle();
        }
        else if (x==4)
        {
                ogrenciSil();
        }
        else if (x==5)
        {
                kursGor();
        }
        else if (x==6)
        {
                kursFiyat();
        }
        else
        {
                printf("Hatali sayi secimi!");
        }
        printf("\nAna menuye donmek icin 0 haric bir rakam, islemleri sonlandirmak icin 0 rakamini tuslayiniz: ");
        scanf("%d", &control);
        }
        return 0;
}
