//Eskenar dortgen cizen uygulamayi yapin.

#include<stdio.h>

int main(){
    
    int yukseklik, i, j;
    
    printf("Yuksekligi giriniz: ");
    scanf("%d", &yukseklik);
    
    for(i = 1; i <= yukseklik; i++){
        
        for(j = 1; j <= yukseklik - i; j++){
            printf(" ");
        }
        
        for(j = 1; j <= yukseklik; j++){
            if(i == 1 || i == yukseklik || j == 1 || j == yukseklik){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        
        printf("\n");
    }
    
}
