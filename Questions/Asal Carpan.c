//Girilen sayının asal çarpanlarını bul.

#include<stdio.h>

int main(){
    
    int sayi, i = 2;
    printf("Sayiyi giriniz: ");
    scanf("%d", &sayi);
    
    printf("Sayının asal çarpanları: ");
    
    while(sayi != 1){
        
        if(sayi % i == 0){
            printf("%d ", i);
            sayi /= i;
        }
        else{
            i++;
        }
        
    }
}
