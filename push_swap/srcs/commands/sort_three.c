#include "../../inc/push_swap.h"

static t_stack_node	*find_highest(t_stack_node *stack)
{
	int				highest;
	t_stack_node	*highest_node;

	if (!stack)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->nbr > highest)
		{
			highest = stack->nbr;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*highest_node;

	highest_node = find_highest(*a);
	if (*a == highest_node) //Check if the current node is the highest
		ra(a, false); //If so, rotate the top node to the bottom of the stack
	else if ((*a)->next == highest_node) //Check if the second node is the highest
		rra(a, false); //If so, reverse rotate the bottom node, to the top of the stack
	if ((*a)->nbr > (*a)->next->nbr) //Check if the bottom node is the highest, but the top node is higher than the second node
		sa(a, false); //Simply swap the top and second nodes
}
