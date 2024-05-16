//Girilen bir sayıya kadar kaç tane asal sayı olduğunu hesaplayan bir program yazın.

#include<stdio.h>
#include<stdbool.h>

bool asalKontrol(int sayi){
    int i;
    
    for(i = 2; i < sayi; i++){
        if(sayi % i == 0){
            return false;
        }
    }
    
    return true;
}

int asalSayım(int n){
    int i, asalSayi = 0;
    
    for(i = 2; i < n; i++){
        if(asalKontrol(i)){
            asalSayi++;
        }
    }
    
    return asalSayi;
}

int main(){
    
    int n;
    
    printf("Kaca kadar asal sayi alinsin: ");
    scanf("%d", &n);

    printf("%d. sayıya kadar toplam %d asal sayi var.", n, asalSayım(n));
}
