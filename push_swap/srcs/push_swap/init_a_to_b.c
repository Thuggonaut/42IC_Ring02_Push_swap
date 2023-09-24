#include "../../inc/push_swap.h"

void	current_index(t_stack_node *stack)
{
	int	i; //To store the index of the current node
	int	median; //The median of the stack

	i = 0; //The first index is `0`
	if (!stack)
		return ;
	median = stack_len(stack) / 2; //Calculate the median by dividing the length of a stack by 2
	while (stack) //Loop through all the nodes until the end of the stack is reached
	{
		stack->index = i; //Assign the current index value to the current node
		if (i <= median) //Check whether the current node is above or below the median
			stack->above_median = true; //If above, set the above_median data of the node to true
		else
			stack->above_median = false; //If below, set the above_median data of the node to false
		stack = stack->next; //Move to the next node for indexing
		++i; //Increment the index value to set the next node with
	}
}

static void	set_target_a(t_stack_node *a, t_stack_node *b)//Find `a` node's target in stack `b`
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_match_index;

	while (a) //As long as we have nodes in stack `a` linked list
	{
		best_match_index = LONG_MIN; //Placeholder for the closest smaller number so far
		current_b = b;
		while (current_b) //Iteratively search through all the nodes in stack `b`
		{
			if (current_b->nbr < a->nbr
				&& current_b->nbr > best_match_index) //If `b` node is smaller than `a` node && bigger than the closest smaller number so far
			{
				best_match_index = current_b->nbr; //Update the value of the closest smaller number so far
				target_node = current_b; //Assign the current `b` node as the `target_node`
			}
			current_b = current_b->next; //Move to the next `b` node
		}
		if (best_match_index == LONG_MIN) //If the LONG_MIN hasn't changed, it means we haven't found anything smaller
			a->target_node = find_max(b); //Then we need to find the biggest nbr and set this as the target node
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a) //Loop through each node until the end of the stack is reached
	{
		a->push_cost = a->index; //Assign the current `a` node's push cost, its' index value
		if (!(a->above_median)) //Check if the above_median data is false, meaning it is below median
			a->push_cost = len_a - (a->index); //If so, update `a` node's push cost to the stack's length - index
		if (a->target_node->above_median) //Check if `a` node's target node `b` has a "true" above median attribute, meaning the target `b` node is above median
			a->push_cost += a->target_node->index; //If so, update `a` node's push cost, the sum of (its current index) + (its target `b` node's index)
		else //If `a` node is indeed above median and its target `b` node is below median
			a->push_cost += len_b - (a->target_node->index); //Update `a` node's push cost, the sum of (its current index) + (`b` stack's length - its target `b` node's index)
		a = a->next; //Move to the next `a` node for its cost analysis
	}
}

void	set_cheapest(t_stack_node *stack)
{
	long			best_match_value;
	t_stack_node	*best_match_node;

	if (!stack)
		return ;
	best_match_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < best_match_value)
		{
			best_match_value = stack->push_cost;
			best_match_node = stack;
		}
		stack = stack->next;
	}
	best_match_node->cheapest = true;
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}