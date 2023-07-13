/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaro-l <gamaro-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:11:34 by gamaro-l          #+#    #+#             */
/*   Updated: 2023/07/11 22:48:30 by gamaro-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	main_extras(int argc, char **argv, int temp, t_stack *stk)
{
	int	j;
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		temp = ft_atoi(argv[i + 1]);
		stk->stack_a[i] = ft_atoi(argv[i + 1]);
		j = 0;
		while (j < i)
		{
			if (temp == stk->stack_a[j])
			{
				printf("Error\n");
				free(stk->stack_a);
				exit(-1);
			}
			j++;
		}
		i++;
	}
}

void	main_hardcode(t_stack stk)
{
	if (stk.s_a == 2)
		twoint_a(&stk);
	else if (stk.s_a == 3)
		threeint_a(&stk);
	else if (stk.s_a == 4)
		fourint_main(&stk);
	else if (stk.s_a == 5)
		fiveint_main(&stk);
}

void	main_algorithm(t_stack *stk)
{
	int i;

	i = -1;
	while (stk->stack_a[i] < stk->stack_a[i + 1])
	{
		i++;
	}
	if (i == stk->s_a)
	{
		no_argument(stk);
	}
	else if (i != stk->s_a)
	{
		send_chunks(stk, divide_chunks(getreadyfordivide(*stk), stk->s_a));
		threeint_a(stk);
		while (stk->s_b)
		{
			send_back_from_b(stk);
		}
		rotate_until_sorted(stk);
	}
}

int	main(int argc, char **argv)
{
	t_stack	stk;
	int		temp;

	temp = 0;
	stk.s_a = (argc - 1);
	stk.s_b = 0;
	stk.stack_a = malloc(sizeof(int) * stk.s_a);
	stk.stack_b = NULL;
	if (!stk.stack_a)
	{
		write(1, "Lack of Memory\n", 16);
		exit(-1);
	}
	main_extras(argc, argv, temp, &stk);
	if (stk.s_a > 1 && stk.s_a < 6)
		main_hardcode(stk);
	else if (stk.s_a > 5)
		main_algorithm(&stk);
	else if(stk.s_a == 0)
		no_argument(&stk);
	else
		error(&stk);
	free(stk.stack_a);
	free(stk.stack_b);
}
