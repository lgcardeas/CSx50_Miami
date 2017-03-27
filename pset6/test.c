#include <stdio.h>
#include <stdlib.h>


int main(void){
    char* str = "abc\" \r\n";
    if (*(str + 3) == '"'){
        printf("It's working \n");
    }
    int length = 0;
    while(*( str + (length++) ) != '\0');
    length--;
    printf("%s == %i\n", str, length);
    
    char* line = "GET";
    int index = 0;
    if ((*(line + (index++)) == 'G' &&
         *(line + (index++)) == 'E' &&
         *(line + (index++)) == 'T' && 
         *(line + (index++)) == ' ')){ //method == GET
        printf("Perfect.\n");
    }
    printf("%i", index);
    
    line = "HTTP/1.1s";
    index = -1;
    if ( ( *(line + index + 1) == 'H' && *(line + index + 2) == 'T' && 
            *(line + index + 3) == 'T' && *(line + index + 4) == 'P' && 
            *(line + index + 5) == '/' && *(line + index + 6) == '1' && 
            *(line + index + 7) == '.' && *(line + index + 8) == '1' && 
            ( *(line + index + 9) == ' ' ||  *(line + index + 9) == '\r') ) ){
     
    }
    
     length = 0;
     char* path = "cat.HtMl";
    
    while(*( path + (length++) ) != '\0'); //Calculate the length of the path
    length--;
    
    char* ptrResult = NULL;
    
    if (*(path + length - 3) == '.'){ //should be .js
        if (*(path + length - 2) == 'j' && *(path + length - 1) == 's' && *( path + length ) == '\0'){
            ptrResult = malloc(15);
            ptrResult = "text/javascrip";
            
        }
    } else if (*(path + length - 4) == '.'){ //should be .css or .gif or .ico or .jpg or .php or .png
         if (*(path + length - 3) == 'c' && *(path + length - 2) == 's' && *(path + length - 1) == 's' && *( path + length ) == '\0'){ //.css
            ptrResult = malloc(15);
            ptrResult = "text/css";
            
        } else if (*(path + length - 3) == 'g' && *(path + length - 2) == 'i' && *(path + length - 1) == 'f' && *( path + length ) == '\0'){ //.gif
            ptrResult = malloc(15);
            ptrResult = "image/gif";
            
        } else if (*(path + length - 3) == 'i' && *(path + length - 2) == 'c' && *(path + length - 1) == 'o' && *( path + length ) == '\0'){ //.ico
            ptrResult = malloc(15);
            ptrResult = "image/x-icon";
            
        } else if (*(path + length - 3) == 'j' && *(path + length - 2) == 'p' && *(path + length - 1) == 'g' && *( path + length ) == '\0'){ //.jpg
            ptrResult = malloc(15);
            ptrResult = "image/jpeg";
            
        } else  if (*(path + length - 3) == 'p' && *(path + length - 2) == 'h' && *(path + length - 1) == 'p' && *( path + length ) == '\0'){ //.php
            ptrResult = malloc(15);
            ptrResult = "text/x-php";
            
        } else if (*(path + length - 3) == 'p' && *(path + length - 2) == 'n' && *(path + length - 1) == 'g' && *( path + length ) == '\0'){ //.png
            ptrResult = malloc(15);
            ptrResult = "text/x-php";
            
        }
    } else if (*(path + length - 5) == '.'){ //should be .html
            ptrResult = malloc(15);
            ptrResult = "text/html";
            
    } 
    
    printf("ptrResult : %s \n", ptrResult);
}

/*

*/

/*
   */