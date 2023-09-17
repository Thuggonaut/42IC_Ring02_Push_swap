#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/inc/libft.h"

typedef struct s_stack_node //A container of data enclosed in {} braces. `s_` for struct
{
	int					nbr; //The number to sort (previously `value`)
	int					index; //The number's position in the stack (previously `current_position`)
	//int					push_price;
	//bool				above_median;
	bool				cheapest;
	//struct s_stack_node	*target_node;
	struct s_stack_node	*next; //A pointer to the next node
	struct s_stack_node	*prev; //A pointer to the previous node
}	t_stack_node; //Now that we have our struct blueprint, we can use a "shortened name", "t_stack_node". `t_` for type


//***Handle errors
void			free_array(char **argv); //Previously 'free_matrix'
void			free_errors(t_stack_node **a, char **argv, bool flag_argc_2); //Previously `error_free`
void			free_stack(t_stack_node **stack);
int				error_duplicate(t_stack_node *a, int n); //Previously `error_repetition`
//int				error_syntax(char *str_n);


//***Stack initiation
void			init_stack_a(t_stack_node **a, char **argv, bool flag_argc_2); //Previously `stack_init`


//***Stack utils
void			append_node(t_stack_node **stack, int n);
t_stack_node	*find_last(t_stack_node *head);
//t_stack_node	*find_smallest(t_stack_node *stack);
//t_stack_node	*return_cheapest(t_stack_node *stack);
//int				stack_len(t_stack_node *stack);
//void			finish_rotation(t_stack_node **s, t_stack_node *n, char c);


//***Algorithm
bool			stack_sorted(t_stack_node *stack);

#endif