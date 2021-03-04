#include "push_swap.h"

int main(int ac, char **av)
{
    ft_putstr_fd("CHECKER\n",1);

    t_stack     *a = new_stack(100);
    int           i = 0;


    while (!is_full_s(a))
    {
        push_to_stack(a, i++);
    }

    ft_putnbr_fd(stack_size(a), 1);
    ft_putchar_fd('\n', 1);
    while (!is_empty_s(a))
    {
        ft_putnbr_fd(pop_stack(a), 1);
        ft_putchar_fd(' ', 1);
    }
    ft_putnbr_fd(stack_size(a), 1);
    ft_putchar_fd('\n', 1);
    return (0);
}