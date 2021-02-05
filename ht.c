#include "ht.h"

#include "misc.h"
#include <stdio.h>
#include <stdlib.h>

tHashTable ht_initialize(int, int (*compare_function)(),int(*hash_function)())
{
    
}

void ht_free(tHashTable)
{

}

tHashTable ht_insert(tHashTable, void*)
{

}

tHashTable ht_delete(tHashTable, void*)
{

}

void *ht_lookup(tHashTable, void*)
{

}

void ht_print(tHashTable, void (*print_function)())
{

}

void ht_foreach(tHashTable, void (*function)(void *))
{

}

void ht_foreach1(tHashTable, void (*function)(void *, void *), void*)
{

}

void ht_foreach2(tHashTable, void (*function)(void *, void *, void *), void*, void*)
{

}
