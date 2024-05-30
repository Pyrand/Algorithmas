//Iký cumleyi birlestirme

#include<stdio.h>
#include<string.h>

int main(){
	
	char msg[100] = "Hello World ";
	char msg2[] = "Herkese sellamlar babuslar";
	
	int bas = strlen(msg);
	int son = strlen(msg2);
	int i, j = 0;
	
	for(i = bas; i < bas + son; i++){		
		msg[i] = msg2[j];
		j++;					
	}
		
	printf("%s", msg);
}
