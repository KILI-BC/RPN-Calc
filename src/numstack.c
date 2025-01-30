#include "numstack.h"
#include <stdlib.h>

numstack_result numstack_init(numstack *n)
{
	n->first = NULL;
	return NUMSTACK_SUCCESS;
}

numstack_result numstack_push(numstack *n, double *d)
{
	numstack_elem *new = malloc(sizeof(numstack_elem));
	if(new == NULL)
		return NUMSTACK_MEMORY_ERROR;
	new->num = *d;
	new->next = n->first;
	n->first = new;
	return NUMSTACK_SUCCESS;
}

numstack_result numstack_pop(numstack *n, double *d)
{
	numstack_elem *old = n->first;
	if(old = NULL)
		return NUMSTACK_STACK_EMPTY;

	n->first = n->first->next;
	*d = old->num;
	free(old);

	return NUMSTACK_SUCCESS;
}