/*

    Author - Thomas Maxwell
    pset1 - water.c
    
*/

#include <stdio.h>
#include <cs50.h>

int main(void)

{
    
     //banner
    printf ("***************************************************\n");
    printf ("*** How much water do you waste in the shower?? ***\n");
    printf ("***************************************************\n");
    
    //Program explaination
    printf ("This program shows how much water you use based on how much time you spend in the shower\n");

    
    printf ("How many minutes do you spend in the shower?\n");
    int minutes = GetInt();
    
    int water = ((1.5 * minutes) * 128) / 16;
    printf ("You used %d bottles of water\n", water);
    
    
}