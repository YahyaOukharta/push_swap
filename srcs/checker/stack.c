#include "push_swap.h"

t_stack			*new_stack(int capacity)
{
	t_stack		*s;

	if (!(s = (t_stack *)malloc(sizeof(t_stack))))
		return (0);
	s->capacity = capacity;
	s->content = (int *)malloc(sizeof(int) * s->capacity);
	s->top_index = -1;
	return (s);
}

void			free_stack(t_stack *s)
{
	free(s->content);
	free(s);
}

int				is_empty_s(t_stack *s)
{
	return (s->top_index == -1);
}

int				is_full_s(t_stack *s)
{
	return (s->top_index == s->capacity - 1);
}

int				pop_stack(t_stack *s)
{
	if (is_empty_s(s))
		return (-1);
	return (s->content[s->top_index--]);
}

int				push_to_stack(t_stack *s, int i)
{
	if (is_full_s(s))
		return (0);
	s->top_index++;
	s->content[s->top_index] = i;
	return (1);
}

int				stack_size(t_stack *s)
{
	return (s->top_index + 1);
}

int				exists_in_stack(t_stack *s, int value)
{
	int	i;

	i = 0;
	while (i <= s->top_index)
	{
		if (s->content[i] == value)
			return (1);
		i++;
	}
	return (0);
}