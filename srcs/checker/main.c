#include "push_swap.h"

int is_valid_int(char *s)
{
	int i;
	char *tmp;

	i = -1;
	while (s[++i])
	{
		if (!ft_isdigit(s[i]) && !(i == 0 && s[i] == '-'))
			return (0);
	}
	tmp = ft_itoa(ft_atoi(s));
	i = ft_strlen(tmp);
	free(tmp);
	return (ft_strlen(s) == i);
}

int				is_sorted_stack(t_stack *s)
{
	int tmp;
	int tmp2;

	tmp = pop_stack(s);
	while (!is_empty_s(s))
	{
		tmp2 = pop_stack(s);
		if (tmp > tmp2)
			return (0);
		tmp = tmp2;
	}
	return (1);
}

int send_error(t_stack *a, t_stack *b, t_operations *ops)
{
	free_stack(a);
	free_stack(b);
	free_operations(ops);
	ft_putstr_fd("Error\n", 2);
	return (1);
}

int main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	int			i;
	char		*line;
	t_operations *ops;

	if (ac == 1)
		return (0);
	init_operations(&ops);
	a = new_stack(ac - 1);
	b = new_stack(ac - 1);
	i = ac - 1;
	while (i > 0)
	{
		if (!is_valid_int(av[i]))
			return (send_error(a, b, ops));
		push_to_stack(a, ft_atoi(av[i]));
		i--;
	}
	while (get_next_line(0, &line) > 0)
	{
		if ((i = index_of_in_tab(ops->op_codes, line)) == -1)
			return (send_error(a, b, ops));
		else
			ops->op_funcs[i](a, b);
		free(line);
	}
	free(line);
	ft_putstr_fd((!stack_size(b) && is_sorted_stack(a) ? "OK" : "KO"), 1);
	free_stack(a);
	free_stack(b);
	free_operations(ops);
	return (0);
}