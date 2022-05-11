/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:12:17 by algaspar          #+#    #+#             */
/*   Updated: 2022/05/10 14:19:55 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_rr(int bra, int brb, t_stacks *ps)
{
	int	z;

	z = 0;
	if (bra >= brb)
	{
		z = bra - brb;
		while (brb--)
			do_op(rr, &ps->stacka, &ps->stackb);
		while (z--)
			do_op(ra, &ps->stacka, &ps->stackb);
	}
	else if (bra < brb)
	{
		z = brb - bra;
		while (bra--)
			do_op(rr, &ps->stacka, &ps->stackb);
		while (z--)
			do_op(rb, &ps->stacka, &ps->stackb);
	}
}

void	do_rrr(int brra, int brrb, t_stacks *ps)
{
	int	z;

	z = 0;
	if (brra >= brrb)
	{
		z = brra - brrb;
		while (brrb--)
			do_op(rrr, &ps->stacka, &ps->stackb);
		while (z--)
			do_op(rra, &ps->stacka, &ps->stackb);
	}
	else if (brra < brrb)
	{
		z = brrb - brra;
		while (brra--)
			do_op(rrr, &ps->stacka, &ps->stackb);
		while (z--)
			do_op(rrb, &ps->stacka, &ps->stackb);
	}
}

void	exec_ops(t_move *best, t_stacks *ps, t_params **params)
{
	if (best->ra <= best->rra && best->rb <= best->rrb)
		do_rr(best->ra, best->rb, ps);
	else if (best->ra >= best->rra && best->rb >= best->rrb)
		do_rrr(best->rra, best->rrb, ps);
	else if (best->ra < best->rra && best->rb > best->rrb)
	{
		while (best->ra--)
			do_op(ra, &ps->stacka, &ps->stackb);
		while (best->rrb--)
			do_op(rrb, &ps->stacka, &ps->stackb);
	}
	else if (best->ra > best->rra && best->rb < best->rrb)
	{
		while (best->rb--)
			do_op(rb, &ps->stacka, &ps->stackb);
		while (best->rra--)
			do_op(rra, &ps->stacka, &ps->stackb);
	}
	if (best->val > (*params)->head)
		(*params)->head = best->val;
	if (best->val < (*params)->tail)
		(*params)->tail = best->val;
	do_op(pb, &ps->stacka, &ps->stackb);
}

void	push_stack(t_stacks *ps, t_params *params)
{
	int	head;
	int	revhead;

	head = find_head(params, ps);
	revhead = params->size_b - head;
	if (head < params->size_b / 2)
		while (head--)
			do_op(rb, &ps->stacka, &ps->stackb);
	else
		while (revhead--)
			do_op(rrb, &ps->stacka, &ps->stackb);
	while (ps->stackb)
		do_op(pa, &ps->stacka, &ps->stackb);
}

void	sorting_algo(t_stacks *ps, t_params *params, t_move *best, t_move *tmp)
{
	t_stack		*ptr;

	do_op(pb, &ps->stacka, &ps->stackb);
	ptr = ps->stacka;
	params->size_a--;
	params->size_b++;
	while (params->size_a--)
	{
		set_tmp(&params, ptr, &tmp, ps);
		set_val(tmp, &best);
		while (ptr)
		{
			if (ptr != ps->stacka)
				set_tmp(&params, ptr, &tmp, ps);
			if (check_ops(tmp) < check_ops(best))
				set_val(tmp, &best);
			ptr = ptr->next;
			params->index++;
		}
		exec_ops(best, ps, &params);
		ptr = ps->stacka;
		params->index = 0;
		params->size_b++;
	}
	push_stack(ps, params);
}
