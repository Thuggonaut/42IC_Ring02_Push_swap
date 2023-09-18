#include "../../inc/push_swap.h"

/*Free array created from ft_split()
void	free_array(char **argv)
{
	int	i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}
*/

//Free stack
void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}


void	free_errors(t_stack_node **a, char **argv)
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}

//Check for duplicate numbers
int	error_duplicate(t_stack_node *a, int n)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}