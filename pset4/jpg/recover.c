/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <unistd.h>

typedef uint8_t  BYTE;

//PROTOTYPES
void findPicture(BYTE*);
void printPicture(BYTE*);

int countPictures;
int open;
FILE* outPtr;

int main()
{
    //if (argc != 1){
    //    printf("This program doesn't allow you pass any argument");
    //    return 1;
    //}
    //Creating varibles
    
    BYTE* block = malloc(512);
    FILE* inPtr =  fopen("card.raw", "r");
    
    countPictures = 0;
    open = 0;
    
    if (inPtr == NULL){
        printf("An Error has occurred\n");
        return 1;
    }
    
    while((fread(block, 512, 1, inPtr)) > 0){//While we got a block of memory to read
        findPicture(block);
    }
    
    if (open == 1){
        fclose(outPtr);
    }
    fclose(inPtr);
    free(block);

    return 0;
}

void findPicture(BYTE* block){
    
    if ( (*(block + 0) == 0xff) && (*(block + 1) == 0xd8) && (*(block + 2) == 0xff) ){
        switch(*(block + 3)){
            case 0xe0:
            case 0xe1:
            {
                if (open == 1){
                    fclose(outPtr);
                    open = 0;
                }
                printPicture(block);
                countPictures++;
            }
        }
    }else{
        if (open == 1){
            printPicture(block);
        }
    }
}

void printPicture(BYTE* block){
    
    //Creating the picture file recovered.
    if (open == 0){
        char* title = malloc(8);
        if (countPictures < 10){
            sprintf(title, "00%d.jpg", countPictures);
        }else{
            sprintf(title, "0%d.jpg", countPictures);
        }
        outPtr = fopen(title, "w");
        if ( outPtr == NULL){
            printf("File %s couldn't be created\n", title);
            exit(2);
        }
        open = 1;
        free(title);
    }
     fwrite(block, 512 , 1, outPtr);
}
/*
case 0xe3:
            case 0xe4:
            case 0xe5:
            case 0xe6:
            case 0xe7:
            case 0xe8:
            case 0xe9:
            case 0xea:
            case 0xeb:
            case 0xec:
            case 0xed:
            case 0xee:
            case 0xef:
*/