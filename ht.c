#include "ht.h"
#include "list.h"


#include "misc.h"
#include <stdio.h>
#include <stdlib.h>


struct sHashTable
{
    tList* lists;
    bool (*compare_function)();
    int(*hash_function)()

}sHashTable;

#define TABLE_SIZE (sizeof(struct sHashTable))

#define LIST_SIZE (sizeof(struct tList))


/* purpose: initialize the hashtable
 * input: an int, compare that returns an int, hash function to place int in hashtable 
 * output:  a hashtable
 */
tHashTable ht_initialize(int i, bool (*compare_function)(), int(*hash_function)())
{
    tHashTable table;

    table = (tHashTable)check_malloc(TABLE_SIZE);
    //table->lists = (tList)check_malloc(LIST_SIZE);

    table->hash_function = hash_function;
    table->compare_function = compare_function;

    for( int j = 0; j <= i; j++)
    {
        list_initialize(table->lists[j]);
    }
}

/* purpose: 
 * input:   
 * output:  nothing
 */
void ht_free(tHashTable table)
{   
    if( table == NULL )
        return;

    for( int i = 0; i <= TABLE_SIZE; i++)
    {
        list_free(table->lists[i]);
    }
    //free the overall list as a whole
    free(table);
}

/* purpose: 
 * input:   
 * output:  a hashtable with a new value in it
 */
tHashTable ht_insert(tHashTable table, void* value)
{
    tHashTable table = table;

    // set i to the hash value that is retrieved
    int i = table->hash_function(value);

    //loop through the hashtable to find the matching index/bucket
    for( int j = 0; j <= i; j++)
    {
        //if the bucket matches insert the value in
        if(j == i)
            list_insert_beginning(table->lists[j], value);

    }
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
