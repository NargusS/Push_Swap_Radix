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

static void	sort_three_element(t_data *stacks)
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
		swap(stacks->stack_a, 0);
	}
	else if (less_than(fst, scd) && tall_than(scd, trd) && tall_than(fst, trd))
		reverse_rotate(&stacks->stack_a, 0);
	else if (tall_than(fst, scd) && less_than(scd, trd) && tall_than(fst, trd))
		rotate(&stacks->stack_a, 0);
	else if (tall_than(fst, scd) && tall_than(scd, trd))
	{
		swap_a(stacks->stack_a, PRINT_CMD);
		reverse_rotate_a(&stacks->stack_a, PRINT_CMD);
	}
	else
		swap_a(stacks->stack_a, PRINT_CMD);
}

void    load_algo(t_data *stacks)
{
    int size;

    size = get_size_of_stack(stacks->stack_a);
    if (size == 2)
        //rotate
    else if (size == 3)
        //algo 3
    else if (size <= 5)
        //algo 5
    else
        //radix_sort
}