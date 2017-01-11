/*

    Author - Thomas Maxwell
    pset1 - mario.c
    
*/


#include <stdio.h>
#include <cs50.h>

int main(void)

{
    
     //banner
    printf ("*********************************\n");
    printf ("*** Build a pyramid for Mario ***\n");
    printf ("*********************************\n");
    
    int pyramid = 0; //initial variable 
    
    do
    {
        printf ("Enter a number to represent the pyramid height for Mario to Climb:\n");
        pyramid = GetInt();
        
        if (pyramid == 0)
        {
            return 0;
        }
    }
    
    while (pyramid < 1 || pyramid > 23);
    
    for (int x = 0; x < pyramid; x++) //number of rows to print
    {
        for (int y = 0; y < pyramid - x - 1; y++) //prints spaces
        {
            printf ("%s", " ");
        }
            for (int z = 0; z < x + 2; z++) //prints #
            {
                printf ("#");
            }
            
            printf ("\n");
            
    }
    return 0; 
}