#include "push_swap.h"

int		max(int a, int b)
{
	return (a > b ? a : b);
}

int		free_s_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
	return (0);
}

int		index_of_in_tab(char **tab, char *str)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (!ft_strncmp(str, tab[i], max(ft_strlen(str), ft_strlen(tab[i]))))
			return (i);
		i++;
	}
	return (-1);
}