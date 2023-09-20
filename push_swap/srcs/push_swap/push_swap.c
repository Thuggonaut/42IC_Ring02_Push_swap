#include "../../inc/push_swap.h"

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


//After each init_nodes, we move the cheapest nodes
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


void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*max;
	
	while (*a)
	{
		init_nodes(*a, *b); //Refresh the current positions of the notes in the current state
		move_cheapest(a, b); 
	}
	current_index(*b);
	max = find_max(*b);
	if (max->above_median)
		while (*b != max)
			rb(b, false);
	else
		while (*b != max)
			rra(b, false);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;

	//Handle errors
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_stack_a(&a, argv + 1);
	if (!stack_sorted(a))
	{
		if (ft_lstsize(a) == 2) 
			sa(&a, false);
		else if (ft_lstsize(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a); //Clean up the stack
}
