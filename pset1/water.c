#include <stdio.h>
#include <cs50.h>

int main (void){
    int minutes, bottles;
    printf("minutes: ");
    minutes = GetInt();
    bottles = (minutes * 192) / 16;
    printf("bottles: %i\n", bottles);
    return 0;
}