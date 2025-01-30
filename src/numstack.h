#ifndef NUMSTACK_H_INCLUDED
#define NUMSTACK_H_INCLUDED

#define NUMSTACK_SUCCESS 0
#define NUMSTACK_MEMORY_ERROR 1
#define NUMSTACK_STACK_EMPTY 2

typedef struct _numstack_elem{
	struct _numstack_elem * next;
	double num;
} numstack_elem;

typedef struct _numstack{
	numstack_elem *first;
} numstack;

typedef int numstack_result;

numstack_result numstack_init(numstack *n);
numstack_result numstack_push(numstack *n, double *d);
numstack_result numstack_pop(numstack *n, double *d);

#endif