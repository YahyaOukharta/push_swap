#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct	s_stack
{
	int			capacity;
	int			top_index;
	int			*content;
}				t_stack;

t_stack			*new_stack(int capacity);
int				is_empty_s(t_stack *s);
int				is_full_s(t_stack *s);
int				pop_stack(t_stack *s);
int				push_to_stack(t_stack *s, int i);
int				stack_size(t_stack *s);
void			free_stack(t_stack *s);


void			op_swap(t_stack *s);
void			op_push(t_stack *from, t_stack *to);
void			op_rotate(t_stack *s);
void			op_reverse_rotate(t_stack *s);

#endif
