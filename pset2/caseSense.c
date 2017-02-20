#include <stdio.h>
#include <cs50.h>
#include <string.h>

//Prototype
int converToUpperCase(int);
int converToLowerCase(int);
int swapCase(int);


int main(void){
    printf("Give me a name!!\n");
    string name = GetString();
    printf("Chose an option, typing a letter in UpperCase!!\n");
    printf("U    ConverToUpperCase\n");
    printf("L    ConverToLowerCase\n");
    printf("S    SwapCase\n");
    char option;
    scanf("%c",&option);
    
    
    int n = strlen(name);
    int character;
    
    for (int i = 0; i < n; i++){
        character = (int)name[i];
        if ((65 <= character && character <= 93) || (97 <= character && character <= 123)){
            if (option == 'U'){
                printf("%c",(char)converToUpperCase(character));
            }else if (option == 'L'){
                printf("%c",(char)converToLowerCase(character));
            }else{
                printf("%c",(char)swapCase(character));
            }
        }else{
            printf("%c", (char)character);
        }
    }
    printf("\n");
    return 0;
}

int converToUpperCase(int character){
    if (97 <= character && character <= 123){
        character -= 32;
    }   
    return character;
}

int converToLowerCase(int character){
    if (65 <= character && character <= 93){
        character += 32;
    }   
    return character;
}

int swapCase(int character){
    int tmpCharacter = character;
    character = converToUpperCase(character);
    if (tmpCharacter == character){
        return converToLowerCase(character);
    }else{
        return character;
    }
}
