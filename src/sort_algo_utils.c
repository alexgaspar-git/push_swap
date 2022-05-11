/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:03:27 by algaspar          #+#    #+#             */
/*   Updated: 2022/05/06 19:28:22 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ops_rr(int m1, int m2)
{
	int	ops;

	ops = 0;
	if (m1 >= m2)
	{
		ops += m2;
		ops += (m1 - m2);
	}
	else if (m1 < m2)
	{
		ops += m1;
		ops += (m2 - m1);
	}
	return (ops);
}

int	check_ops(t_move *move)
{
	int	ops;

	ops = 0;
	if (move->ra <= move->rra && move->rb <= move->rrb)
		ops = ops_rr(move->ra, move->rb);
	else if (move->ra >= move->rra && move->rb >= move->rrb)
		ops = ops_rr(move->rra, move->rrb);
	else if (move->ra < move->rra && move->rb > move->rrb)
	{
		ops += move->ra;
		ops += move->rrb;
	}
	else if (move->ra > move->rra && move->rb < move->rrb)
	{
		ops += move->rra;
		ops += move->rb;
	}
	return (ops);
}

t_stack	*biggest_stack(t_stack *stack)
{
	int		i;
	t_stack	*ptr;

	i = stack->i;
	ptr = stack;
	while (stack->next)
	{
		stack = stack->next;
		if (stack->i > i)
		{
			i = stack->i;
			ptr = stack;
		}
	}
	return (ptr);
}

t_stack	*smallest_stack(t_stack *stack)
{
	int		i;
	t_stack	*ptr;

	i = stack->i;
	ptr = stack;
	while (stack->next)
	{
		stack = stack->next;
		if (stack->i < i)
		{
			i = stack->i;
			ptr = stack;
		}
	}
	return (ptr);
}
