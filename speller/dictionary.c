// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <math.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int NUMBER_TIMES_N = 2;
const unsigned int N = 26 * 26;
int valor_size = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    char *wordcopy = malloc ((LENGTH + 1) * sizeof(char));
    strcpy (wordcopy, word);
    int n = hash(wordcopy);
    node *tmp = table[n];
    while (tmp != NULL)
    {
        char test[46];
        strcpy (test, tmp->word);
        if (strcasecmp(wordcopy, tmp->word) == 0)
        {
            free(wordcopy);
            return true;
        }
        tmp = tmp->next;
    }
    free(wordcopy);
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int x = 0;
    for (int i = 0, j; i < NUMBER_TIMES_N; i++)
    {
        if ((word[i] >='a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z'))
        {
            j = toupper(word[i]) - 'A';
            x += j * pow(26, (NUMBER_TIMES_N - i - 1));
        }

    }
    return x;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char* wordcopy = malloc((LENGTH + 1) * sizeof(char));    //free wordcopy

    while (fscanf (file, "%s", wordcopy) != EOF)
    {
        node *temp = malloc(sizeof(node));
        if (temp == NULL)
        {
            unload();
            return false;
        }
        strcpy (temp->word, wordcopy);
        int n = hash(wordcopy);
        if (table[n] == NULL)
        {
            temp->next = NULL;
        }
        else
        {
            temp->next = table[n];
        }
        table[n] = temp;
        valor_size++;
    }
    free (wordcopy);
    fclose (file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return valor_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *list = table[i];
        while (list != NULL)
        {
            node *tmp = list->next;
            free(list);
            list = tmp;
        }
        if ((list == NULL) && (i == N - 1))
        {
            return true;
        }
    }

    return false;
}
