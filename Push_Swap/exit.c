/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaro-l <gamaro-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:34:37 by gamaro-l          #+#    #+#             */
/*   Updated: 2023/07/11 19:07:51 by gamaro-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	falta_memoria(t_stack *stk)
{
	if (stk->stack_a)
		free(stk->stack_a);
	if (stk->stack_b)
		free(stk->stack_b);
	write(1, "Lack of Memory\n", 16);
	exit(1);
}

void	error(t_stack *stk)
{
	if (stk->stack_a)
		free(stk->stack_a);
	if (stk->stack_b)
		free(stk->stack_b);
	write(1, "Error\n", 6);
	exit(1);
}

void	no_argument(t_stack *stk)
{
	if (stk->stack_a)
		free(stk->stack_a);
	if (stk->stack_b)
		free(stk->stack_b);
	exit(1);
}
