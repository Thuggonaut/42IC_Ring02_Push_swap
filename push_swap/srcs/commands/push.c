#include "../../inc/push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src) //e.g. `src` will be `a` node and `dst` will be `b` node
{
	t_stack_node	*push_node;

	if (!(*src))
		return ;
	push_node = *src; //The top `a` node to push
	*src = (*src)->next; //Move the pointer to the next `a` node (the node following `push_node`)
	if (*src) //Check if the current `a` node exists
		(*src)->prev = NULL; //Set the current `a` node as the head of the stack
	push_node->prev = NULL; //Detach the node to push from `a`
	if (!(*dst)) //Check if `b` is empty
	{
		*dst = push_node; //Assign to `b` node the node to push from `a`
		push_node->next = NULL; //The pushed node is completely detached from `a` and now in `b` as the "last node"
	}
	else //If `b` is not empty
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}