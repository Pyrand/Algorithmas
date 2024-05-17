//Tam sayinin bölenlerini dizide tutan programi yapin.

#include<stdio.h>

int main(){
	
	int sayi, i, bolen = 0; 
	int bolenler[bolen];
	
	printf("Sayi giriniz: ");
	scanf("%d", &sayi);
	
	for(i = 1; i <= sayi; i++){
		if(sayi % i == 0){
			bolenler[bolen++] = i;
		}
	}
	
	printf("%d sayisinin bolenleri: ", sayi);
	for(i = 0; i < bolen; i++){
		printf("%d ", bolenler[i]);
	}
}
