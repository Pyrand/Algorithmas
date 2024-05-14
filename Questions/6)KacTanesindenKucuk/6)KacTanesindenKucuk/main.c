#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//0-99 arası rastgele 10 sayıyla doldurulan bir dizide dışarıdan girilen bir sayının dizinin elemanlarından kaç tanesinden küçük olduğunu bulan programı yaz.

int main(){
    
    int randomSayi[10], sayi, i, kucukOlan = 0;
    srand(time(NULL));
    
    for(i = 0; i < 10; i++){
        randomSayi[i] = rand() % 100;
    }
    
    printf("Bir sayı giriniz: ");
    scanf("%d", &sayi);
    
    for(i = 0; i < 10; i++){
        if(sayi < randomSayi[i]){
            kucukOlan++;
        }
    }
    
    printf("Girdigin %d sayisi %d adet random sayidan daha kucuk.", sayi, kucukOlan);
}
