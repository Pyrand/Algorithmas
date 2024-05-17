//Girilen sayının asal çarpanlarını bul.

#include<stdio.h>

int main(){
    
    int number, i = 2;
    printf("Number: ");
    scanf("%d", &number);
    
    printf("Sayının asal çarpanları: ");
    
    while(number != 1){
        
        if(number % i == 0){
            printf("%d ", i);
            number /= i;
        }
        else{
            i++;
        }
        
    }
}
