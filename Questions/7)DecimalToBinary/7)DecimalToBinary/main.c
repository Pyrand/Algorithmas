// Decimal sayıyı binary’e çeviren uygulamayı yap.

#include<stdio.h>
#include<string.h>

#define MAX 50

int main(){
    
    int sayi, i = 0, j, binarys[MAX];
    
    printf("Sayiyi girin: ");
    scanf("%d", &sayi);
    
    while(sayi != 0){
        
        if(sayi % 2 == 0){ //Eğer sayi 2ye tam bolunuyorsa binary kismina 0 eklenir
            sayi /= 2;
            binarys[i] = 0;
        }
        else{  //Eger 2ye tam bolunmuyorsa 1 eklenir
            sayi /= 2;
            binarys[i] = 1;
        }
        
        i++;
    }
    
    for(j = i - 1 ; j >= 0 ; j--){  //Binary kisimlari tersten yazdirilir.
        printf("%d ", binarys[j]);
    }
}
