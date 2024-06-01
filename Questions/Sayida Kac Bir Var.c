//Girilen sayinin binary formda kac adet 1 icerdigini bulun.
//NOT: Bu uygulama sadece 8 bitlik sayilar icindir daha buyuk sayilar icin i degeri degistirilebilir.
//NOT2: i degerinin 128 olması 8 bitlik sayilar üzerinden islem yapildigi icindir. Daha yuksek sayilar icin NOT dikkate alinmali.

#include<stdio.h>
#include<math.h>

int main(){
	unsigned int number, count = 0;
	
	printf("Sayi gir: ");
	scanf("%u", &number);
	
	for(int i = 128; i >= 1 ; i = i / 2){
		if(number >= i){
			count++;
			number = number - i;
		}
		
	}
	
	printf("Sayidaki toplam 1'ler: %u", count);
	
	return 0;
}
