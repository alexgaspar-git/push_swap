/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:04:30 by algaspar          #+#    #+#             */
/*   Updated: 2022/05/10 14:19:36 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_params	*init_params(int size_a, int size_b, t_stacks *ps)
{
	t_params	*params;

	params = malloc(sizeof(t_params));
	if (params != NULL)
	{
		params->index = 0;
		params->size_a = size_a;
		params->size_b = size_b;
		params->head = ps->stacka->i;
		params->tail = ps->stacka->i;
		params->head_index = 0;
	}
	return (params);
}

t_move	*init_move(void)
{
	t_move	*move;

	move = malloc(sizeof(t_move));
	if (move != NULL)
	{
		move->ra = 0;
		move->rb = 0;
		move->rra = 0;
		move->rrb = 0;
		move->val = 0;
	}
	return (move);
}

void	set_val(t_move *src, t_move **dest)
{
	(*dest)->ra = src->ra;
	(*dest)->rb = src->rb;
	(*dest)->rra = src->rra;
	(*dest)->rrb = src->rrb;
	(*dest)->val = src->val;
}

void	set_tmp(t_params **params, t_stack *ptr, t_move **tmp, t_stacks *ps)
{
	(*tmp)->ra = (*params)->index;
	(*tmp)->rra = (*params)->size_a - (*params)->index + 1;
	(*tmp)->rb = calc_rb(ptr, *params, ps);
	if ((*tmp)->rb == 0)
		(*tmp)->rrb = 0;
	else
		(*tmp)->rrb = (*params)->size_b - (*tmp)->rb;
	(*tmp)->val = ptr->i;
}
