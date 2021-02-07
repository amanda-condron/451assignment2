//This is my code Amanda Condron
/* list.c */

//static char *cr = "copyright (c) David Binkley 2021";

#include "list.h"
#include "misc.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct sElement
{
    struct sElement *next;
    void *element;
} *tElement;
#define ELEMENT_SIZE (sizeof(struct sElement))


struct sList                 /* has dummy first element */
{
    tElement elements; 
};
#define LIST_SIZE (sizeof(struct sList))


/* purpose: search the list for an element
 * input:   a list, an element, and a function that compares elements
 * output:  the element if found, NULL otherwise
 */
void *list_find(tList l, void *e, int (*compare)())
{
    tElement tmp;

    if( l == NULL )
        return NULL;

    for( tmp = l->elements->next; tmp != NULL; tmp = tmp->next)
    {
        if((*compare) (tmp->element, e))
            return tmp->element;
    }
    return NULL;
}


/* purpose: apply a one argument function to each element of a list
 * input:   a list and a function
 * output:  nothing
 */
/* An addition parameter is passed to f.  This parameter is TRUE iff the 
 * current element being passed to f is the last element in the list
 * (The same is done for the other list_foreach functions)
 */

// basically want to have every element go through the function up until the last element
void list_foreach(tList l, void (*f)(void *, int))
{ 
    tElement tmp;

    if( l == NULL )
        return;

    for( tmp = l->elements->next; tmp != NULL; tmp = tmp->next)
        f(tmp->element, tmp->next == NULL); 

} 


/* purpose: apply one argument a function to each element of a list
 *          along with an additional parameter
 * input:   a list, a function, and an additional parameter
 * output:  nothing
 */
void list_foreach1(tList l, void (*f)(), void *parm)
{
    tElement tmp;

    if( l == NULL )
        return;

    for( tmp = l->elements->next; tmp != NULL; tmp = tmp->next)
        f(tmp->element, parm, tmp->next == NULL);
     
}


/* purpose: apply two argument a function to each element of a list
 *          along with two additional parameters
 * input:   a list, a function, and two additional parameters
 * output:  nothing
 */
void list_foreach2(tList l, void (*f)(), void *parm1, void *parm2)
{
    tElement tmp;

    if( l == NULL )
        return;

    for( tmp = l->elements->next; tmp != NULL; tmp = tmp->next)
        f(tmp->element, parm1, parm2, tmp->next == NULL);
}


/* purpose: free all memory allocated to the list
 * input:   a list
 * output:  nothing
 */
void list_free(tList l)
{
    tElement tmp, tmp2;
    
    if( l == NULL )
        return;

    for(tmp = l->elements; tmp != NULL; tmp = tmp2)
    {
        tmp2 = tmp->next;
        free(tmp);
    }
    //free the overall list as a whole
    free(l);
}

/* purpose: create new lists
 * input:   nothing
 * output:  an empty list
 */
tList list_initialize()
{
    tList new_list;

    new_list = (tList) check_malloc(LIST_SIZE);                     //checks the size of the list
    new_list->elements = (tElement) check_malloc(ELEMENT_SIZE);     //checks the size of the elements

    new_list->elements->next = NULL;                                //setting last index to NULL
    new_list->elements->element = NULL;                             //setting last element to NULL
    return new_list;
}


/* purpose: add an element to the end of a list
 * input:   a list and an element
 * output:  the list with element at the end
 */
tList list_insert_end(tList l, void *e)
{
    tElement new_element;
    tElement tmp;

    if( l == NULL )
        l = list_initialize();

    new_element = (tElement)check_malloc(ELEMENT_SIZE);
    new_element->element = e;
    new_element->next = NULL;

    for( tmp = l ->elements; tmp->next != NULL; tmp = tmp->next)
        ;
    tmp->next = new_element;
    return 1;

}


/* purpose: add an element to the beginning of a list
 * input:   a list and an element
 * output:  the list [element|list]
 */
tList list_insert_beginning(tList l, void *e)   //e is tElement
{
    tElement new_element;

    if( l == NULL )
        l = list_initialize();

    new_element = (tElement)check_malloc(ELEMENT_SIZE);
    new_element->element = e;
    new_element->next = l->elements->next;
    l->elements->next = new_element;
    return 1;

}

/* purpose: check if a list is empty
 * input:   a list
 * output:  true if the list is empty, false otherwise
 */
bool list_isempty(tList l)
{
    return l == NULL ? true : l->elements->next == NULL;
}


/* purpose: compute the length of a list
 * input:   a list
 * output:  the length of the list :)
 */
int list_length(tList l)
{
   int len = 0;
   tElement tmp;

   if(l == NULL)
        return 0;

   for(tmp = l->elements->next; tmp != NULL; tmp = tmp->next)
        len++;

    return len;

}


/* purpose: check if an element is part of a list
 * input:   a list, the element, and function that compares entries
 * output:  TRUE if compare returns true of one of the elements in the list,
 *          FALSE otherwise
 */
bool list_member(tList l, void * e, int (*compare)())
{   
    return list_find( l, e, compare) != NULL;
}


/* purpose: remove an element from a list
 * input:   a list, an element, and a function that compares entries
 * output:  the list without the first occurrence of the element
 *          (the list is unchanged if the elements in not in the list)
 */
void* list_remove(tList list, void *element, int (*compare)(void*, void*))
{
    tElement laggard, tmp;

    if(list == NULL)
        return NULL;

    for(laggard = list->elements, tmp = list->elements->next; tmp != NULL; laggard = tmp, tmp = tmp->next)
    {
        if((*compare) (tmp->element, element))
        break;
    }

    if(tmp != NULL)
    {
        laggard->next = tmp->next;
        free(tmp);
    }
    return list;
}

void list_print(tList the_list)
{
    int length = list_length(the_list);
    printf("The length of list: %d\n", length);
    for(tElement head = the_list->elements->next; head != NULL; head = head -> next)
    {
        int *value = (int*)head -> element;
        printf("value: %d\n", *value);
    }
}