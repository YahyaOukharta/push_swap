//#include "push_swap.h"

void print_line(int n)
{
    for (int i = 232; i <= 255; i++)
    {
        //if (i % 4 == 0 && i != 0)
        printf("\033[48;5;%dm %*c\033[m", i, n,' ');
    }
}

int main(int ac, char ** av)
{
    print_line(1);
    return (0);
}