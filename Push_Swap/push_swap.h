/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamaro-l <gamaro-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:00:00 by gamaro-l          #+#    #+#             */
/*   Updated: 2023/07/11 19:08:45 by gamaro-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define MOVE_SIZE 4

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	s_a;
	int	s_b;
}	t_stack;

typedef struct s_chunks
{
	int	**chunk;
	int	last_chunk;
	int	chunk_amount;
	int	chunk_size;
}	t_chunks;

int			ft_atoi(const char *str);
void		twoint_a(t_stack *stk);
void		threeint_a(t_stack *stk);
void		swap_a(t_stack *stk);
void		swap_b(t_stack *stk);
void		rotate_a(t_stack *stk);
void		rotate_b(t_stack *stk);
void		revrotate_a(t_stack *stk);
void		revrotate_b(t_stack *stk);
void		push_a(t_stack *stk);
void		push_b(t_stack *stk);
void		fourint_find_first(t_stack *stk);
void		fourint_find_secc(t_stack *stk);
void		fourint_main(t_stack *stk);
void		fiveint_findfirst(t_stack *stk);
void		fiveint_findseccond(t_stack *stk);
void		fiveint_main(t_stack *stk);
t_chunks	divide_chunks(int *ready4chunk, int lenght);
int			*getreadyfordivide(t_stack stk);
int			get_chunk_amount(int lenght);
void		send_chunks(t_stack *stk, t_chunks chunk);
void		send_back_from_b(t_stack *stk);
int			find_correct_position(t_stack *stk, int val);
void		rotate_until_sorted(t_stack *stk);
void		falta_memoria(t_stack *stk);
void		error(t_stack *stk);
int			position_extras(t_stack *stk, int min, int pos, int i);
int			position_extras_2(t_stack *stk, int val, int i);
void	no_argument(t_stack *stk);
#endif
