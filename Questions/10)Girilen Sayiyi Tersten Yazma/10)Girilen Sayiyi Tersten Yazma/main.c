//Girilen sayıyı tersten yazın.

#include<stdio.h>

int main(){
    
    int sayi, tersSayi = 0;
    
    printf("Sayi giriniz: ");
    scanf("%d", &sayi);
    
    while(sayi != 0){
        tersSayi *= 10;
        tersSayi = tersSayi + sayi % 10;
        sayi /= 10;
    }
    
    printf("Sayinin tersi: %d\n", tersSayi);
    
    
}
