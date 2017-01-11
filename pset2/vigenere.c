#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

//Creating a function
string cipher(string plain, string key);

int main (int argc, string argv[])
{
    //converts string to integer, 
    string key = argv[1];
    if (argc != 2) //if more than one parameters are entered, the program terminates
    {
        printf("Incorrect parameters\n");
        printf("Vignere <key>\n");
        return 1;
    }
    // loop checks for alphabeticalness
    for(int i = 0, j = strlen(key); i < j; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("You cannot use non-alphabetic characters\n");
            printf("vignere <key>\n");
            return 1;
        }
    }
    
    string plainText; 
    
     do
    {
        plainText = GetString();
    }
    //asks for users input until 1 character is entered
    while (strlen(plainText) == 0); 
    string result = cipher(plainText, key);
    printf("%s\n", result);
    return 0;
}

string cipher(string plain, string key)
{
    int key_length = strlen(key); //calculate lenght of key
    char* cipher = plain; //variable to hold ciphered string
    
    //loop through characters of the plain text
    for (int i = 0, j = 0, n = strlen(plain); i < n; i++)
    {
        if (isalpha(plain[i])) //check for alphabeticalness
        {
            //ASCII code calculation of the key position
            char key_Value = (isupper(key[j % key_length])) ? 'A' : 'a';
            
            //ASCII code calculation for the first letter
            char letter_value = (isupper(plain[i])) ? 'A' : 'a';
            
            //calculation with formula ci = (pi +kj) % 26
            cipher[i] = ((plain[i] - letter_value + (key[(j % key_length)] - key_Value)) % 26) + letter_value;
            
            //increments key position to the next letter
            j++;
        }
        else
        {
            cipher[i] = plain[i]; //non-alphabetical characters output
        }
    }
    return cipher; //ciphered string results
}