#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){
    int  amount_int = 0,quarters = 0, dimes = 0, nickels = 0, pennies = 0;
    float amount = 0;
    printf("O hai! How much change is owed?\n");
    while((amount = GetFloat()) < 0){
        printf("How much change is owed?\n");
    }
    if (((int)amount) > 0){
        quarters = ((int)amount)*4;
        amount = amount - ((int)amount);
    }
    
    amount_int = round(amount*100);
    
    while(amount_int > 0){
        if (amount_int - 25 >= 0){
            quarters++;
            amount_int -= 25;
            continue;
        }
        if (amount_int - 10 >= 0){
            dimes++;
            amount_int -= 10;
            continue;
        }
        if (amount_int - 5 >= 0){
            nickels++;
            amount_int -= 5;
            continue;
        }
        if (amount_int - 1 >= 0){
            pennies++;
            amount_int -= 1;
            continue;
        }
    }
    printf("%i\n", (quarters+dimes+nickels+pennies));
    
    
    return 0;
}