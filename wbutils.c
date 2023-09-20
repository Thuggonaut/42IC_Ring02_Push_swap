#include "../../inc/push_swap.h"







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

void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis(a, b);
	set_cheapest(a);
}

static void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node) //Static function to maintain the data in "cheapest_node"?
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node) //As long as the current `b` node is not `a` cheapest node's target node
		rr(a, b, false); //Rotate both `a` and `b` nodes
	current_index(*a); //Refresh positions
	current_index(*b);
}

static void	reverse_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node) //As long as the current `b` node is not `a` cheapest node's target node
		rrr(a, b, false);  //Reverse rotate both `a` and `b` nodes
	current_index(*a); //Refresh current positions
	current_index(*b);
}


//Are the `a` and target `b` nodes at the top of the stack? 
void	prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}	
	}
}

static void	move_cheapest(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a); //After each configuration, return a pointer to the cheapest node
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median) //If both nodes are `above_median`
		rotate_both(a, b, cheapest_node); //Rotate both, effectively halving the cost of two moves
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median)) //If both nodes are below median
		reverse_rotate_both(a, b, cheapest_node); //Reverse rotate both, effectively halving the cost of two moves
	prep_for_push(a, cheapest_node, 'a'); //Ensure cheapest `a` node is on top of the stack
	prep_for_push(b, cheapest_node->target_node, 'b'); //Ensure cheapest `a` node's target `b` node is on top of the stack
	pb(b, a, false); //Finally, push the cheapest `a` node on top of the `b` stack, which should sit on top of its target node
}

t_stack_node	*find_min(t_stack_node *stack)
{
	long			min;
	t_stack_node	*min_node;

	if (stack == NULL)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nbr > min)
		{
			min = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

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