//A program that reads a number and then produces the sum (explicitly) of all the numbers from 1 up to the current number, for all numbers up to the value that was entered.

#include<stdio.h>

int main(){
    int sayi, i, j;
    
    printf("Hangi sayiya kadar toplansin: ");
    scanf("%d", &sayi);
    
    for(i = 1; i <= sayi; i++){
        int toplam = 0;
        for(j = 1; j <= i; j++){
            if(i == j){
                toplam += j;
                printf("%d = %d\n", j, toplam);
            }
            else{
                toplam += j;
                printf("%d + ", j);
            }
        }
    }
}
