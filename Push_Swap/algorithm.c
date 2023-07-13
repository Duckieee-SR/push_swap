/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaro-l <gamaro-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:03:19 by gamaro-l          #+#    #+#             */
/*   Updated: 2023/06/29 11:09:33 by gamaro-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_extras(t_stack *stk, int pos)
{
	if (pos < stk->s_a / 2 + stk->s_a % 2)
	{
		while (pos)
		{
			rotate_a(stk);
			pos--;
		}
	}
	else
	{
		pos = stk->s_a - pos;
		while (pos)
		{
			revrotate_a(stk);
			pos--;
		}
	}
}

void	send_chunks(t_stack *stk, t_chunks ch)
{
	int	j;
	int	p;

	j = -1;
	while (++j < ch.chunk_amount)
	{
		p = 0;
		while ((p < ch.chunk_size && j < ch.chunk_amount - 1) || \
		(p < ch.last_chunk && j == ch.chunk_amount - 1))
		{
			if (stk->stack_a[0] >= ch.chunk[j][0] && \
			stk->stack_a[0] <= ch.chunk[j][1])
			{
				push_b(stk);
				p++;
			}
			else
				rotate_a(stk);
		}
	}
	j = -1;
	while (++j < ch.chunk_amount)
		free(ch.chunk[j]);
	free(ch.chunk);
}

void	send_back_from_b(t_stack *stk)
{
	int	pos;

	if (stk->s_b)
		pos = find_correct_position(stk, stk->stack_b[0]);
	if (pos < stk->s_a / 2 + stk->s_a % 2)
	{
		while (pos)
		{
			rotate_a(stk);
			pos--;
		}
	}
	else
	{
		pos = stk->s_a - pos;
		while (pos)
		{
			revrotate_a(stk);
			pos--;
		}
	}
	push_a(stk);
}

int	find_correct_position(t_stack *stk, int val)
{
	int	pos;
	int	min;
	int	i;

	min = 1;
	i = -1;
	pos = 0;
	while (++i < stk->s_a)
	{
		if (val > stk->stack_a[i])
		{
			min = 0;
			break ;
		}
	}
	i = -1;
	if (min)
		return (position_extras(stk, min, pos, i));
	return (position_extras_2(stk, val, i));
}

void	rotate_until_sorted(t_stack *stk)
{
	int	pos;
	int	min;
	int	i;

	min = stk->stack_a[0];
	pos = 0;
	i = -1;
	while (++i < stk->s_a)
	{
		if (stk->stack_a[i] < min)
		{
			min = stk->stack_a[i];
			pos = i;
		}
	}
	rotate_extras(stk, pos);
}
