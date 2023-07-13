/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaro-l <gamaro-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:27:25 by gamaro-l          #+#    #+#             */
/*   Updated: 2023/07/11 18:54:08 by gamaro-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushb_extras(t_stack *stk, int *temp, int *temp2)
{
	if (stk->stack_b)
		free(stk->stack_b);
	stk->stack_b = temp2;
	if (stk->stack_a)
		free(stk->stack_a);
	stk->stack_a = temp;
	write(1, "pb\n", 3);
}

void	rotate_a(t_stack *stk)
{
	int	j;
	int	temp;

	j = 0;
	temp = stk->stack_a[0];
	while (j < stk->s_a - 1)
	{
		stk->stack_a[j] = stk->stack_a[j + 1];
		j++;
	}
	stk->stack_a[j] = temp;
	write(1, "ra\n", 3);
}

void	revrotate_a(t_stack *stk)
{
	int	j;
	int	temp;

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
	write(1, "rra\n", 4);
}

void	swap_a(t_stack *stk)
{
	int	temp;

	temp = stk->stack_a[0];
	stk->stack_a[0] = stk->stack_a[1];
	stk->stack_a[1] = temp;
	write(1, "sa\n", 3);
}

void	push_b(t_stack *stk)
{
	int		*temp;
	int		*temp2;
	int		i;
	int		j;

	i = -1;
	j = -1;
	temp = malloc(sizeof(int) * stk->s_a);
	if (!temp)
		falta_memoria(stk);
	while (++i < stk->s_a - 1)
		temp[i] = stk->stack_a[i + 1];
	stk->s_a--;
	stk->s_b++;
	temp2 = malloc(sizeof(int) * stk->s_b);
	if (!temp2)
		falta_memoria(stk);
	temp2[0] = stk->stack_a[0];
	while (++j < stk->s_b - 1)
		temp2[j + 1] = stk->stack_b[j];
	pushb_extras(stk, temp, temp2);
}
