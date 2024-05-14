//n haneli bir sayının basamaklarının n’inci üstlerinin toplamı, sayının kendisine eşitse, böyle sayılara Armstrong sayı denir.
//Girilen sayının Armstrong sayısı olup olmadığını bulan programı yaz.

#include<stdio.h>
#include<math.h>

int main(){
    
    int basamakSayisi = 0, sayi, üstlerToplamı = 0;
    
    printf("Sayiyi giriniz: ");
    scanf("%d", &sayi);
    
    int asılSayı = sayi;
    int tempSayi = sayi;
    
    while(tempSayi != 0){
        basamakSayisi++;
        tempSayi /= 10;
    }
    
    tempSayi = sayi;
    
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
