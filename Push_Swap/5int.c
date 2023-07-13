/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5int.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaro-l <gamaro-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:30:16 by gamaro-l          #+#    #+#             */
/*   Updated: 2023/06/27 17:49:58 by gamaro-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	extrafunction(t_stack *s)
{
	revrotate_a(s);
	revrotate_a(s);
	push_b(s);
}

void	fiveint_findfirst(t_stack *s)
{
	if (s->stack_a[0] < s->stack_a[1] && s->stack_a[0] < s->stack_a[2] \
	&& s->stack_a[0] < s->stack_a[3] && s->stack_a[0] < s->stack_a[4])
		push_b(s);
	else if (s->stack_a[1] < s->stack_a[0] && s->stack_a[1] < s->stack_a[2] \
	&& s->stack_a[1] < s->stack_a[3] && s->stack_a[1] < s->stack_a[4])
	{
		rotate_a(s);
		push_b(s);
	}
	else if (s->stack_a[2] < s->stack_a[0] && s->stack_a[2] < s->stack_a[1] \
	&& s->stack_a[2] < s->stack_a[3] && s->stack_a[2] < s->stack_a[4])
	{
		rotate_a(s);
		rotate_a(s);
		push_b(s);
	}
	else if (s->stack_a[3] < s->stack_a[0] && s->stack_a[3] < s->stack_a[1] \
	&& s->stack_a[3] < s->stack_a[2] && s->stack_a[3] < s->stack_a[4])
		extrafunction(s);
	else if (s->stack_a[4] < s->stack_a[0] && s->stack_a[4] < s->stack_a[1] \
	&& s->stack_a[4] < s->stack_a[2] && s->stack_a[4] < s->stack_a[3])
	{
		revrotate_a(s);
		push_b(s);
	}
}

void	fiveint_findseccond(t_stack *s)
{
	if (s->stack_a[0] < s->stack_a[1] && s->stack_a[0] < s->stack_a[2] \
	&& s->stack_a[0] < s->stack_a[3])
		push_b(s);
	else if (s->stack_a[1] < s->stack_a[0] && s->stack_a[1] < s->stack_a[2] \
	&& s->stack_a[1] < s->stack_a[3])
	{
		rotate_a(s);
		push_b(s);
	}
	else if (s->stack_a[2] < s->stack_a[0] && s->stack_a[2] < s->stack_a[1] \
	&& s->stack_a[2] < s->stack_a[3])
	{
		rotate_a(s);
		rotate_a(s);
		push_b(s);
	}
	else if (s->stack_a[3] < s->stack_a[0] && s->stack_a[3] < s->stack_a[1] \
	&& s->stack_a[3] < s->stack_a[2])
	{
		revrotate_a(s);
		push_b(s);
	}
}

void	fiveint_main(t_stack *s)
{
	if (s->stack_a[0] < s->stack_a[1] && s->stack_a[0] < s->stack_a[2] \
	&& s->stack_a[0] < s->stack_a[3] && s->stack_a[0] < s->stack_a[4] \
	&& s->stack_a[1] < s->stack_a[2] && s->stack_a[1] < s->stack_a[3] \
	&& s->stack_a[1] < s->stack_a[4] && s->stack_a[2] < s->stack_a[3] \
	&& s->stack_a[2] < s->stack_a[4] && s->stack_a[3] < s->stack_a[4])
		return ;
	fiveint_findfirst(s);
	fiveint_findseccond(s);
	threeint_a(s);
	push_a(s);
	push_a(s);
}
