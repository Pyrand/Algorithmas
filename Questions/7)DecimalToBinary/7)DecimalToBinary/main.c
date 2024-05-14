// Decimal sayıyı binary’e çeviren uygulamayı yap.

#include<stdio.h>
#include<string.h>

#define MAX 50

int main(){
    
    int sayi, i = 0, j, binarys[MAX];
    
    printf("Sayiyi girin: ");
    scanf("%d", &sayi);
    
    while(sayi != 0){
        
        if(sayi % 2 == 0){
            sayi /= 2;
            binarys[i] = 0;
        }
        else{
            sayi /= 2;
            binarys[i] = 1;
        }
        
        i++;
    }
    
    for(j = i - 1 ; j >= 0 ; j--){
        printf("%d ", binarys[j]);
    }
}
