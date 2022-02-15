#include "./push_swap.h"

int		add_to_stack(t_data *stacks, int num)
{
	t_stack *new_element;

	new_element = malloc(sizeof(t_stack));
	if (new_element == NULL)
		return (-1);
	new_element->value = num;
	new_element->next = NULL;
	if (stacks->stack_a == NULL)
		stacks->stack_a = new_element;
	else
	{
		if (check_is_value_exist(stacks->stack_a, num) == -1)
		{
			free(new_element);
			return(-1);
		}
		else
			get_last_of_my_stack(stacks->stack_a)->next = new_element;
	}
	return (1);
}

int	atoi_and_add(t_data *stacks, char *arg)
{
	long long int	num;
	long long int	sign;

	num = 0;
	sign = 1;
	if (*arg == 0 || ft_strlen(arg) > 11 || (*arg == '-' && \
	(*(arg + 1) < '0' && *(arg + 1) < '9')))
		return (-1);
	if (*arg == '-')
	{
		sign = -1;
		arg++;
	}
	while (*arg >= '0' && *arg <= '9')
	{
		num = (num * 10) + (*arg - 48);
		arg++;
	}
	if (*arg != '\0' || num < INT_MIN || num > INT_MAX || \
	add_to_stack(stacks, num * sign) == -1)
		return (-1);
	return (1);
}

static int	get_index(t_stack *start,int value)
{
	int	index;

	index = 0;
	while (start != NULL)
	{
		if (value > start->value)
			index++;
		start = start->next;
	}
	return (index);
}

static void	init_index(t_stack *stack_a)
{
	t_stack	*start;

	start = stack_a;
	while (stack_a)
	{
		stack_a->index = get_index(start, stack_a->value);
		stack_a = stack_a->next;
	}
}

void	init_stacks(t_data *stacks, int argc, char **argv)
{
	int i;

	i = 1;
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	while (i < argc)
	{
		if (atoi_and_add(stacks, argv[i]) == -1)
		{
			free_my_stack(stacks->stack_a);
			exit(-1);
		}
		i++;
	}
	init_index(stacks->stack_a);
}