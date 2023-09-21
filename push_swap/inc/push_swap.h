#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

typedef struct s_stack_node //A container of data enclosed in {} braces. `s_` for struct
{
	int					nbr; //The number to sort (previously `value`)
	int					index; //The number's position in the stack (previously `current_position`)
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next; //A pointer to the next node
	struct s_stack_node	*prev; //A pointer to the previous node
}	t_stack_node; //Now that we have our struct blueprint, we can use a "shortened name", "t_stack_node". `t_` for type

//***Handle errors
int				error_syntax(char *str_n);
int				error_duplicate(t_stack_node *a, int n);
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **a);

//***Stack initiation
void			init_stack_a(t_stack_node **a, char **argv);
void			append_node(t_stack_node **stack, int n);

//***Nodes initiation
void			init_nodes(t_stack_node *a, t_stack_node *b);
void			current_index(t_stack_node *stack);
void			cost_analysis(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *b);

//***Stack utils
int				stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			prep_for_push(t_stack_node **s, t_stack_node *n, char c);
void			move_cheapest(t_stack_node **a, t_stack_node **b);

//***Commands
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);

//***Algorithm
void			sort_three(t_stack_node **a);
void			sort_b(t_stack_node **a, t_stack_node **b);
void			sort_a(t_stack_node **a, t_stack_node **b);
void			sort_stacks(t_stack_node **a, t_stack_node **b);

#endif