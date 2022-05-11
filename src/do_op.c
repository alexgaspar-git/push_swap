/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:03:20 by algaspar          #+#    #+#             */
/*   Updated: 2022/05/06 15:58:32 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	do_op_three(int op, t_stack **stacka, t_stack **stackb)
{
	if (op == rra && stacka)
	{
		revrotate(stacka);
		write(1, "rra\n", 4);
	}
	else if (op == rrb && stackb)
	{
		revrotate(stackb);
		write(1, "rrb\n", 4);
	}
	else if (op == rrr && stacka && stackb)
	{
		revrotate(stacka);
		revrotate(stackb);
		write(1, "rrr\n", 4);
	}
}

static void	do_op_two(int op, t_stack **stacka, t_stack **stackb)
{
	if (op == rb && stackb)
	{
		rotate(stackb);
		write(1, "rb\n", 3);
	}
	else if (op == rr && stacka && stackb)
	{
		rotate(stacka);
		rotate(stackb);
		write(1, "rr\n", 3);
	}
	else if (op == pa && stacka && stackb)
	{
		push(stackb, stacka);
		write(1, "pa\n", 3);
	}
	else if (op == pb && stacka && stackb)
	{
		push(stacka, stackb);
		write(1, "pb\n", 3);
	}
	else
		do_op_three(op, stacka, stackb);
}

void	do_op(int op, t_stack **stacka, t_stack **stackb)
{
	if (op == sa && stacka)
	{
		swap(stacka);
		write(1, "sa\n", 3);
	}
	else if (op == sb && stackb)
	{
		swap(stackb);
		write(1, "sb\n", 3);
	}
	else if (op == ss && stacka && stackb)
	{
		swap(stacka);
		swap(stackb);
		write(1, "ss\n", 3);
	}
	else if (op == ra && stacka)
	{
		rotate(stacka);
		write(1, "ra\n", 3);
	}
	else
		do_op_two(op, stacka, stackb);
}
