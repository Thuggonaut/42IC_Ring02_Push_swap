#include "../../inc/push_swap.h"

//Check if a stack is already sorted
bool	stack_sorted(t_stack_node *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}


static t_stack_node	*find_highest(t_stack_node *stack)
{
	int				highest;
	t_stack_node	*highest_node;

	if (stack == NULL)
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

/*Handle input 5
void	handle_five(t_stack_node **a, t_stack_node **b)
{
	while (stack_len(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(b, a, false);
	}
}*/

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