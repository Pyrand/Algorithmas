//Bir sayı gir ve bu sayının mükemmel sayı olup olmadığını belirle
//(Bir sayının kendisi hariç çarpanlarının toplamı, girilen sayıya eşitse bu sayı mükemmel sayıdır. Örneğin: 6, 26, 496)

#include<stdio.h>

int main(){
    
    int number, i, multiplierSum = 1;
    printf("Numberi gir: ");
    scanf("%d", &number);
    
    for(i = 2; i <= number / 2; i++){
        
        if(number % i == 0){
            multiplierSum += i;
        }
        
    }
    
    if(number == multiplierSum){
        printf("Bu sayi mukemmel sayidir!!");
    }
    else{
        printf("Bu sayi mukemmel sayi degildir :(");
    }
}
