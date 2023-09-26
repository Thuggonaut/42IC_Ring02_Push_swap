/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:40:14 by tquemato          #+#    #+#             */
/*   Updated: 2023/09/26 15:56:09 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	swap(t_stack_node **stack)
{
	t_stack_node	*old_top;
	t_stack_node	*new_top;

	if (!*stack || !(*stack)->next)
		return ;
	old_top = *stack;
	new_top = (*stack)->next;
	old_top->next = new_top->next;
	old_top->prev = new_top;
	new_top->next = old_top;
	new_top->prev = NULL;
	*stack = new_top;
}

void	sa(t_stack_node	**a, bool print)
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool print)
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}
