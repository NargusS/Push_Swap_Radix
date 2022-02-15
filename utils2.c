#include "./push_swap.h"

int	get_size_of_stack(t_stack *my_stack)
{
	int	count;

	count = 0;
	while (my_stack != NULL)
	{
		count++;
		my_stack = my_stack->next;
	}
	return (count);
}