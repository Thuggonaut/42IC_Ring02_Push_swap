#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

/*
 *  atol, i need it to check eventual overflows
 *  converting every string into a long value
*/
static long	ft_atol(const char *str) //A function that takes a string and converts it to a long integer
{
	long	num;
	int		isneg;
	int		i;

	num = 0;
	isneg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * isneg);
}

/*
 * Create the stack with the command line values
 * Checks are embedded in the creation itslef
 * 		~Duplicate values
 * 		~Over|Underflow
 * 		~Syntax errors
 *
 * 	🏁 Flag is useful cause if true, i have the argv in the HEAP to free
 *
*/
void	stack_init(t_stack_node **a, char **argv, bool flag_argc_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i])) //Check for syntax errors
			error_free(a, argv, flag_argc_2);
		nbr = ft_atol(argv[i]); //Conver the string into a long 
		if (nbr > INT_MAX || nbr < INT_MIN) //Check for overflow
			error_free(a, argv, flag_argc_2);
		if (error_repetition(*a, (int)nbr)) //Check for duplicate numbers, i.e. if value at current node == nbr
			error_free(a, argv, flag_argc_2); 
		append_node(a, (int)nbr); //If no errors, append the node to the linked list by, taking a pointer to stack `a`, create a new node and assign `nbr` to that new node
		++i; //Move to the next argv
	}
	if (flag_argc_2)
		free_matrix(argv);
}