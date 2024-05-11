
//21100011022/OZGUR/KARA



#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    false,
    true
} bool;

int sonrasi = 0;
int genelayakkabi = 0;
int ayakkabisayisi;
int eklesay = 0;

typedef struct ayakkabi1
{
    int barkod;
    char marka[15];
    int ayakkabifiy;
    int ayakkabino;

} ana;

typedef struct ayrinti
{
    char ayakkabituru[15];
    int ayakkabisay;
    int id;
    ana *ayak;

} ext;
ext *ay;
ext *temp;
ana *yer;
ext *EKLE()
{
    printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<EKLEME EKRANI>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
    int i, j;
    int sayi;

    printf("Girilecek id ve barkodlarin essiz olmasina dikkat ediniz.");
    printf("\n");

    printf("Kac turlu(spor, dag vs.) ayakkabi girilecek: ");
    scanf("%d", &sayi);
    if (eklesay == 0)
    {
        eklesay++;
        temp = (ext *)malloc(sayi * sizeof(ext));
        ay = temp;
        if (ay == 'NULL')
            printf("yetersiz bellek !");

        for (i = 0; i < sayi; i++)
        {
            printf("%d. turu (spor, dag vs.) giriniz: ", i + 1);
            scanf("%s", (ay + i)->ayakkabituru);

            printf("Ayakkabi turune ait id'yi girin: ");
            scanf("%d", &(ay + i)->id);

            printf("Bu ayakkabilardan kac tane var: ");
            scanf("%d", &ayakkabisayisi);
            printf("\n");

            (ay + i)->ayakkabisay = ayakkabisayisi;
            (ay + i)->ayak = (ana *)malloc(ayakkabisayisi * sizeof(ana));

            for (j = 0; j < (ay + i)->ayakkabisay; j++)
            {
                printf("%d. ayakkabinin markasini giriniz: ", j + 1);
                scanf("%s", ((ay + i)->ayak + j)->marka);
                printf("Ayakkabilarin birim fiyatini(TL) giriniz: ");
                scanf("%d", &((ay + i)->ayak + j)->ayakkabifiy);
                printf("%d. ayakkabinin numarasini giriniz: ", j + 1);
                scanf("%d", &((ay + i)->ayak + j)->ayakkabino);
                printf("%d. ayakkabinin barkodunu giriniz: ", j + 1);
                scanf("%d", &((ay + i)->ayak + j)->barkod);
                printf("\n\n");
            }
        }
        genelayakkabi += sayi;
        return ay;
    }
    else
    {
        temp = (ext *)malloc((genelayakkabi)*sayi * sizeof(ext));
        for (i = 0; i < genelayakkabi; ++i)
        {
            *(temp + i) = *(ay + i);
        }
        ay = temp;
        if (ay == 'NULL')
            printf("yetersiz bellek !");


        if(sayi==1)
        {
            temp = (ext *)malloc((genelayakkabi)*sayi * sizeof(ext));


            printf("%d. turu (spor, dag vs.) giriniz: ", i - genelayakkabi+1);
            scanf("%s", (ay + genelayakkabi)->ayakkabituru);

            printf("Ayakkabi turune ait id'yi girin: ");
            scanf("%d", &(ay + genelayakkabi)->id);

            printf("Bu ayakkabilardan kac tane var: ");
            scanf("%d", &ayakkabisayisi);
            printf("\n");
            (ay + genelayakkabi)->ayakkabisay = ayakkabisayisi;
            (ay + genelayakkabi)->ayak = (ana *)malloc(ayakkabisayisi * sizeof(ana));

            for (j = 0; j < (ay + i)->ayakkabisay; j++)
            {
                printf("%d. ayakkabinin markasini giriniz: ", j + 1);
                scanf("%s", ((ay + genelayakkabi)->ayak + j)->marka);
                printf("Ayakkabilarin birim fiyatini(TL) giriniz: ");
                scanf("%d", &((ay + genelayakkabi)->ayak + j)->ayakkabifiy);
                printf("%d. ayakkabinin numarasini giriniz: ", j + 1);
                scanf("%d", &((ay + genelayakkabi)->ayak + j)->ayakkabino);
                printf("%d. ayakkabinin barkodunu giriniz: ", j + 1);
                scanf("%d", &((ay + genelayakkabi)->ayak + j)->barkod);
                printf("\n\n");
            }

            genelayakkabi += sayi;
            return ay;
        }





        for (i = genelayakkabi; i < (sayi * genelayakkabi); i++)
        {
            printf("%d. turu (spor, dag vs.) giriniz: ", i - genelayakkabi+1);
            scanf("%s", (ay + i)->ayakkabituru);

            printf("Ayakkabi turune ait id'yi girin: ");
            scanf("%d", &(ay + i)->id);

            printf("Bu ayakkabilardan kac tane var: ");
            scanf("%d", &ayakkabisayisi);
            printf("\n");
            (ay + i)->ayakkabisay = ayakkabisayisi;
            (ay + i)->ayak = (ana *)malloc(ayakkabisayisi * sizeof(ana));

            for (j = 0; j < (ay + i)->ayakkabisay; j++)
            {
                printf("%d. ayakkabinin markasini giriniz: ", j + 1);
                scanf("%s", ((ay + i)->ayak + j)->marka);
                printf("Ayakkabilarin birim fiyatini(TL) giriniz: ");
                scanf("%d", &((ay + i)->ayak + j)->ayakkabifiy);
                printf("%d. ayakkabinin numarasini giriniz: ", j + 1);
                scanf("%d", &((ay + i)->ayak + j)->ayakkabino);
                printf("%d. ayakkabinin barkodunu giriniz: ", j + 1);
                scanf("%d", &((ay + i)->ayak + j)->barkod);
                printf("\n\n");
            }
        }
        genelayakkabi += sayi;
        return ay;
    }
}

void LISTELE(ext *ay)
{
    int i, j, k;

    printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<LISTELEME EKRANI>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");

    for (i = 0; i < genelayakkabi; i++)
    {
        printf("\n\n--------------------------------------------------------\n\n");
        printf("AYAKKABI TURU: %s\n", (ay + i)->ayakkabituru);
        printf("Ayakkabi turunun id'si: %d\n", (ay + i)->id);
        printf("Ayakkabi sayisi: %d\n", (ay + i)->ayakkabisay);
        printf("\n");

        for (j = 0; j < (ay + i)->ayakkabisay; j++)
        {
            printf("%d. ayakkabinin barkodu: %d\n",j+1, ((ay + i)->ayak + j)->barkod);
            printf("%d. ayakkabinin markasi: %s\n",j+1, ((ay + i)->ayak + j)->marka);
            printf("%d. ayakkabinin fiyati: %d TL\n",j+1, ((ay + i)->ayak + j)->ayakkabifiy);
            printf("%d. ayakkabinin numarasi: %d\n\n",j+1, ((ay + i)->ayak + j)->ayakkabino);
        }

    }
}

ext *SILME(ext *ay, int genelayakkabi)
{
    int i, j, k, l, m;
    int silinecekbarkod;
    int silinecekid;
    bool bulundumu = false;
    ana *ayak;
    ana *yer;
    int ayakkabisay;
    printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<SILME   EKRANI>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");

    printf("Silmek istediginiz ayakkabi turunun id'sini giriniz: ");
    scanf("%d", &silinecekid);

    for (i = 0; i < genelayakkabi; i++)
    {

        if ((ay + i)->id == silinecekid)
        {
            printf("Silmek istediginiz ayakkabinin barkodunu giriniz: ");
            scanf("%d", &silinecekbarkod);
            ayakkabisay = (ay + i)->ayakkabisay;

            for (j = 0; j < ayakkabisay; ++j)
            {
                if (((ay + i)->ayak + j)->barkod == silinecekbarkod)
                {
                    bulundumu = true;
                    if ((ay+i)->ayakkabisay==1)
                    {
                        (ay + i)->ayakkabisay = ayakkabisay - 1;
                        (ay+i)->ayak=NULL;
                        return ay;
                    }
                    (ay + i)->ayakkabisay = ayakkabisay - 1;


                    yer = (ana *)malloc((ayakkabisay) * sizeof(ana));
                }
            }
        }
    }
    if (!bulundumu)
    {
        printf("Girdiginiz verileri iceren bir ayakkabi bulunamadi !\n");
    }
    else
    {
        int say = 0;
        int say2;
        for (k = 0; k < genelayakkabi; ++k)
        {
            if ((ay + k)->id == silinecekid)
            {

                ayakkabisay = (ay + k)->ayakkabisay+1;
                for (l = 0; l < ayakkabisay; ++l)
                {

                    if (((ay + k)->ayak + l)->barkod == silinecekbarkod)
                    {
                        say2 = k;
                        continue;
                    }
                    else
                    {
                        *(yer + say) = *((ay + k)->ayak + l);
                        say++;
                    }
                }
            }
        }
        (ay + say2)->ayak = yer;
    }

    return ay;
}

ext *GUNCELLEME(ext *ay)
{
    int guncellenecekid, guncellenecekbarkod;
    int i, j;
    int ayakkabisay;
    bool guncel = false;
    printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<GUNCELLEME EKRANI>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");

    printf("Guncellemek istediginiz ayakkabi turunun id'sini giriniz: ");
    scanf("%d", &guncellenecekid);

    for (i = 0; i < genelayakkabi; i++)
    {

        if ((ay + i)->id == guncellenecekid)
        {
            printf("Guncellemek istediginiz ayakkabinin barkodunu giriniz: ");
            scanf("%d", &guncellenecekbarkod);
            ayakkabisay = (ay + i)->ayakkabisay;

            for (j = 0; j < ayakkabisay; ++j)

            {
                if (((ay + i)->ayak + j)->barkod == guncellenecekbarkod)

                    guncel = true;
            }
        }
    }

    if (!guncel)
    {
        printf("Girilen verilere ait sonuc bulunamadi !");

    }
    else
    {
        for (i = 0; i < genelayakkabi; i++)
        {
            if(((ay+i)->id)==guncellenecekid)
            {
                printf("Yeni turu (spor, dag vs.) giriniz: ");
                scanf("%s", (ay + i)->ayakkabituru);

                printf("Ayakkabi turune ait yeni id'yi girin: ");
                scanf("%d", &(ay + i)->id);
                printf("\n");

                for (j = 0; j < (ay + i)->ayakkabisay; ++j)
                {
                    if(((ay+i)->ayak+j)->barkod==guncellenecekbarkod)
                    {

                        printf("%d. ayakkabinin yeni markasini giriniz: ", j + 1);
                        scanf("%s", ((ay + i)->ayak + j)->marka);
                        printf("Ayakkabilarin yeni birim fiyatini(TL) giriniz: ",j+1);
                        scanf("%d", &((ay + i)->ayak + j)->ayakkabifiy);
                        printf("%d. ayakkabinin yeni numarasini giriniz: ", j + 1);
                        scanf("%d", &((ay + i)->ayak + j)->ayakkabino);
                        printf("%d. ayakkabinin yeni barkodunu giriniz: ", j + 1);
                        scanf("%d", &((ay + i)->ayak + j)->barkod);
                        printf("\n");
                    }
                }
                break;
            }
        }

    }
    return ay;
}
void BULMA(ext *ay)
{

    int bulunacakid;
    int i,j;
    int ayakkabisay;
    bool bul=false,bul2=false;

    printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<BULMA   EKRANI>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");

    printf("Bulmak istediginiz ture ait id'yi girin: ");
    scanf("%d",&bulunacakid);

    for(i=0; i<genelayakkabi; i++)
    {
        if((ay+i)->id==bulunacakid)
        {

            printf("\n\n--------------------------------------------------------\n\n");
            printf("Ayakkabi Turu: %s\n", (ay + i)->ayakkabituru);
            printf("Ayakkabi turunun id'si: %d\n", (ay + i)->id);
            printf("Ayakkabi Sayisi: %d\n\n", (ay + i)->ayakkabisay);
            ayakkabisay=(ay+i)->ayakkabisay;

            for(j=0; j<(ay+i)->ayakkabisay; ++j)
            {
                printf("%d. ayakkabinin markasi: %s\n",j+1, ((ay + i)->ayak + j)->marka);
                printf("%d. ayakkabinin numarasi: %d\n",j+1, ((ay +i)->ayak+j)->ayakkabino);
                printf("%d. ayakkabinin fiyati: %d\n",j+1, ((ay + i)->ayak + j)->ayakkabifiy);
                printf("%d. ayakkabinin barkodu: %d\n\n",j+1, ((ay + i)->ayak + j)->barkod);

                bul=true;

            }
            break;
        }
    }
    if(bul==false)
        printf("Girilen bilgilere sahip ayakkabi bulunamadi!");
}

void KDV(ext *ay)
{
    int toplam=0;
    float kdvorani,top=0.0;
    int i,j;
    int a;
    int ayakkabisay;

    printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<KDV HESAPLAMA EKRANI>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
//bu Fonksiyonda oranlar yüzde olarak degil normal yazilir. 18/100 fonksiyona 18 degil 0.18 girilir. Sebebi bu seklin daha sade ve guzel durdugunu dusunmem.
    printf("Kdv oranini girin (TL): ");
    scanf("%f",&kdvorani);
    printf("\n\n");
    printf("Kdv hesaplaniyor. . .\n\n");

    for(i=0; i<genelayakkabi; i++)
    {
        ayakkabisay=(ay+i)->ayakkabisay;
        for(j=0; j<(ay+i)->ayakkabisay; ++j)
        {
            a=((ay+i)->ayak+j)->ayakkabifiy;
            toplam+=a;
        }
    }




    printf("Ayakkabilardan alinacak toplam kdv: %.2f TL",toplam*kdvorani);
    toplam=0;

}

int main()
{

    printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<MENU   EKRANI>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

    int secim;
    int a=0;

    while(a==0)
    {

        printf("\n\n--------------------------------------------------------\n\n");
        printf("EKLEME(1)\n");
        printf("LISTELEME(2)\n");
        printf("SILME(3)\n");
        printf("GUNCELLEME(4)\n");
        printf("BULMA(5)\n");
        printf("KDV HESAPLAMA(6)\n");
        printf("CIKIS(7)");
        printf("\n\n--------------------------------------------------------\n");

        printf("Lutfen yapmak istediginiz secime bagli bir sayiya basin: ");
        scanf("%d",&secim);

        if(secim==1)
            ay=EKLE();

        else if(secim==2)
            LISTELE(ay);

        else if(secim==3)
            ay=SILME(ay,genelayakkabi);

        else if(secim==4)
            ay=GUNCELLEME(ay);

        else if(secim==5)
            BULMA(ay);

        else if(secim==6)
            KDV(ay);

        else if(secim==7)
            a++;

        else
        {
            printf("Eksik ya da hatali tuslama yaptiniz. Tekrar deneyiniz.");

        }
    }

    return 0;
}
