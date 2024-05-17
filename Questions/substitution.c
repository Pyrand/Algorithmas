#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

#define SIZE 26

bool isKey(char cipherText[]){
	return(cipherText[0] != NULL); 
}

int main(){
	printf("ENCRYPTION MACHINE ver. 0.05\n\n");
	int choice, i, j, k;
	char plainText[SIZE] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','S','T','U','V','W','X','Y','Z'};
	char cipherText[SIZE + 1] = "";
	char text[100], newText[100];
	
	while(1){
		printf("\n***** MAIN MENU *****\n");
		printf("1) Enter key\n");
		printf("2) Encrypt message\n");
		printf("3) Decrypt message\n");
		printf("4) Exit\n");
		
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		if(choice == 1 || isKey(cipherText)){
			switch(choice){
			case 1: 
				again:
				printf("Please enter the key: ");
				scanf("%s", cipherText);
				
				if(strlen(cipherText) != SIZE){
					printf("ERROR: Key must contain 26 characters!\n");
					goto again;
				}
				
				for(i = 0; i < SIZE; i++){
					if(isdigit(cipherText[i])){
						printf("ERROR: Key must contain only alphabetic character!\n");
						goto again;
					}
				}
				
				for(i = 0; i < SIZE; i++){
					for(j = i + 1; j < SIZE; j++){
						if(cipherText[i] == cipherText[j]){
							printf("ERROR: Key must not contain repeated characters.\n");		
							goto again;
						}
					}
				}			
				break;
				
			case 2: printf("Enter a plain text (max 100 characters): ");
				getchar();
				fgets(text, sizeof(text), stdin);
				
				
				for(i = 0; i < strlen(text); i++){
					char character = text[i];							
					
					for(j = 0; j < SIZE; j++){
						if(plainText[j] == character){
							newText[i] = cipherText[j];
							break;
						}
					}
				}
				
		
				newText[i] = '\0';
				printf("%s\n", newText);
				break;
				
			} 
		}
		else{
			printf("ERROR: Please enter the key first!\n\n");
		}
		
		
	}
}
