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

int index_of_second_smallest(t_stack *s)
{
	int i;
	int min; 
	int ind;
	int smallest_ind;

	min = 2147483647;
	i = 0;
	smallest_ind = index_of_smallest(s);
	//printf("%d\n", smallest_ind);
	while (i <= s->top_index)
	{
		if (s->content[i] < min && s->content[i] > s->content[smallest_ind])
		{
			min = s->content[i];
			ind = i;
		}
		i++;
	}
	return (ind);
}

void	move_smallest_to_top(t_stack *a, t_stack *b)
{
	int i;
	int min_i;
	int dir;

	min_i = index_of_smallest(a);
	dir = min_i - (a->top_index / 2);
	if (dir > 0)
	{
		i = a->top_index - min_i;
		while (i)
		{
			ft_putstr_fd("rra\n", 1);
			op_rra(a, b);
			i--;
		}
	}
	else
	{
		i = min_i + 1;
		while (i)
		{
			ft_putstr_fd("ra\n", 1);
			op_ra(a, b);
			i--;
		}
	}
}

void	move_easiest_smallest_to_top(t_stack *a, t_stack *b)
{
	int i[2];
	int min_i[2];
	int dir[2];
	int j ;
	int d;
	
	min_i[0] = index_of_smallest(a);
	dir[0] = min_i[0] - (a->top_index / 2);
	if (dir[0] > 0)
		i[0] = a->top_index - min_i[0]; //ra
	else
		i[0] = min_i[0] + 1; //rra
	
	min_i[1] = index_of_second_smallest(a);
	dir[1] = min_i[1] - (a->top_index / 2);
	if (dir[1] > 0)
		i[1] = a->top_index - min_i[1]; //ra
	else
		i[1] = min_i[1] + 1; //rra

	j = (i[0] < i[1] ? i[0] : i[1]);
	d = (i[0] < i[1] ? dir[0] : dir[1]);
	while (j)
	{
		if (dir > 0)
		{
			ft_putstr_fd("rra\n", 1);
			op_rra(a, b);
		}
		else
		{
			ft_putstr_fd("ra\n", 1);
			op_ra(a, b);
		}
		j--;
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
	move_easiest_smallest_to_top(a, b);
	ft_putstr_fd("pb\n", 1);
	op_pb(a, b);
	move_smallest_to_top(a, b);
	ft_putstr_fd("pb\n", 1);
	op_pb(a, b);
	send_operations_3(a, b);
	//print_stack(a);
	//print_stack(b);

	ft_putstr_fd("pa\n", 1);
	op_pa(a, b);
	ft_putstr_fd("pa\n", 1);
	op_pa(a, b);
	//print_stack(a);
	//print_stack(b);
	if ( a->content[4] > a->content[3])
	{
		ft_putstr_fd("sa\n", 1);
		op_sa(a, b);
	}
	//print_stack(a);
	//print_stack(b);
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

	// print_stack(a);
	// print_stack(b);
	free_stack(a);
	free_stack(b);
	
	return (0);
}
