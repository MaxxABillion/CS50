#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//Gets key
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Valid key please\n");
        return 1;
    }
   
    int k = atoi(argv[1]);
    if (k < 0)
        {
            printf("Your key is invald, please enter another one!\n");
            return 1;
        }
        else
        {
        string text = GetString();
        for (int i = 0, n = strlen(text); i < n; i++)
            {
            if isupper(text[i])
                printf("%c", (((text[i] + k) - 65) % 26) + 65);
                  
            else if islower(text[i])
                printf("%c", (((text[i] + k) - 97) % 26) + 97);
            
            else
                printf("%c", text[i]);
            }
            printf("\n");
            return 0;
        }
    }
    

