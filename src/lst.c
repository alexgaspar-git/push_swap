/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:06:24 by algaspar          #+#    #+#             */
/*   Updated: 2022/05/06 15:48:45 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	lst_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (stack && new)
	{
		if (!*stack)
		{
			*stack = new;
		}
		else
		{
			last = last_stack(*stack);
			last->next = new;
		}
		new->next = NULL;
	}
}

void	lst_add_front(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	if (*stack)
	{
		new->next = *stack;
		*stack = new;
	}
	else
		*stack = new;
}

t_stack	*last_stack(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*bflast_stack(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}

t_stack	*new_list(int i)
{
	t_stack	*list;

	list = malloc(sizeof(t_stack));
	if (list != NULL)
	{
		list->i = i;
		list->next = NULL;
	}
	return (list);
}
