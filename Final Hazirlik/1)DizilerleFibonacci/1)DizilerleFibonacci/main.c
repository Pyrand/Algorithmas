#include<stdio.h>

//n sayısına kadar fibonacci serisi oluştur, bunu dizileri kullanarak yap.

int main(){
    
    int n;
    printf("Kac adet fibonacci serisi olusturulsun: ");
    scanf("%d", &n);
    
    int fibonacci[n];
    int temp, i;
    
    if(n == 1){
        fibonacci[0] = 1;
        printf("%d", fibonacci[0]);
    }
    else if(n == 2){
        fibonacci[0] = fibonacci[1] = 1;
        printf("%d %d", fibonacci[0], fibonacci[1]);
    }
    else{
        fibonacci[0] = fibonacci[1] = 1;
        printf("%d %d ", fibonacci[0], fibonacci[1]);
        
        for(i = 2; i < n; i++){
            
            temp = fibonacci[0]; //0. dizinin 3 oldugunu varsayalim
            fibonacci[0] += fibonacci[1]; //1. dizi de 2 olsun burada 2+3 diyerek bir sonraki fibonacci sayisini buluyoruz ve 0. dizi ustune yazıyoruz
            fibonacci[1] = temp; //1. diziyi de eski 0. dizi degerine esitliyoruz
            
            printf("%d ", fibonacci[0]); //0. diziyi yazıyoruz cunku degisen deger o
        }
    }
    
}
