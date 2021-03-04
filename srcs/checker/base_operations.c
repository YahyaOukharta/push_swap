#include "push_swap.h"

void    op_swap(t_stack *s)
{
    int tmp[2];

    if (stack_size(s) >= 2)
    {
        tmp[0] = pop_stack(s);
        tmp[1] = pop_stack(s);
        push_to_stack(s, tmp[0]);
        push_to_stack(s, tmp[1]);
    }
}

void    op_push(t_stack *from, t_stack *to)
{
    if (stack_size(from) >= 1)
        push_to_stack(to, pop_stack(from));
}

void    op_rotate(t_stack *s)
{
    int     top;
    t_stack *tmp_s;

    if (stack_size(s) >= 2)
    {
        if (!(tmp_s = new_stack(stack_size(s) - 1)))
            return ;
        top = pop_stack(s);
        while (!is_empty_s(s))
            push_to_stack(tmp_s, pop_stack(s));
        push_to_stack(s, top);
        while (!is_empty_s(tmp_s))
            push_to_stack(s, pop_stack(tmp_s));
        free_stack(tmp_s);
    }
}

void    op_reverse_rotate(t_stack *s)
{
    int     bottom;
    t_stack *tmp_s;

    if (stack_size(s) >= 2)
    {
        if (!(tmp_s = new_stack(stack_size(s) - 1)))
            return ;
        while (stack_size(s) > 1)
            push_to_stack(tmp_s, pop_stack(s));
        bottom = pop_stack(s);
        while (!is_empty_s(tmp_s))
            push_to_stack(s, pop_stack(tmp_s));
        push_to_stack(s, bottom);
        free_stack(tmp_s);
    }
}