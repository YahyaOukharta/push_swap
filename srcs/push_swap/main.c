#include "push_swap.h"

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
	print_stack(a);
	return (0);
}
