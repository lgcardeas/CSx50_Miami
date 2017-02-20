#include <stdio.h>
#include <cs50.h>
#include <string.h>

//Prototype
int converToUpperCase(int);


int main(void){
    string name = GetString();
    int n = strlen(name);
    if (n >= 1){
        printf("%c",(char)converToUpperCase((int)name[0]));
    }
    
    for (int i = 1; i < n; i++){
        switch((int)name[i]){
            case 32: 
            case 45:
            case 39:
                printf("%c",(char)converToUpperCase((int)name[++i]));
                break;
            default:
                continue;
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