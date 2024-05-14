#include<stdio.h>
#include<math.h>

//n haneli bir sayının basamaklarının n’inci üstlerinin toplamı, sayının kendisine eşitse, böyle sayılara Armstrong sayı denir.
//Girilen sayının Armstrong sayısı olup olmadığını bulan programı yaz.

int main(){
    
    int basamakSayisi = 0, sayi, üstlerToplamı = 0;
    
    printf("Sayiyi giriniz: ");
    scanf("%d", &sayi);
    
    int asılSayı = sayi; //Sayi degiskeni while icinde degisecegi icin son karsilastirma islemi bu degiskenle yapilacak
    int tempSayi = sayi; //While icinde gecici bi degiskene ihtiyacimiz oldugundan olusturduk
    
    
    //Burada basamak sayisini buluyoruz
    while(tempSayi != 0){
        basamakSayisi++;
        tempSayi /= 10;
    }
    
    tempSayi = sayi; //Yine while icin
    
    while(sayi != 0){
        tempSayi = sayi % 10;
        üstlerToplamı = üstlerToplamı + pow(tempSayi, basamakSayisi);
        sayi /= 10;
    }
    
    printf("Üstler toplami: %d \n", üstlerToplamı);
    
    if(asılSayı == üstlerToplamı){
        printf("Bu sayı Armstrong sayidir!");
    }
    else{
        printf("Bu sayi Armstrong sayi degildir.");
    }
    
}
