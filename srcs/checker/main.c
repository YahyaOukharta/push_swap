#include "push_swap.h"

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
		if (!is_valid_int(av[i]) || exists_in_stack(a, ft_atoi(av[i])))
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
	ft_putstr_fd((!stack_size(b) && is_sorted_stack(a) ? "OK\n" : "KO\n"), 1);
	free_stack(a);
	free_stack(b);
	free_operations(ops);
	return (0);
}