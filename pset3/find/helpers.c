/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int begin = 0;
    int end = n;
    bool founded = false;
    int medium;
    // TODO: implement a searching algorithm
    while(!founded){
        medium = (begin + end) / 2;
        if (begin == medium){
            if (values[end - 1] == value){
                founded = true;
            }
            return founded;
        }
        if (value == values[medium]){
            founded = true;
        }else if (values[medium] > value){
            end = medium;
        } else {
            begin = medium;
        }
    }
    return founded;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    bool swapped = true;
    int tmp = 0;
    while(n > 0 && swapped){
        for (int i = 0 ; i < n - 1 ; i++){
            swapped = false;
            if (values[i] > values[i + 1]){
                tmp = values[i + 1]; 
                values[i + 1] = values[i];
                values[i] = tmp;
                swapped = true;
            }
        }
        n--;
    }
    
}