/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // TODO: Handling the arguments. These must be 2 or 3. Otherwise, the program shows you how to use it.
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // TODO: This line takes the first argument and converts it to int.
    int n = atoi(argv[1]);

    // TODO: Initializing the function to proceed to generate the random numbers.
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));  //Going to generate the same random numbers if doesn't change the input of number type . Otherwise, it going to generate others numbers
    }
    else
    {
        srand48((long int) time(NULL));     //Going to generate random numbers each time.
    }

    // TODO: Generate n random numbers and prints it. Each number generated is multiply by Limit( Because drand48 generate numbers between 0.0 1.0). 
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}