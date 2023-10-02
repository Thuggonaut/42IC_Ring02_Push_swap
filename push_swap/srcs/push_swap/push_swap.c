#include "../../inc/push_swap.h"

int	main(int argc, char **argv) //Define a program that takes in a random input if numbers and sorts them in ascending order
{
	t_stack_node	*a; //To store a pointer to stack `a`
	t_stack_node	*b; //To store a pointer to stack `b`

	a = NULL; //Set both pointers to NULL to avoid undefined behaviour
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0])) //Check for incorrect argument counts or if the 2 argument is `0`
		return (1);
	else if (argc == 2) //Check if the argument count is 2 and the 2nd is not empty, this implies a string
		argv = split(argv[1], ' '); //Call ``split()` to extract each substring
	init_stack_a(&a, argv + 1); //Initiate stack `a`, which also handles errors
	if (!stack_sorted(a)) //Check if the stack is not sorted
	{
		if (stack_len(a) == 2) //If not, and there are two numbers, swap the first two nodes
			sa(&a, false);
		else if (stack_len(a) == 3) //If not, and there are three numbers, call the sort three algorithm
			sort_three(&a);
		else
			sort_stacks(&a, &b); //If not, and there are more than three numbers, call the sort stacks algorithm
	}
	free_stack(&a); //Clean up the stack
	return (0);
}
