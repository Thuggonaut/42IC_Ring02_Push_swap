#include "../../inc/push_swap.h"

//Search for the last node to append to the linked list
void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_lstlast(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

//Flag the cheapest node in the current stacks configurations

void	set_cheapest(t_stack_node *a)
{
	long			best_match_value;
	t_stack_node	*best_match_node;

	if (a == NULL)
		return ;
	best_match_value = LONG_MIN;
	while (a)
	{
		if (a->push_cost < best_match_value)
		{
			best_match_value = a->push_cost;
			best_match_node = a;
		}
		a = a->next;
	}
	best_match_node->cheapest = true;
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}


//Set the current position of every node in the current state-configuration

void	current_index(t_stack_node *stack)
{
	int	i; //To store the index of the current node
	int	median; //The median of the stack

	i = 0; //The first index is `0`
	if (stack == NULL)
		return ;
	median = ft_lstsize(stack) / 2; //Calculate the median by dividing the length of a stack by 2
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

//Find the biggest nbr 
t_stack_node	*find_max(t_stack_node *stack)
{
	long			max;
	t_stack_node	*max_node;

	if (stack == NULL)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}


//Every `a` node needs a target `b` node
//The best match for `a` node is the "closest smaller" nbr in `b` node
//If there are no smaller nbr in `b`, then the target will be the max nbr
//`a` node will be pushed above the target `b` node
static void	set_target_node(t_stack_node *a, t_stack_node *b)
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

//Set the prices to push the node from a -> b
//The price checks for the relative positions in the stack for every node, setting the respective price

void	cost_analysis(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
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


//For every configuration, we initalise all the nodes in preparation for moves and push
void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_node(a, b);
	cost_analysis(a, b);
	set_cheapest(a);
}
