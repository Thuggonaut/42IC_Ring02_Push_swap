#include "../../inc/push_swap.h"

int	error_syntax(char *str_n)
{
	if (!(*str_n == '+'
			|| *str_n == '-'
			|| (*str_n >= '0' && *str_n <= '9')))
		return (1);
	if ((*str_n == '+'
			|| *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9'))
		return (1);
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	}
	return (0);
}

int	error_duplicate(t_stack_node *a, int n) //Define a function that checks for duplicate input numbers in stack `a`
{
	if (NULL == a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

/*
void	free_stack(t_stack_node **stack) //Define a funtion to free a stack if there are errors
{
	t_stack_node	*tmp; //To store the next node in the stack before the current node is freed, because once a node is freed, you can't access its next pointer

	if (!stack) //Check for an empty stack
		return ;
	while (*stack) //As long as a node exist in the stack
	{
		tmp = (*stack)->next; //Assign to `tmp` the pointer to the next node
		(*stack)->nbr = 0; //Assigning the node to `0` before freeing is not strictly necessary but it can help catch potential bugs such as memory-leaks and improve debugging
		free(*stack); //Free the current node, deallocating the memory occupied by that node
		*stack = tmp; //Assign `tmp` as the current first node
	}
}
*/

void	free_stack(t_stack_node **stack) //Define a funtion to free a stack if there are errors
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (NULL == stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack_node **a) //Define a function that, upon encountering a unique error, to free the stack and print an error message
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}
