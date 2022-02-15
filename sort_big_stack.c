#include "./push_swap.h"

static	int get_bit_max(int value)
{
	int count;

	count = 0;
	while ((value >> count) != 0)
		count++;
	return (count);
}

void    radix_sort(t_data *stacks)
{
	int bit_max;
	int get_size;
	int bit;

	bit = 0;
	bit_max = get_bit_max(get_size_of_stack(stacks->stack_a) - 1);
	while (bit < bit_max)
	{
		get_size = get_size_of_stack(stacks->stack_a);
		while (get_size--)
		{
			if (((stacks->stack_a->index >> bit) & 1 ) == 1)
				rotate(&stacks->stack_a, 0);
			else
				push_b(stacks);
		}
		while (stacks->stack_b != NULL)
			push_a(stacks);
		bit++;
	}
}
