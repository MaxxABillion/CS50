/*

    Author - Thomas Maxwell
    pset1 - greedy.c
    
*/


#include <stdio.h>
#include <cs50.h>
#include <math.h>

#define quarter 25;
#define dime 10;
#define nickel 5;


int main(void)
{
    //Variables
    float money = 0;
    int convert_cents = 0;
    int quarterc = 0;
    int dimec = 0;
    int nickelc = 0;
    int change = 0;
    int coin_total = 0;
    
    //banner
    printf ("**************************************\n");
    printf ("*** COINS!!! How many do you need? ***\n");
    printf ("**************************************\n");
    
    //Program instructions
    printf ("This program shows the number of coins you'll recieve for change\n");
    printf ("Enter amount in decimals. (i.e. 1.34)\n");
    
    //prompts user for input
    do
    {
        printf("How much do I owe you?  ");
        money = GetFloat();
        
        //error checking
        if (money == 0 || money <= 0)
        printf ("Plese enter a number greater than zero\n");
    }
    while (money <= 0);
    
    //converts to cents
    convert_cents = (int)round(money * 100);
    
    //quarters
    quarterc = convert_cents / quarter;
    change = convert_cents % quarter;
    
    //dimes
    dimec = change / dime;
    change = change % dime;
    
    //nickels
    nickelc = change / nickel;
    change = change % nickel;
    
    //change = pennies
    coin_total = quarterc + dimec + nickelc + change;
    
    printf("%d COINS!!!\n", coin_total);
    return 0;
}
