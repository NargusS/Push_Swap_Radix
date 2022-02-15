#include "./push_swap.h"

void	swap(t_stack **stack, int is_stack)
{
	t_stack	*my_stack;
	t_stack	*second;

	if (get_size_of_stack(*stack) >= 2)
	{
		my_stack = *stack;
		second = my_stack->next;
		my_stack->next = second->next;
		second->next = my_stack;
		*stack = second;
		if (is_stack == 0)
			write(1, "sa\n", 3);
		else
			write(1, "sb\n", 3);
	}
}

void	reverse_rotate(t_stack **stack, int is_stack)
{
	t_stack	*my_stack;
	t_stack	*last;

	if (get_size_of_stack(*stack) >= 2)
	{
		my_stack = *stack;
		last = get_last_of_my_stack(*stack);
		while (my_stack->next->next != NULL)
			my_stack = my_stack->next;
		my_stack->next = NULL;
		last->next = *stack;
		*stack = last;
		if (is_stack == 0)
			write(1, "rra\n", 4);
		else
			write(1, "rrb\n", 4);
	}
}

void	rotate(t_stack **stack, int is_stack)
{
	t_stack	*my_stack;
	t_stack	*last;

	if (get_size_of_stack(*stack) >= 2)
	{
		last = get_last_of_my_stack(*stack);
		my_stack = *stack;
		*stack = (*stack)->next;
		last->next = my_stack;
		my_stack->next = NULL;
		if (is_stack == 0)
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
	}
}

void	push_a(t_data *stacks)
{
	t_stack	*first_of_b;

	if (get_size_of_stack(stacks->stack_b) >= 1)
	{
		first_of_b = stacks->stack_b;
		stacks->stack_b = stacks->stack_b->next;
		first_of_b->next = stacks->stack_a;
		stacks->stack_a = first_of_b;
		write(1, "pa\n", 3);
	}
}

void	push_b(t_data *stacks)
{
	t_stack	*first_of_a;

	if (get_size_of_stack(stacks->stack_a) >= 1)
	{
		first_of_a = stacks->stack_a;
		stacks->stack_a = stacks->stack_a->next;
		first_of_a->next = stacks->stack_b;
		stacks->stack_b = first_of_a;
		write(1, "pb\n", 3);
	}
}
