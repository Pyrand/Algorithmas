//n sayısına kadar fibonacci serisi oluştur, bunu dizileri kullanarak yap.

#include<stdio.h>

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
            
            temp = fibonacci[0];
            fibonacci[0] += fibonacci[1];
            fibonacci[1] = temp;
            
            printf("%d ", fibonacci[0]);
        }
    }    
}
