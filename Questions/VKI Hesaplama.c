//VKI hesaplama uygulamasi yapin.
//NOT: Bu program tamamlanmamistir. Basit kisimlari kendiniz doldurabilirsiniz ama temel kod bu sekildedir.

#include<stdio.h>
#include<ctype.h>

int main(){
	int weight;
	float lenght, VKI;
	
	enum sexs{man, woman} sex;
	
	printf("Kilon: ");
	scanf("%d", &weight);
	printf("Boyun (Ondalikli gir): ");
	scanf("%f", &lenght);
	printf("Cinsiyetin (Erkek 0 - Kadin 1): ");
	scanf("%d", &sex);
	
	VKI = weight / (lenght*lenght);
	printf("VKIN = %.3f\n", VKI);
	
	switch(sex){
		case 0:
			//Buraya erkegin VKI araligi iflerle yazilir.
			if(VKI < 18){
				printf("Zayifsin");
			}
			else if(VKI >= 18 && VKI < 24){
				printf("Iyisin...");
			}
			//else...
			
			break;
			
		case 1:
			//Buraya kadinlarin VKI araligi iflerle yazilir.
			if(VKI < 17.5){
				printf("Zayifsin");
			}
			else if(VKI >= 17.5 && VKI < 22.50){
				printf("Iyisin...");
			}
			//else...
			break;
			
		default:
			printf("Sadece iki cinsiyet var...");
			break;
	}
	
	return 0;
}
