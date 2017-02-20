#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[]){
    int key;
    if (argc != 2){
        printf("You have something missing!!!");
        return 1;
    }
    
    if (!(key = atoi(argv[1]))){
                return -1;
            }
    
    string str = GetString();
    
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        if ( 65 <= ((int)str[i]) && ((int)str[i]) <= 91 ){
            printf("%c",(char)( ( (((int)str[i] + key)-65) % 26 )+65) );
        }else if ( 97 <= ((int)str[i]) && ((int)str[i]) <= 123 ){
            printf("%c",(char)( ( (((int)str[i] + key)-97) % 26 )+97) );
        }else{
            printf("%c", str[i]);
        }
    }
    printf("\n");
    return 0;
}