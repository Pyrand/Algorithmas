//Girilen tek kelimelik bir metnin harflerinin arasına “*” koyan bir program yazın.

#include<stdio.h>
#include<string.h>

int main(){
    
    int i, j = 0;
    char metin[30], yildizliMetin[60];
    
    printf("Metin giriniz (Max 30 harf): ");
    scanf("%s", metin);
    
    for(i = 0; i < strlen(metin); i++){
        yildizliMetin[j] = metin[i];
        j++;
        if(i < strlen(metin) - 1){
            yildizliMetin[j] = '*';
            j++;
        }
    }
    
    printf("Metnin yildizli hali: %s", yildizliMetin);
    
}
