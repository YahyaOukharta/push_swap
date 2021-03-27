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

void	free_operations(t_operations *ops_table)
{
	free_s_tab(ops_table->op_codes);
	free(ops_table);
}

int send_error(t_stack *a, t_stack *b, t_operations *ops)
{
	free_stack(a);
	free_stack(b);
	if (ops)
		free_operations(ops);
	ft_putstr_fd("Error\n", 2);
	return (1);
}