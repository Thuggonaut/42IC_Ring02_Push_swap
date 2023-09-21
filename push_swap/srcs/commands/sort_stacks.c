#include "../../inc/push_swap.h"

void	sort_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*max;
	
	if (ft_lstsize(a) > 3 && !stack_sorted(*a))
			pb(a, b, 0);
	if (ft_lstsize(*a) > 3 && !stack_sorted(*a))
			pb(a, b, 0);
	if (ft_lstsize(*a) > 3 && !stack_sorted(*a))
	{
		while (ft_lstsize(*a) > 3) //As long as there are more than 3 nodes in stack `a`
		{
			init_nodes(*a, *b); //Refresh the current index and data in all the nodes in the current configuration
			move_cheapest(a, b); //Push the cheapest `a` node to stack `b`
		}
	}
	if (!stack_sorted(*a))
		sort_three(a);
}

static void	set_target_b(t_stack_node *a, t_stack_node *b)//Find `b` node's target in stack `a`. Does it need to be static????????????? If not, then add prototype in push_swap.h
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	while (b) //As long as we have nodes in stack `a` linked list
	{
		best_match_index = LONG_MAX; //Placeholder for the closest bigger number so far
		current_a = a;
		while (current_a) //Iteratively search through all the nodes in stack `a`
		{
			if (current_a->nbr > a->nbr
				&& current_a->nbr < best_match_index) //If `a` node is bigger than `b` node && smaller than the closest bigger number so far
			{
				best_match_index = current_a->nbr; //Update the value of the closest bigger number so far
				target_node = current_a; //Assign the current `a` node as the `target_node`
			}
			current_a = current_a->next; //Move to the next `a` node
		}
		if (best_match_index == LONG_MAX) //If the LONG_MAX hasn't changed, it means we haven't found anything bigger
			b->target_node = find_min(a); //Then we need to find the smallest nbr and set this as the target node
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	sort_a(t_stack_node **a, t_stack_node **b)
{
	while (*b) //Loop until the end of stack `b` is reached and is empty
	{
		current_index(a); //Refresh the indices in stack `a`
		set_target_b(a, b); //Refresh `b` nodes' target `a` nodes
		while ((*a) != (*b)->target_node)
		{
			if ((*b)->target_node->above_median)
				ra(a, false);
			else if (!(*b)->target_node->above_median)
				rra(a, false);
		}
	}
	return (a); //Do we need this line?????????
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	sort_b(a, b); //Push all `a` nodes to stack `b`, and sorted in descending order, until there are 3 nodes left in stack `a`
	sort_a(a, b); //Push back to stack `a` all `b` nodes
	while ((*a)->nbr != find_min(*a)->nbr) //While the top `a` node is not the smallest number
	{
		if (find_min(*a)->above_median) //If smallest `a` node is above the median
			ra(a, false); //Rotate the top `a` node
		else //If the smallest number is below the median
			rra(a, false); //Reverse rotate the bottom `a` node
	}
}
