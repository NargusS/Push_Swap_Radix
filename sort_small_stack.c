#include "./push_swap.h"

static int	less_than(t_stack *elem1, t_stack *elem2)
{
	if (elem1->value < elem2->value)
		return (1);
	return (0);
}

static int	tall_than(t_stack *elem1, t_stack *elem2)
{
	if (elem1->value > elem2->value)
		return (1);
	return (0);
}

void	sort_three_number(t_data *stacks)
{
	t_stack	*fst;
	t_stack	*scd;
	t_stack	*trd;

	fst = stacks->stack_a;
	scd = stacks->stack_a->next;
	trd = stacks->stack_a->next->next;
	if (less_than(fst, scd) && tall_than(scd, trd) && less_than(fst, trd))
	{
		reverse_rotate(&stacks->stack_a, 0);
		swap(&stacks->stack_a, 0);
	}
	else if (less_than(fst, scd) && tall_than(scd, trd) && tall_than(fst, trd))
		reverse_rotate(&stacks->stack_a, 0);
	else if (tall_than(fst, scd) && less_than(scd, trd) && tall_than(fst, trd))
		rotate(&stacks->stack_a, 0);
	else if (tall_than(fst, scd) && tall_than(scd, trd))
	{
		swap(&stacks->stack_a, 0);
		reverse_rotate(&stacks->stack_a, 0);
	}
	else
		swap(&stacks->stack_a, 0);
}

void	sort_small_stacks(t_data *stacks)
{
	int	median;

	if (get_size_of_stack(stacks->stack_a) > 3)
	{
		median = get_size_of_stack(stacks->stack_a) / 2;
		while (get_size_of_stack(stacks->stack_a) > 3)
		{
			if (stacks->stack_a->index < median)
				push_b(stacks);
			else
				rotate(&stacks->stack_a, 0);
		}
		if (stack_is_sort(stacks->stack_a) == -1)
			sort_three_number(stacks);
		if (stacks->stack_b->next && stacks->stack_b->value < stacks->stack_b->next->value)
			swap(&stacks->stack_b, 1);
		while (stacks->stack_b)
			push_a(stacks);
		if (stacks->stack_a->next && stacks->stack_a->value > stacks->stack_a->next->value)
			swap(&stacks->stack_a, 0);
	}
	else
		sort_three_number(stacks);
}
