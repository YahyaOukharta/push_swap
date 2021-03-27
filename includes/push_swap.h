#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "get_next_line.h"
# include "limits.h"

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
int				exists_in_stack(t_stack *s, int value);
int				is_sorted_stack(t_stack *s);
void			print_stack(t_stack *s);

void			op_swap(t_stack *s);
void			op_push(t_stack *from, t_stack *to);
void			op_rotate(t_stack *s);
void			op_reverse_rotate(t_stack *s);

typedef struct	s_operations
{
	char		**op_codes;
	void		(*op_funcs[11])(t_stack *a, t_stack *b);
}				t_operations;

void			op_sa(t_stack *a, t_stack *b);
void			op_sb(t_stack *a, t_stack *b);
void			op_ss(t_stack *a, t_stack *b);
void			op_pa(t_stack *a, t_stack *b);
void			op_pb(t_stack *a, t_stack *b);
void			op_ra(t_stack *a, t_stack *b);
void			op_rb(t_stack *a, t_stack *b);
void			op_rr(t_stack *a, t_stack *b);
void			op_rra(t_stack *a, t_stack *b);
void			op_rrb(t_stack *a, t_stack *b);
void			op_rrr(t_stack *a, t_stack *b);
void			init_operations(t_operations **ops_table);
void			free_operations(t_operations *ops_table);

int				max(int a, int b);
int				free_s_tab(char **tab);
int				index_of_in_tab(char **tab, char *str);
int				is_valid_int(char *s);
int				send_error(t_stack *a, t_stack *b, t_operations *ops);

#endif
