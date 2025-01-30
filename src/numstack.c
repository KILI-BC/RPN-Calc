#include "numstack.h"
#include <stdlib.h>

numstack_result numstack_init(numstack *n)
{
	n->first = NULL;
	return NUMSTACK_SUCCESS;
}

numstack_result numstack_push(numstack *n, double d)
{
	numstack_elem *new = malloc(sizeof(numstack_elem));
	if(new == NULL)
		return NUMSTACK_FALIURE;
	new->num = d;
	new->next = n->first;
	n->first = new;
	return NUMSTACK_SUCCESS;
}

double numstack_pop(numstack *n)
{
	double d;
	numstack_elem *old = n->first;
	n->first = n->first->next;
	d = old->num;
	free(old);
	return d;
}