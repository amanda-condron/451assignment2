#include "ht.h"

#include "misc.h"
#include <stdio.h>
#include <stdlib.h>

struct sHashtable
{
    void * list;

}sHashTable;

#define LIST_SIZE (sizeof(struct sHashtable))


/* purpose: initialize the hashtable
 * input: an int, compare that returns an int, hash function to place int in hashtable 
 * output:  a hashtable
 */
tHashTable ht_initialize(int i, int (*compare_function)(), int(*hash_function)())
{
    sHashtable table;

    table = (sHashtable) check_malloc(LIST_SIZE);
    
    // takes in int it which is the size of the table (that has arrays as indexes)

    // takes in compare function

    // takes in hash function that will has the thingy and return an int saying where to be placed in the table
}

/* purpose: 
 * input:   
 * output:  nothing
 */
void ht_free(tHashTable table)
{

}

/* purpose: 
 * input:   
 * output:  a hashtable with a new value in it
 */
tHashTable ht_insert(tHashTable table, void* value)
{

}

/* purpose: 
 * input:   
 * output:  a hashtable with one less value in it
 */
tHashTable ht_delete(tHashTable table, void* value)
{

}

/* purpose: 
 * input:   
 * output:  nothing
 */
void *ht_lookup(tHashTable table, void* value)
{

}

/* purpose: 
 * input:   
 * output:  nothing
 */
void ht_print(tHashTable table, void (*print_function)())
{

}

/* purpose: 
 * input:   
 * output:  nothing
 */
void ht_foreach(tHashTable table, void (*function)(void *))
{

}

/* purpose: 
 * input:   
 * output:  nothing
 */
void ht_foreach1(tHashTable table, void (*function)(void *, void *), void* parm)
{

}

/* purpose: 
 * input:   
 * output:  nothing
 */
void ht_foreach2(tHashTable table, void (*function)(void *, void *, void *), void* parm1, void* parm2)
{

}
