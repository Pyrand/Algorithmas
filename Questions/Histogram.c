// A program that reads numbers from an array and graphs the information in the form of a bar chart or histogram.

#include<stdio.h>

int main(){
    
    int n, i, j;
    
    printf("Dizi boyutunu giriniz: ");
    scanf("%d", &n);
    int dizi[n];
    
    for(i = 0; i < n; i++){
        printf("%d. sayiyi giriniz: ", i+1);
        scanf("%d", &dizi[i]);
    }
    
    printf("Element\tValue\tHistogram\n");
    for(i = 0; i < n; i++){
        printf("%d\t\t%d\t\t", i+1, dizi[i]);
        for(j = 0; j < dizi[i]; j++){
            printf("*");
        }
        printf("\n");
    }
}
