#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    //prompts the user for their name
    //printf("Hello stranger, what is your name?\n");
    string name = GetString();
    
    //prints the first letter in the name in uppercase
    printf("%c", toupper(name[0]));
    
    //loops to find the space between the first and last name
    for (int i = 0; i < strlen(name); i++)
    {
        if (name[i] == ' ')
        {
            printf("%c", toupper(name[i + 1]));
        }
    }
    
    printf("\n");
}