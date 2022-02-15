#include "./push_swap.h"

int	stack_is_sort(t_stack *my_stack)
{
	int	current;

	while (my_stack->next != NULL)
	{
		current = my_stack->value;
		if (current > my_stack->next->value)
			return (-1);
		my_stack = my_stack->next;
	}
	return (1);
}

int	check_is_value_exist(t_stack *my_stack, int num)
{
	while (my_stack != NULL)
	{
		if (my_stack->value == num)
			return (-1);
		my_stack = my_stack->next;
	}
	return (1);
}

int ft_strlen(char *str)
{
	int count;

	count = 0;
	while (str && str[count])
		count++;
	return (count);
}

t_stack *get_last_of_my_stack(t_stack *my_stack)
{
	while (my_stack->next != NULL)
		my_stack = my_stack->next;
	return (my_stack);
}

void	free_my_stack(t_stack *my_stack)
{
	t_stack *current;

	current = my_stack;
	while (current != NULL)
	{
		my_stack = my_stack->next;
		free(current);
		current = my_stack;
	}
}