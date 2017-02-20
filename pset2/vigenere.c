#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>



int main(int argc, string argv[]){
    string key, str;
    int n, j;
    if (argc != 2){//Checks if the user inputs only 2 arguments on the command line
        printf("You have something missing!!!");
        return 1;
    }
    
    key = argv[1];
    
    n = strlen(key);
    
    int keys [n];
    //filling the heys' array. AND. Checks if the key contains only letters. Return 1 if it's invalid.
    for (int i = 0 ; i < n; i++){
        if (( 65 <= ((int)key[i]) && ((int)key[i]) <= 91)){
            keys[i] = ((int)key[i]) - 65;
        }else if ( 97 <= ((int)key[i]) && ((int)key[i]) <= 123 ){
            keys[i] = ((int)key[i]) - 97;
        }else{
             printf("The key must be only letters!!!");
            return 1;
        }  
    }
    
    str = GetString(); 
    j = 0;
    //Vigenere Cipher.
    for (int i = 0, m = strlen(str); i < m; i++)
    {
        if ( 65 <= ((int)str[i]) && ((int)str[i]) <= 91 ){
            printf("%c",(char)( ( (((int)str[i] + (keys[ (j++) % n ]))-65) % 26 )+65) );
        }else if ( 97 <= ((int)str[i]) && ((int)str[i]) <= 123 ){
            printf("%c",(char)( ( (((int)str[i] + (keys[ (j++) % n ]))-97) % 26 )+97) );
        }else{
            printf("%c", str[i]);
        }
    }
    printf("\n");
    return 0;
}
