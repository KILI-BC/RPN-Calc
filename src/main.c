#include "numstack.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define INVALID_ARGUMENT -1

void handle_error(numstack_result err);
numstack_result calculate(numstack *stack_ptr, char *operation);

int main(int argc, char *argv[])
{
	int i;
	double d;
	numstack_result err;
	numstack *stack_ptr;
	numstack_init(stack_ptr);

	for (i = 1; i < argc; i++)
	{
		if(isdigit(argv[i][i])){
			d = atof(argv[i]);
			err = numstack_push(stack_ptr, &d);
		} else {
			err = calculate(stack_ptr, argv[i]);
		}

		handle_error(err);
		if(err != NUMSTACK_SUCCESS)
			return EXIT_FAILURE;
	}
	err = numstack_pop(stack_ptr, &d);
	handle_error(err);
	if(err != NUMSTACK_SUCCESS)
			return EXIT_FAILURE;
	printf("The result of the calculation is: %f", d);

	err = numstack_pop(stack_ptr, &d);
	if(err != NUMSTACK_STACK_EMPTY){
		printf("\n...however there seems to be something left on the stack");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

numstack_result calculate(numstack *stack_ptr, char *operation)
{
	double arg1, arg2, res;
	numstack_result err;

	if(operation[1] != '\0')
		return INVALID_ARGUMENT;

	err = numstack_pop(stack_ptr, &arg2);
	if(err != NUMSTACK_SUCCESS)
		return err;
	err = numstack_pop(stack_ptr, &arg1);
	if(err != NUMSTACK_SUCCESS)
		return err;

	switch (operation[0]) {
	case '+':
		res = arg1 + arg2;
		break;
	case '-':
		res = arg1 - arg2;
		break;
	case '*':
		res = arg1 * arg2;
		break;
	case '/':
		res = arg1 / arg2;
		break;
	default:
		return INVALID_ARGUMENT;
	}
	err = numstack_push(stack_ptr, &res);
	return err;
}

void handle_error(numstack_result err)
{
	switch (err) {
	case INVALID_ARGUMENT:
		printf("You seem to have used an invalid argument");
		break;
	case NUMSTACK_MEMORY_ERROR:
		printf("A memory error occured!");
		break;
	case NUMSTACK_STACK_EMPTY:
		printf("The stack seems to be empty");
		break;
	default:
		break;
	}
}