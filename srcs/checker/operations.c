#include "push_swap.h"

void	op_sa(t_stack *a, t_stack *b)
{
	op_swap(a);
}

void	op_sb(t_stack *a, t_stack *b)
{
	op_swap(a);
}

void	op_ss(t_stack *a, t_stack *b)
{
	op_swap(a);
	op_swap(b);
}

void	op_pa(t_stack *a, t_stack *b)
{
	op_push(b, a);
}

void	op_pb(t_stack *a, t_stack *b)
{
	op_push(a, b);
}

void	op_ra(t_stack *a, t_stack *b)
{
	op_rotate(a);
}

void	op_rb(t_stack *a, t_stack *b)
{
	op_rotate(b);
}

void	op_rr(t_stack *a, t_stack *b)
{
	op_rotate(a);
	op_rotate(b);
}

void	op_rra(t_stack *a, t_stack *b)
{
	op_reverse_rotate(a);
}

void	op_rrb(t_stack *a, t_stack *b)
{
	op_reverse_rotate(a);
}

void	op_rrr(t_stack *a, t_stack *b)
{
	op_reverse_rotate(a);
	op_reverse_rotate(b);
}

void	init_operations(t_operations **ops_table)
{
	*ops_table = (t_operations *)malloc(sizeof(t_operations));
	(*ops_table)->op_codes = ft_split("sa;sb;ss;pa;pb;ra;rb;rr;rra;rrb;rrr", ';');
	(*ops_table)->op_funcs[0] = op_sa;
	(*ops_table)->op_funcs[1] = op_sb;
	(*ops_table)->op_funcs[2] = op_ss;
	(*ops_table)->op_funcs[3] = op_pa;
	(*ops_table)->op_funcs[4] = op_pb;
	(*ops_table)->op_funcs[5] = op_ra;
	(*ops_table)->op_funcs[6] = op_rb;
	(*ops_table)->op_funcs[7] = op_rr;
	(*ops_table)->op_funcs[8] = op_rra;
	(*ops_table)->op_funcs[9] = op_rrb;
	(*ops_table)->op_funcs[10] = op_rrr;
}

void	free_operations(t_operations *ops_table)
{
	free_s_tab(ops_table->op_codes);
	free(ops_table);
}