//Girilen 4 basamakli sayiyi tersten yazdir.

#include<stdio.h>

int main(){
	int number, ones, tens, hundreds, thousands;
	
	again:
	printf("4 basamakli sayi gir: ");
	scanf("%d", &number);
	
	if(number < 1000 || number > 10000){
		printf("Gecersiz sayi!\n");
		goto again;
	}
	else{
		ones = number % 10;
		tens = (number / 10) % 10;
		hundreds = (number / 100) % 10;
		thousands = (number / 1000) % 10;
	}
	
	printf("Sayinin tersi: %d%d%d%d", ones,tens,hundreds, thousands);
	
	return 0;
}
