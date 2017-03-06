/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#define _XOPEN_SOURCE 700
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"


int count = 0;
//Structures to be used to composed the dictionary
typedef struct node{
    bool is_word;
    struct node* next[27];
}node;

node* root;

void loadWord(char* word, node* nextNode); //Function added for me to add words.
char converToLowerCase(char character); //Convert To LowerCase all UpperCase Characteres
void unLoadAllChild(node* nextNode); //I'm going to impliment Depth-first
/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    int pos = 0;
    int i = 0;
    node* nextNode = root;
   
    while(nextNode != NULL && *(word + i) != '\0'){
            
            pos = (int) converToLowerCase(*(word + i)) - 97;
            
            if (pos < 0)
                pos = 26;
                
            nextNode = nextNode->next[pos];
            i++;
    }
    
    if (*(word + i) == '\0' && nextNode != NULL){
        if (nextNode->is_word)
            return true;
    }
    
    return false;
}


//Transform the letter Uppercase to LowerCase
char converToLowerCase(char character){
    if (character >= 'A' && character <= 'Z'){
        character += 32;
    }
    return character;
}


/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // TODO
    root = malloc(sizeof(node));
    FILE* inFileFictionary = fopen(dictionary, "r");
    
    if (inFileFictionary == NULL){
        printf("Something went wrong\n");
        return false;
    }
    
    char char_read = '\0';
    int length = 0;
    
    
     while(1){
        char* word = malloc(LENGTH + 1);
        //This loop is to find each word and put it in to word pointer
        while( ((char_read = fgetc(inFileFictionary)) != 10) && (char_read != EOF) ){
            *(word + (length++)) = char_read;
        }
        
        *(word+length) = '\0'; //Add the end of word to each word
        
        // Word found
         if (length > 0){ 
                loadWord(word, root); //load each word  
            count++;
         }
        
         // getout if the EOF is found
         if (char_read == EOF){ 
             break;
         }
         length = 0;
         free(word);
    }
    
            
    fclose(inFileFictionary);
    
    if (count > 0)
        return true;
    return false;
}

// 39 -- ' (para mi va a ser el lugar 26)
void loadWord(char *word, node* nextNode){
    char firstChar = *word;
    if (firstChar != '\0'){
        int pos = ((int)firstChar) - 97;
        if (pos < 0)
            pos = 26;
        
        if  (nextNode->next[pos] == NULL){
            nextNode->next[pos] = malloc(sizeof(node));
        }
        loadWord((word + 1), nextNode->next[pos]);
    }else{
        nextNode->is_word = true;
    }
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    
    return count;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    unLoadAllChild(root);
    return true;
}

void unLoadAllChild(node* nextNode){
    node* tmp;
    int i = 0;
    while(i < 27){
        tmp = nextNode->next[i];
        if (tmp != NULL){
            unLoadAllChild(tmp);
        }
        i++;
        free(tmp);
    }
}


//check50 2015.fall.pset5.speller dictionary.c dictionary.h Makefile