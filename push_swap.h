#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
#include <stdio.h>

typedef struct s_stack
{
	int				value;
    int             index;
	struct s_stack	*next;
}				t_stack;
typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}				t_data;

//get_arg_init.c//
int		add_to_stack(t_data *stacks, int num);
int	atoi_and_add(t_data *stacks, char *arg);
void	init_stacks(t_data *stacks, int argc, char **argv);
//utils.c//
int stack_is_sort(t_stack *my_stack);
int	check_is_value_exist(t_stack *my_stack, int value);
int ft_strlen(char *str);
t_stack *get_last_of_my_stack(t_stack *my_stack);
void	free_my_stack(t_stack *my_stack);
//utils2.c//
int get_size_of_stack(t_stack *my_stack);
//command.c//
void    swap(t_stack **stack, int is_stack);
void    reverse_rotate(t_stack **stack, int is_stack);
void    rotate(t_stack **stack, int is_stack);
void	push_a(t_data *stacks);
void	push_b(t_data *stacks);
//sort algo//
void	sort_three_number(t_data *stacks);
void	sort_small_stacks(t_data *stacks);
void    radix_sort(t_data *stacks);
void    load_algo(t_data *stacks);
#endif