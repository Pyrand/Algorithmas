//Girilen float sayilarin ondalik kismini degistiren program
//NOT: Floatın integer-decimal kisimlarinin baska degisken icinde tutulmasi cok ekstra. Daha kisa yapilabilir deneyin...

#include<stdio.h>

int main(){
	float num1, num2, num1int, num2int, num1dec, num2dec, temp;;
	
	printf("Enter the num1: ");
	scanf("%f", &num1);
	printf("Enter the num2: ");
	scanf("%f", &num2);
	
	num1int = (int)num1; //Float degerlerin integer kismi
	num2int = (int)num2;
	
	num1dec = num1 - num1int; //Float degerlerin decimal kismi
	num2dec = num2 - num2int;
	
	num1int = num1int + num2dec; //Decimal kisimlarini degistirip topluyorum 
	num2int = num2int + num1dec;
	
	printf("Baslangic: num1 = %.3f / num2 = %.3f\n", num1, num2);
	printf("Degismis Hali: num1 = %.3f / num2 = %.3f", num1int, num2int);
	
	return 0;
}
