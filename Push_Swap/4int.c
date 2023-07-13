/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4int.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaro-l <gamaro-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:20:27 by gamaro-l          #+#    #+#             */
/*   Updated: 2023/06/27 17:29:59 by gamaro-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fourint_find_first(t_stack *stk)
{
	if (stk->stack_a[0] < stk->stack_a[1] && stk->stack_a[0] < stk->stack_a[2]
		&& stk->stack_a[0] < stk->stack_a[3])
	{
		push_b(stk);
	}
	else if (stk->stack_a[3] < stk->stack_a[1] && stk->stack_a[3] \
	< stk->stack_a[2] && stk->stack_a[3] < stk->stack_a[0])
	{
		revrotate_a(stk);
		push_b(stk);
	}
	else if (stk->stack_a[2] < stk->stack_a[1] && stk->stack_a[2] \
	< stk->stack_a[3] && stk->stack_a[2] < stk->stack_a[0])
	{
		revrotate_a(stk);
		revrotate_a(stk);
		push_b(stk);
	}
	else if (stk->stack_a[1] < stk->stack_a[2] && stk->stack_a[1] \
	< stk->stack_a[3] && stk->stack_a[1] < stk->stack_a[0])
	{
		rotate_a(stk);
		push_b(stk);
	}
}

void	fourint_find_secc(t_stack *stk)
{
	if (stk->stack_a[0] < stk->stack_a[1] && stk->stack_a[0] < stk->stack_a[2])
	{
		push_b(stk);
	}
	else if (stk->stack_a[2] < stk->stack_a[1] && stk->stack_a[2] \
	< stk->stack_a[0])
	{
		revrotate_a(stk);
		push_b(stk);
	}
	else if (stk->stack_a[1] < stk->stack_a[2] && stk->stack_a[1] \
	< stk->stack_a[0])
	{
		rotate_a(stk);
		push_b(stk);
	}
}

void	fourint_main(t_stack *stk)
{
	if (stk->stack_a[0] < stk->stack_a[1] && stk->stack_a[0] < stk->stack_a[2] \
	&& stk->stack_a[0] < stk->stack_a[3] && stk->stack_a[1] < stk->stack_a[2] \
	&& stk->stack_a[1] < stk->stack_a[3] && stk->stack_a[2] < stk->stack_a[3])
		return ;
	fourint_find_first(stk);
	fourint_find_secc(stk);
	twoint_a(stk);
	push_a(stk);
	push_a(stk);
}
