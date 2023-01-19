/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaro-l <gamaro-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:00:00 by gamaro-l          #+#    #+#             */
/*   Updated: 2023/01/19 16:48:56 by gamaro-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
    int	*stack_a;
    int	*stack_b;
    int	s_a;
    int	s_b;
}	t_stack;

void twoint(t_stack *stk);
void threeint(t_stack *stk);
void swap(t_stack *stk);
void rotate(t_stack *stk);
int	ft_atoi(const char *str);

#endif
