/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaro-l <gamaro-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:19:46 by gamaro-l          #+#    #+#             */
/*   Updated: 2023/06/29 11:11:31 by gamaro-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_amount(int length)
{
	if (length < 26)
		return (2);
	else if (length > 25 && length < 51)
		return (4);
	else if (length > 50 && length < 101)
		return (6);
	else if (length > 100)
		return (10);
	else
		return (0);
}

t_chunks	divide_chunks(int *ready4chunk, int length)
{
	t_chunks	ch;
	int			i;

	i = 0;
	ch.chunk_amount = get_chunk_amount(length);
	ch.chunk_size = length / ch.chunk_amount;
	ch.chunk = malloc(sizeof(int *) * ch.chunk_amount);
	while (i < ch.chunk_amount)
	{
		ch.chunk[i] = malloc(sizeof(int) * 2);
		ch.chunk[i][0] = ready4chunk[i * ch.chunk_size];
		if (i == ch.chunk_amount - 1)
		{
			ch.chunk[i][1] = ready4chunk[length - 4];
			ch.last_chunk = ((length - 4) - (ch.chunk_size * i)) + 1;
		}
		else
			ch.chunk[i][1] = ready4chunk[i * ch.chunk_size + ch.chunk_size - 1];
		i++;
	}
	free(ready4chunk);
	return (ch);
}

int	*getreadyfordivide(t_stack stk)
{
	int	i;
	int	l;
	int	*ready4chunk;
	int	temp;

	i = 0;
	l = -1;
	ready4chunk = malloc(sizeof(int) * stk.s_a);
	while (++l != stk.s_a)
	{
		ready4chunk[l] = stk.stack_a[l];
	}
	while (i != stk.s_a - 1)
	{
		if (ready4chunk[i] > ready4chunk[i + 1])
		{
			temp = ready4chunk[i];
			ready4chunk[i] = ready4chunk[i + 1];
			ready4chunk[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	return (ready4chunk);
}
