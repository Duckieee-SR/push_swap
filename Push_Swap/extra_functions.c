/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaro-l <gamaro-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:37:55 by gamaro-l          #+#    #+#             */
/*   Updated: 2023/06/28 18:29:41 by gamaro-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	position_extras(t_stack *stk, int min, int pos, int i)
{
	min = stk->stack_a[0];
	pos = 0;
	while (++i < stk->s_a)
	{
		if (stk->stack_a[i] < min)
		{
			min = stk->stack_a[i];
			pos = i;
		}
	}
	return (pos);
}

int	position_extras_2(t_stack *stk, int val, int i)
{
	while (++i < stk->s_a)
	{
		if (i == 0)
		{
			if (stk->stack_a[stk->s_a - 1] < val && stk->stack_a[0] > val)
				return (0);
		}
		else
		{
			if (stk->stack_a[i - 1] < val && stk->stack_a[i] > val)
				return (i);
		}
	}
	return (0);
}
