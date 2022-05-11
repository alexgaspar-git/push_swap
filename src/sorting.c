/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:24:06 by algaspar          #+#    #+#             */
/*   Updated: 2022/04/20 21:45:12 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack)
{
	int	tmp;

	tmp = 0;
	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->i;
		(*stack)->i = (*stack)->next->i;
		(*stack)->next->i = tmp;
	}
}

void	push(t_stack **stacka, t_stack **stackb)
{
	t_stack	*head;

	if (stacka && *stacka && stackb)
	{
		head = (*stacka)->next;
		(*stacka)->next = NULL;
		lst_add_front(stackb, *stacka);
		*stacka = head;
	}
}

void	rotate(t_stack **stack)
{
	t_stack	*head;

	if (stack && (*stack)->next)
	{
		head = (*stack)->next;
		lst_add_back(stack, *stack);
		*stack = head;
	}
}

void	revrotate(t_stack **stack)
{
	t_stack	*last;

	if (*stack && (*stack)->next)
	{
		last = bflast_stack(*stack);
		lst_add_front(stack, last_stack(*stack));
		last->next = NULL;
	}
}
