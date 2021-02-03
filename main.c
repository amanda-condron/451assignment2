/* main.c -- a hash table of integers */

#include <stdio.h>
#include <stdlib.h>

#include "misc.h"
#include "ht.h"

#define SIZE 5 


/* The next three function are auxiliary functions for an integer hash table */
int int_compare(a, b)
int *a, *b;
{
    return *a == *b;
}

int int_hash(d)
int *d;
{
    return (int)*d;
}

void int_print(d)
int *d;
{
    printf("%d ", *d);
}


int main()
{
    int command;
    int *item;
    tHashTable ht;

    ht = ht_initialize (SIZE, int_compare, int_hash);
    item = (int *) check_malloc(sizeof (int));

    while ((command = getchar()) != EOF)
    {
        if (command == 'i' || command == 'd' || command == 'l') 
            if (1 != scanf("%d", item))
                abort1("scanf kinda wanted an int\n");

        switch (command)
        {
            case 'i':    ht_insert(ht, item);
                         item = (int *) check_malloc(sizeof (int));
                         break;

            case 'd':    ht_delete(ht, item);
                         break;

            case 'l':    if (ht_lookup(ht, item) != NULL)
                              printf("Found\n");
                         else
                              printf("Not Found\n");
                         break;

            case 'p':    ht_print(ht, int_print);
                         break;

            case 'q':    ht_free(ht);
                         exit(0);
        }
    }

	return 0;
}
