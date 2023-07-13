/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2int_3int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaro-l <gamaro-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:16:37 by gamaro-l          #+#    #+#             */
/*   Updated: 2023/06/27 15:27:56 by gamaro-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	twoint_a(t_stack *s)
{
	if (s->stack_a[0] > s->stack_a[1])
		swap_a(s);
	else if (s->stack_a[0] < s->stack_a[1])
		return ;
	return ;
}

void	twoint_b(t_stack *s)
{
	if (s->stack_b[0] < s->stack_b[1])
		swap_b(s);
	else if (s->stack_b[0] > s->stack_b[1])
		return ;
	return ;
}

void	threeint_a(t_stack *s)
{
	if (s->stack_a[0] < s->stack_a[1] \
	&& s->stack_a[0] < s->stack_a[2] \
	&& s->stack_a[1] < s->stack_a[2])
		return ;
	else if (s->stack_a[0] > s->stack_a[1] && s->stack_a[0] > s->stack_a[2])
	{
		if (s->stack_a[1] > s->stack_a[2])
		{
			rotate_a(s);
			swap_a(s);
		}
		else if (s->stack_a[1] < s->stack_a[2])
			rotate_a(s);
	}
	else if (s->stack_a[0] < s->stack_a[1] && s->stack_a[0] > s->stack_a[2])
		revrotate_a(s);
	else if (s->stack_a[0] > s->stack_a[1] && s->stack_a[0] < s->stack_a[2])
		swap_a(s);
	else if (s->stack_a[0] < s->stack_a[1] && s->stack_a[0] < s->stack_a[2])
	{
		swap_a(s);
		rotate_a(s);
	}
}

void	threeint_b(t_stack *s)
{
	if (s->stack_b[0] > s->stack_b[1] && s->stack_b[0] > s->stack_b[2]
		&& s->stack_b[1] > s->stack_b[2])
		return ;
	else if (s->stack_b[0] < s->stack_b[1] && s->stack_b[0] < s->stack_b[2])
	{
		if (s->stack_b[1] < s->stack_b[2])
		{
			rotate_b(s);
			swap_b(s);
		}
		else if (s->stack_b[1] > s->stack_b[2])
			rotate_b(s);
	}
	else if (s->stack_b[0] > s->stack_b[1] && s->stack_b[0] < s->stack_b[2])
		revrotate_b(s);
	else if (s->stack_b[0] < s->stack_b[1] && s->stack_b[0] > s->stack_b[2])
		swap_b(s);
	else if (s->stack_b[0] > s->stack_b[1] && s->stack_b[0] > s->stack_b[2])
	{
		swap_b(s);
		rotate_b(s);
	}
}
