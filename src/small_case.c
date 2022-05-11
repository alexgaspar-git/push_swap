/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_case.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:51:15 by algaspar          #+#    #+#             */
/*   Updated: 2022/04/20 21:42:36 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_case(t_stacks *ps, int x)
{
	if (is_bigger(ps->stacka, last_stack(ps->stacka)->i) == x)
		do_op(rra, &ps->stacka, &ps->stackb);
	else if (is_bigger(ps->stacka, bflast_stack(ps->stacka)->i) == x)
	{
		do_op(rra, &ps->stacka, &ps->stackb);
		do_op(rra, &ps->stacka, &ps->stackb);
	}
	else
		while (is_bigger(ps->stacka, ps->stacka->i) != x)
			do_op(ra, &ps->stacka, &ps->stackb);
}

void	case_three(t_stacks *ps)
{
	int	a;
	int	b;
	int	c;

	a = ps->stacka->i;
	b = ps->stacka->next->i;
	c = ps->stacka->next->next->i;
	if (a > b && a < c && b < c)
		do_op(sa, &ps->stacka, &ps->stackb);
	else if (a > b && a > c && b > c)
	{
		do_op(sa, &ps->stacka, &ps->stackb);
		do_op(rra, &ps->stacka, &ps->stackb);
	}
	else if (a > b && a > c && b < c)
		do_op(ra, &ps->stacka, &ps->stackb);
	else if (a < b && a < c && b > c)
	{
		do_op(sa, &ps->stacka, &ps->stackb);
		do_op(ra, &ps->stacka, &ps->stackb);
	}
	else if (a < b && a > c && b > c)
		do_op(rra, &ps->stacka, &ps->stackb);
}

void	case_four(t_stacks *ps)
{
	push_case(ps, 3);
	do_op(pb, &ps->stacka, &ps->stackb);
	case_three(ps);
	do_op(pa, &ps->stacka, &ps->stackb);
}

void	case_five(t_stacks *ps)
{
	push_case(ps, 4);
	do_op(pb, &ps->stacka, &ps->stackb);
	push_case(ps, 3);
	do_op(pb, &ps->stacka, &ps->stackb);
	case_three(ps);
	do_op(pa, &ps->stacka, &ps->stackb);
	do_op(pa, &ps->stacka, &ps->stackb);
}
