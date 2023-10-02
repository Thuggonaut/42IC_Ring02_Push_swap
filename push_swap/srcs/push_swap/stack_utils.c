#include "../../inc/push_swap.h"

int	stack_len(t_stack_node *stack) //Define a function that calculates and returns the length of a stack
{
	int	count; //To store the node count

	if (!stack) 
		return (0);
	count = 0;
	while (stack) //Loop until the end of the stack is reached
	{
		stack = stack->next; //Move to the next node
		count++;
	}
	return (count);
}

t_stack_node	*find_last(t_stack_node *stack) //Define a function that returns the pointer to the last node
{
	if (!stack)
		return (NULL);
	while (stack->next) //Loop until the end of the stack is reached
		stack = stack->next;
	return (stack);
}

bool	stack_sorted(t_stack_node *stack) //Define a function that checks if the stack is sorted in ascending order
{
	if (!stack)
		return (1);
	while (stack->next) //Loop until the end of the stack is reached
	{
		if (stack->nbr > stack->next->nbr) //Check if the current value is larger than the next node's value, indicating it is out of sort
			return (false);
		stack = stack->next; //If not, move to the next node for processing
	}
	return (true);
}

t_stack_node	*find_min(t_stack_node *stack) //Define a function that searches a stack and returns the node with the smallest number
{
	long			min; //To store the smallest value so far
	t_stack_node	*min_node; //To store a pointer that points to the smallest number

	if (!stack)
		return (NULL);
	min = LONG_MAX; //Assign to the smallest value so far, the max long integer
	while (stack) //Loop until the end of the stack is reached
	{
		if (stack->nbr < min) //Check if the current node value is smaller than the smallest so far
		{
			min = stack->nbr; //If so, update the smallest number so far
			min_node = stack; //Set the pointer to point to the node with the smallest number so far
		}
		stack = stack->next; //Move to the next node for processing
	}
	return (min_node); 
}

t_stack_node	*find_max(t_stack_node *stack) //Define a function that searches a stack and returns the node with the biggest number
{
	long			max; //To store the biggest value so far
	t_stack_node	*max_node; //To store a pointer that points to the biggest number

	if (!stack)
		return (NULL);
	max = LONG_MIN; //Assign to the biggest value so far, the max long integer
	while (stack) //Loop until the end of the stack is reached
	{
		if (stack->nbr > max) //Check if the current node value is smaller than the biggest so far
		{
			max = stack->nbr; //If so, update the biggest number so far
			max_node = stack; //Set the pointer to point to the node with the biggest number so far
		}
		stack = stack->next; //Move to the next node for processing
	}
	return (max_node);
}
