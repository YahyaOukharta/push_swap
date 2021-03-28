#include "push_swap.h"

int index_of_smallest(t_stack *s)
{
	int i;
	int min; 
	int ind;

	min = 2147483647;
	i = 0;
	while (i <= s->top_index)
	{
		if (s->content[i] < min)
		{
			min = s->content[i];
			ind = i;
		}
		i++;
	}
	return (ind);
}

void send_operations(t_stack *a, t_stack *b)
{
	int min_i;
	int dir;
	int i;

	while (!is_empty_s(a))
	{
		min_i = index_of_smallest(a);
		//printf("min i = %d, value = %d, mid point index = %d\n", min_i, a->content[min_i], a->top_index / 2);
		dir = min_i - (a->top_index / 2);
		//printf("dir = %d\n", dir);
		if (dir > 0)
		{
			i = a->top_index - min_i;
			while (i)
			{
				ft_putstr_fd("ra\n", 1);
				op_ra(a, b);
				i--;
			}
		}
		else
		{
			i = min_i + 1;
			while (i)
			{
				ft_putstr_fd("rra\n", 1);
				op_rra(a, b);
				i--;
			}
		}
		ft_putstr_fd("pb\n", 1);
		op_pb(a, b);
	}
	while (!is_empty_s(b))
	{
		ft_putstr_fd("pa\n", 1);
		op_pa(a, b);
	}
}

int main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	int			i;

	if (ac == 1)
		return (0);
	a = new_stack(ac - 1);
	b = new_stack(ac - 1);
	i = ac - 1;
	while (i > 0)
	{
		if (!is_valid_int(av[i]) || exists_in_stack(a, ft_atoi(av[i])))
			return (send_error(a, b, NULL));
		push_to_stack(a, ft_atoi(av[i]));
		i--;
	}
	//print_stack(a);
	send_operations(a, b);
	//print_stack(a);
	//print_stack(b);
	return (0);
}
