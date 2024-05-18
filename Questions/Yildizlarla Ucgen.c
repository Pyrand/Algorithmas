//Yıldızlarla eşkenar üçgen oluşturan uygulamayı yap.

#include<stdio.h>

int main(){
    
    int yukseklik, i, j;
    printf("Yukseklik kac olsun: ");
    scanf("%d", &yukseklik);
    
    for(i = 1; i <= yukseklik; i++){
        
        for(j = 1; j <= yukseklik - i; j++){
            printf(" ");
        }
        
        for(j = 1; j <= i * 2 - 1; j++){
            printf("*");
        }
        
        printf("\n");
    }
}
