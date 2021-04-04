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

	if (is_sorted_stack(a))
		return ;
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

void	send_operations_3(t_stack *a, t_stack *b)
{
	if (a->content[2] < a->content[1] && a->content[1] > a->content[0] && a->content[0] < a->content[2])
	{
		ft_putstr_fd("rra\n", 1);
		op_rra(a, b);
		return ;
	}
	if (a->content[2] > a->content[1] && a->content[1] < a->content[0] && a->content[0] < a->content[2])
	{
		ft_putstr_fd("ra\n", 1);
		op_ra(a, b);
		return ;
	}
	if (a->content[2] > a->content[1])
	{
		ft_putstr_fd("sa\n", 1);
		op_sa(a, b);
		if (a->content[2] < a->content[1] && a->content[1] > a->content[0] && a->content[0] < a->content[2])
		{
			ft_putstr_fd("rra\n", 1);
			op_rra(a, b);
		}
	}
	else if (a->content[1] > a->content[0])
	{
		ft_putstr_fd("sa\n", 1);
		op_sa(a, b);
		ft_putstr_fd("ra\n", 1);
		op_ra(a, b);
	}
}

void	send_operations_5(t_stack *a, t_stack *b)
{
	int i = 0;
	ft_putstr_fd("pb\npb\n", 1);
	op_pb(a, b);
	op_pb(a, b);
	send_operations_3(a, b);
	print_stack(a);
	print_stack(b);
	if (a->content[0] > b->content[1])
	{
		while (a->content[2] < b->content[1])
		{
			ft_putstr_fd("ra\n", 1);
			op_ra(a, b);
			i++;
		}
		ft_putstr_fd("pa\n", 1);
		op_pa(a, b);
	}
	else
	{
		ft_putstr_fd("pa\n", 1);
		op_pa(a, b);
		ft_putstr_fd("ra\n", 1);
		op_ra(a, b);
	}
	print_stack(a);
	print_stack(b);
	while (i > 0)
	{
		ft_putstr_fd("ra\n", 1);
		op_ra(a, b);
		i--;
	}
	if (a->content[0] > b->content[0])
	{
		while (a->content[2] < b->content[0])
		{
			ft_putstr_fd("rra\n", 1);
			op_rra(a, b);
			i++;
		}
	}
	else
	{
		ft_putstr_fd("pa\n", 1);
		op_pa(a, b);
		ft_putstr_fd("ra\n", 1);
		op_ra(a, b);
	}
	ft_putstr_fd("pa\n", 1);
	op_pa(a, b);
	print_stack(a);
	print_stack(b);
	while (i > 0)
	{
		ft_putstr_fd("ra\n", 1);
		op_ra(a, b);
		i--;
	}
	print_stack(a);
	print_stack(b);
}

// 1 2 4     3 -1

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
	if (is_sorted_stack(a))
		return (0);
	//print_stack(a);
	if (stack_size(a) == 3)
		send_operations_3(a, b);
	else if (stack_size(a) == 5)
		send_operations_5(a, b);
	else
		send_operations(a, b);
	print_stack(a);
	print_stack(b);
	free_stack(a);
	free_stack(b);
	
	return (0);
}
