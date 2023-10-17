#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if(argc != 2)//checking if there is 2 command line arguments
    {
        printf("ERROR\nUsage:./caesar cipher(non-negative integer)\n");
        return 1;
    }
    int n = strlen(argv[1]);
    for(int i = 0; i < n; i++)//checking if the cipher is a number
    {
        if(argv[1][i] < '0' || argv[1][i] > '9')
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int x = atoi(argv[1])%26;//converting argv[1] to an int
    string s = get_string("plaintext: ");//getting the text
    int c = strlen(s);
    for(int i = 0; i < c; i++)//changing letters
    {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <='Z'))//just change the letters, not pontuation or spaces
        {
            if(s[i] + x > 'z' || (s[i] + x > 'Z' && s[i] + x < 'a'))//quando completa uma volta
            {
                s[i] -= 26;
            }
            s[i] += x;
        }
    }
    printf("ciphertext: %s\n", s);//answer
}