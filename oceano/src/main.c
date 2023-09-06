#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a; //Pointer to the stack `a`
	t_stack_node	*b;

	a = NULL; //Good practice to avoid segmentation faults due to inability to deference NULL pointers
	b = NULL;
	if (1 == argc || (2 == argc && !argv[1][0])) //Check for input errors, such as incorrect argc or the first string input is empty
		return (1); //Return `1` to indicate error and exit
	else if (2 == argc) //If argc is correct, and the string input is not empty, this implied the input is enclosed in " " marks
		argv = ft_split(argv[1], ' '); //Split the string into substrings with the space dilimiter. See #1
	stack_init(&a, argv + 1, 2 == argc); //"Stack init-ialization function that creates the stack `a`. Refer to `stack_init()` source file
	if (!stack_sorted(a)) //Within this if {} is the algorithm - the instructions/commands. First it checks if stack `a` is not in ascending ordder
	{
		if (stack_len(a) == 2) 
			sa(&a, false);
		else if (stack_len(a) == 3)
			tiny_sort(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a); //Clean up the stack
}

/*
#1	`push_swap()` needs to handle both of these cases:
	
	`./push_swap 42 31 0` and

	`./push_swap "42 31 0"`

	- Our `ft_split()` handles this. Refer to the source file.
*/