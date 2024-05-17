//Tam sayinin asal bölenlerini dizide tutan programi yapin.

#include<stdio.h>

int main(){
	
	int sayi, i = 2, asal = 0;
	int asalBolen[asal];
	int tempSayi = sayi; //Sadece en asagidaki printf'i yazdirmak icin...
	
	printf("Sayiyi giriniz: ");
	scanf("%d", &sayi);
	
	while(sayi != 1){
		if(sayi % i == 0){
			asalBolen[asal] = i;
			asal++;
			sayi /= i;
		}
		else{
			i++;
		}
	}
	
	printf("%d sayisinin asal bolenleri: ", tempSayi);
	for(i = 0; i < asal; i++){
		printf("%d ", asalBolen[i]);
	}
}
