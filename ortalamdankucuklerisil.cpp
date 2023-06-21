#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct dugum
{
    int data;
    struct dugum *next;
};


struct dugum* ekle(struct dugum *baslangic, int eklenen)
 {
    struct dugum *yeni = (struct dugum*) malloc(sizeof(struct dugum));
    yeni->data = eklenen;
    yeni->next = NULL;

    if (baslangic == NULL) 
	    {
	        baslangic = yeni;
	    } 
	else 
	    {
	        struct dugum *gecici = baslangic;
	        while (gecici->next != NULL) 
	        {
	            gecici = gecici->next;
	        }
	        gecici->next = yeni;
	    }

    return baslangic;
}



void yazdir(struct dugum *baslangic) 
{
    struct dugum *gecici = baslangic;

    while (gecici != NULL) 
	{
        printf("%d ", gecici->data);
        gecici = gecici->next;
    }
    printf("\n");
}
float ortalama(struct dugum *baslangic)
 {
    int toplam = 0;
    int sayac = 0;

    struct dugum *gecici = baslangic;
    while (gecici != NULL) 
    {
        toplam = toplam+gecici->data;
        sayac++;
        gecici = gecici->next;
    }
	float sonuc=toplam/sayac;
    return sonuc;
}
struct dugum* ortalamadankucuk(struct dugum *baslangic, float ort) 
{
    struct dugum *yeni = NULL;

    struct dugum *gecici = baslangic;
    while (gecici != NULL)
	 {
        if (gecici->data >= ort) 
			{
	            yeni = ekle(yeni, gecici->data);
	        }
        gecici = gecici->next;
    }

    return yeni;
}

int main() 
{
    srand(time(NULL));
	int n,sayi ;
    printf("Kac tane sayi istiyorsunuz : ");
    scanf("%d",&n);
    struct dugum *liste = NULL;
    for (int i = 0; i < n; i++)
	 {
        sayi = 10+rand() % 41;
        liste = ekle(liste, sayi);
    }

    printf("Listemiz: ");
    yazdir(liste);

    float ort = ortalama(liste);
    printf("Ortalama: %.2f\n", ort);
    struct dugum *yeniliste = ortalamadankucuk(liste, ort);

    printf("Ortalamadan kucuk olanlar siliniyor.. \n");
    printf("yeni liste : ");
    yazdir(yeniliste);
    

    return 0;
}
