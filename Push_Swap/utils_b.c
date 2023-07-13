/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaro-l <gamaro-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:18:31 by gamaro-l          #+#    #+#             */
/*   Updated: 2023/07/11 18:54:14 by gamaro-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pusha_extra(t_stack *stk, int *temp, int *temp2)
{
	if (stk->stack_a)
		free(stk->stack_a);
	stk->stack_a = temp2;
	if (stk->stack_b)
		free(stk->stack_b);
	stk->stack_b = temp;
	write(1, "pa\n", 3);
}

void	rotate_b(t_stack *stk)
{
	int	j;
	int	temp;

	j = 0;
	temp = stk->stack_b[0];
	while (j < stk->s_a - 1)
	{
		stk->stack_b[j] = stk->stack_b[j + 1];
		j++;
	}
	stk->stack_b[j] = temp;
	write(1, "rb\n", 3);
}

void	revrotate_b(t_stack *stk)
{
	int	j;
	int	temp;

	j = 0;
	temp = stk->stack_b[stk->s_b - 1];
	while (j < stk->s_b - 1)
	{
		j++;
	}
	while (j > 0)
	{
		stk->stack_b[j] = stk->stack_b[j - 1];
		j--;
	}
	stk->stack_b[0] = temp;
	write(1, "rrb\n", 4);
}

void	swap_b(t_stack *stk)
{
	int	temp;

	temp = stk->stack_b[0];
	stk->stack_b[0] = stk->stack_b[1];
	stk->stack_b[1] = temp;
	write(1, "sb\n", 3);
}

void	push_a(t_stack *stk)
{
	int		*temp;
	int		*temp2;
	int		i;
	int		j;

	j = -1;
	i = -1;
	temp = malloc(sizeof(int) * stk->s_b);
	if (!temp)
		falta_memoria(stk);
	while (++i < stk->s_b - 1)
		temp[i] = stk->stack_b[i + 1];
	stk->s_b--;
	stk->s_a++;
	temp2 = malloc(sizeof(int) * stk->s_a);
	if (!temp2)
		falta_memoria(stk);
	temp2[0] = stk->stack_b[0];
	while (++j < stk->s_a - 1)
		temp2[j + 1] = stk->stack_a[j];
	pusha_extra(stk, temp, temp2);
}
