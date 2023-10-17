#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(int argc, string argv[])
{
    if (argc != 2) //if the key is different than 1 argument
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (strlen(argv[1]) != 26) //if the key is different than 26 characters
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    int num[26];
    for (int i = 0; i < 26; i++) //save the key into a sequence of numbers from 0 to 25
    {
        if (argv[1][i] >= 'a' && argv[1][i] <= 'z') //saves lowercase
        {
            num[i] = argv[1][i] - 97;
        }
        else
        {
            if (argv[1][i] >= 'A' && argv[1][i] <= 'Z') //saves uppercase
            {
                num[i] = argv[1][i] - 65;
            }
            else
            {
                printf("The key must contain only letters\n"); //quit if there are non-letters characters
                return 1;
            }
        }
    }
    int c = 0;
    for (int i = 0; i < 26; i++) //checking if there are duplicate characters in the key
    {
        for (int l = i + 1; l < 26; l++)
        {
            if (num[i] == num[l])
            {
                c++;
            }
        }
        if (c != 0)
        {
            printf("There are duplicate characters in key\n");
            return 1;
        }
    }
    string text = get_string("plaintext: "); //getting input
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z') //gets the letter position and change with the key character
        {
            text[i] = 97 + num[(text[i] - 97)]; //lowercase
        }
        else
        {
            if (text[i] >= 'A' && text[i] <= 'Z') //uppercase
            {
                text[i] = 65 + num[(text[i] - 65)];
            }
        }
    }
    printf("ciphertext: %s\n", text);
}