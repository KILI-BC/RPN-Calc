#ifndef NUMSTACK_H_INCLUDED
#define NUMSTACK_H_INCLUDED

#define NUMSTACK_SUCCESS 1
#define NUMSTACK_FALIURE 0

typedef struct _numstack_elem{
	numstack_elem * next;
	double num;
} numstack_elem;

typedef struct _numstack{
	numstack_elem *first;
} numstack;

typedef int numstack_result;

numstack_result numstack_init(numstack *n);
numstack_result numstack_push(numstack *n, double d);
double numstack_pop(numstack *n);

#endif