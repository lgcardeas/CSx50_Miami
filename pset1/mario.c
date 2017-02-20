#include <stdio.h>
#include <cs50.h>

int main(void){
    int height, i, j = 0;
    printf("Height: ");
    while((height = GetInt()) < 0 || (height > 23)){
        printf("Height: ");
    }
    i = 0;
    while( i < height){
        j = height;
        while (j > i + 1){//Print blank spaces
            printf(" ");
            j--;
        }  
        j = 0;
        while(j <= i+1){//Print # simbols
            printf("#");
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}