//Girilen bir dizideki elemanlari, siralarini bozmadan ama tekil olarak yeni bir diziye aktaran bir program yazin. Ornegin girdi {3, 3, 87, 56, 1, 87, 3, 2 } ise cikti {3, 87, 56, 1, 2 } olmalidir.

#include<stdio.h>
#include<stdbool.h>

int main(){
	
	int n, i, j, tekil = 0;
	printf("Dizinin boyutu kac olsun: ");
	scanf("%d", &n);

	int dizi[n], tekilDizi[n];
	
	for(i = 0; i < n; i++){
		printf("Dizinin %d. elemani: ", i+1);
		scanf("%d", &dizi[i]);
	}
	
	for(i = 0; i < n; i++){
		bool durum = true;
		for(j = 0; j < tekil; j++){
			if(dizi[i] == tekilDizi[j]){
				durum = false;
				break;
			}
		}
		if(durum){
			tekilDizi[tekil] = dizi[i];
			tekil++;
		}	 
	}

	printf("Tekil durumdaki dizi: ");
	for(i = 0; i < tekil; i++){
		printf("%d ", tekilDizi[i]);
	}
}
