//Yıldızlarla eşkenar üçgen oluşturan uygulamayı yap.

#include<stdio.h>

int main(){
    
    int row, i, j;
    printf("Row kac olsun: ");
    scanf("%d", &row);
    
    for(i = 1; i <= row; i++){
        
        for(j = 1; j <= row - i; j++){
            printf(" ");
        }
        
        for(j = 1; j <= i * 2 - 1; j++){
            printf("*");
        }
        
        printf("\n");
    }
}
