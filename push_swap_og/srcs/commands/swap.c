#include "../../inc/push_swap.h"

/*static void	swap(t_stack_node **stack)
{
	int	len;

	len = stack_len(*stack);
	if (NULL == *stack || NULL == stack || 1 == len)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}*/

static void swap(t_stack_node **stack) //Define a function that swaps the positions of the top node and second node of a stack
{
    t_stack_node *old_top; //To store a pointer to the top node
    t_stack_node *new_top; //To store a pointer to the second node
	
	if (!*stack || !(*stack)->next) //Check if the stop node, or second node of a stack exists
        return ;
    old_top = *stack; //Assign to `old_top`, the pointer of the current top node
    new_top = (*stack)->next; //Assign to `new_top` the current second node
    old_top->next = new_top->next; //Update the `next` attribute of the new second node, as the current third node
    old_top->prev = new_top; //Update as the new top node, the old second node
    new_top->next = old_top; //Update the `next` attribute of the new node, as the old top node, completing the swap
    new_top->prev = NULL; //Update the new top node's previous pointer to NULL, effectively setting it as the top node
    *stack = new_top; //Update the pointer of the top node, to hold the new top node
}

void	sa(t_stack_node	**a, bool print) //Swap the first two nodes of stack `a` and print the instruction
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool print) //Swap the first two nodes of stack `b` and print the instruction
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool print) //Stimutaneously swap the first two nodes of the stack and print the instruction
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}