#include "./push_swap.h"

void    load_algo(t_data *stacks)
{
	int size;

	size = get_size_of_stack(stacks->stack_a);
	if (size == 2)
		rotate(&stacks->stack_a, 0);
	else if (size == 3)
		sort_three_number(stacks);
	else if (size <= 5)
		sort_small_stacks(stacks);
	else
		radix_sort(stacks);
}

int	main(int argc, char **argv)
{
	t_data stacks;


	init_stacks(&stacks, argc, argv);
	if (stack_is_sort(stacks.stack_a) == -1)
		load_algo(&stacks);
	free_my_stack(stacks.stack_a);
	free_my_stack(stacks.stack_b);
}
