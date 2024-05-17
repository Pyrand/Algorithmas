#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

#define SIZE 26

bool isKey(char cipherText[]){
	int i;
	
	for(i = 0; i < SIZE; i++){
		if(cipherText[i] == '\0'){
			return false;
		}
	} 
	
	return true;
}

int main(){
	printf("ENCRYPTION MACHINE ver. 1.1\n\n");
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
		
		
		if(choice == 1 || isKey(cipherText) || choice == 4){
			switch(choice){
			case 1: 
				printf("Please enter the key: ");
				getchar();
				fgets(cipherText, sizeof(cipherText), stdin);
				
				if(strlen(cipherText) != SIZE){
					printf("ERROR: Key must contain 26 characters!\n");
					continue;
				}
				
				for(i = 0; i < SIZE; i++){
					if(isdigit(cipherText[i])){
						printf("ERROR: Key must contain only alphabetic character!\n");
						continue;
					}
				}
				
				for(i = 0; i < SIZE; i++){
					for(j = i + 1; j < SIZE; j++){
						if(cipherText[i] == cipherText[j]){
							printf("ERROR: Key must not contain repeated characters.\n");		
							continue;
						}
					}
				}			
				break;
				
			case 2: printf("Enter a plain text (max 100 characters): ");
				getchar();
				fgets(text, sizeof(text), stdin);
								
				for(i = 0; i < strlen(text); i++){
					char character = text[i];		
					newText[i] = character;			
					
					if(isalpha(character)){
						char upperChar = toupper(character);
						
						for(j = 0; j < SIZE; j++){
							if(plainText[j] == upperChar){
								
								newText[i] = cipherText[j];
								
								if(islower(character)){
									newText[i] = tolower(newText[i]);
								}
								
								break;
							}
						}
					}										
				}
				
		
				newText[i] = '\0';
				printf("%s\n", newText);
				break;
				
			case 3: printf("Enter a cipher text (max 100 characters): ");
				getchar();
				fgets(text, sizeof(text), stdin);
								
				for(i = 0; i < strlen(text); i++){
					char character = text[i];		
					newText[i] = character;			
					
					if(isalpha(character)){
						char upperChar = toupper(character);
						
						for(j = 0; j < SIZE; j++){
							if(cipherText[j] == upperChar){
								
								newText[i] = plainText[j];
								
								if(islower(character)){
									newText[i] = tolower(newText[i]);
								}
								
								break;
							}
						}
					}										
				}
				
				newText[i] = '\0';
				printf("%s\n", newText);
				break;
				
			case 4: printf("\nExiting the program...\n");
				return 0;
			
			default: printf("Invalid choice try again...\n");
				break;
			} 
		}
		else{
			printf("ERROR: Please enter the key first!\n\n");
		}
		
		
	}
	
	return 0;
}

