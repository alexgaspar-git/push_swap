/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:45:59 by algaspar          #+#    #+#             */
/*   Updated: 2022/05/06 19:28:05 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	prev;

	prev = 0;
	if (stack)
	{
		while (stack && stack->next)
		{
			prev = stack->i;
			stack = stack->next;
			if (stack->i < prev)
				return (0);
		}
		return (1);
	}
	return (0);
}

int	is_revsorted(t_stack *stack)
{
	int	prev;

	prev = 0;
	if (stack)
	{
		while (stack && stack->next)
		{
			prev = stack->i;
			stack = stack->next;
			if (stack->i > prev)
				return (0);
		}
		return (1);
	}
	return (0);
}

int	lst_count(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	clean_list(t_stack *list)
{
	t_stack	*ptr;

	while (list)
	{
		ptr = list->next;
		free(list);
		list = ptr;
	}
}

int	find_head(t_params *params, t_stacks *ps)
{
	int		headpos;
	t_stack	*ptr;

	ptr = ps->stackb;
	headpos = 0;
	while (ptr && ptr->i != params->head)
	{
		headpos++;
		ptr = ptr->next;
	}
	return (headpos);
}
