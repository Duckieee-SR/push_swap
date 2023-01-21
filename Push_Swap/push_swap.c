
#include "push_swap.h"

int	ft_atoi(const char *str)
{
	unsigned int	w;
	unsigned int	mc;
	unsigned int	res;

	w = 0;
	mc = 1;
	res = 0;
	while (str[w] == '\t' || str[w] == '\n' || str[w] == '\v' || str[w] == '\f'
		|| str[w] == '\r' || str[w] == ' ')
		w++;
	if (str[w] == '-')
	{
		mc *= -1;
		w++;
	}
	else if (str[w] == '+')
		w++;
	while (str[w] >= '0' && str[w] <= '9')
	{
		res = (res * 10) + (str[w] - '0');
		w++;
	}
	return (res * mc);
}

void rotate_a(t_stack *stk)
{
    int j;
    int temp;

    j = 0;
    temp = stk->stack_a[0];
    while (j < stk->s_a - 1)
    {
        stk->stack_a[j] = stk->stack_a[j + 1];
        j++;
    }
    stk->stack_a[j] = temp;
}

void revrotate_a(t_stack *stk)
{
    int j;
	int temp;

	j = 0;
	temp = stk->stack_a[stk->s_a - 1];
        while (j < stk->s_a - 1)
        {
                j++;
        }
        while (j > 0)
        {
                stk->stack_a[j] = stk->stack_a[j - 1]; 
                j--;
        }
        stk->stack_a[0] = temp;
}

void swap_a(t_stack *stk)
{
    int temp;

    temp = stk->stack_a[0];
    stk->stack_a[0] = stk->stack_a[1];
    stk->stack_a[1] = temp;
}

void twoint(t_stack *stk)
{
        if(stk->stack_a[0] > stk->stack_a[1])
                swap_a(stk);
        else if(stk->stack_a[0] < stk->stack_a[1])
                return;
        return;
}

void fiveint(t_stack *stk)
{
        
}

void threeint(t_stack *stk)
{
        if(stk->stack_a[0] > stk->stack_a[1] && stk->stack_a[0] > stk->stack_a[2])
        {
                if(stk->stack_a[1] > stk->stack_a[2])
                {
                        rotate_a(stk);
                        swap_a(stk);
                }
                else if(stk->stack_a[1] < stk->stack_a[2])
                        rotate_a(stk);
        }
        else if(stk->stack_a[0] < stk->stack_a[1] && stk->stack_a[0] > stk->stack_a[2])
                revrotate_a(stk);
        else if(stk->stack_a[0] > stk->stack_a[1] && stk->stack_a[0] < stk->stack_a[2])
                swap_a(stk);
        else if(stk->stack_a[0] < stk->stack_a[1] && stk->stack_a[0] < stk->stack_a[2])
        {
                swap_a(stk);
                rotate_a(stk);
        }
        else if (stk->stack_a[0] < stk->stack_a[1] && stk->stack_a[0] < stk->stack_a[2])
                return;
}


int main(int argc, char **argv)
{
        t_stack stk;
        int temp;
        int a[argc - 1];
        int i;
        int j;

        i = 0;
        j = 0;
        stk.s_a = (argc - 1);
        stk.s_b = 0;
        stk.stack_a = malloc(sizeof(int) * stk.s_a);
        while (i < argc - 1)
        {
                temp = ft_atoi(argv[i + 1]);
                stk.stack_a[i] = ft_atoi(argv[i + 1]);
                while(j < i)
                {
                        if (temp == stk.stack_a[j])
                        {
                                printf("Error\n");
                                free(stk.stack_a);
                                return (0);
                        }
                        j++;
                }
                i++;
        }
        if (stk.s_a == 2)
                twoint(&stk);
        else if (stk.s_a == 3)
                threeint(&stk);
        i = 0;
        while (i < stk.s_a)
        {
                printf("%d\n", stk.stack_a[i]);
                i++;
        }
        free(stk.stack_a);
}