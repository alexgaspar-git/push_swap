/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:30:10 by algaspar          #+#    #+#             */
/*   Updated: 2022/05/10 13:43:37 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_comp	*init_comp(t_params *params, t_stack *num)
{
	t_comp	*temp;

	temp = malloc(sizeof(t_comp));
	if (temp != NULL)
	{
		temp->rb = 0;
		temp->rbi = 0;
		temp->index = 0;
		temp->lap = 0;
		temp->size = params->size_b - 1;
		temp->num = num->i;
	}
	return (temp);
}

static void	algo_rb(t_comp *calc, t_params *params, t_stacks *ps, t_stack *ptr)
{
	while (calc->size--)
	{
		if (calc->num > ptr->i || calc->num < params->tail)
			break ;
		if (calc->lap == 0)
			calc->rb++;
		if (calc->lap == 1)
			calc->rbi++;
		if (ptr->next)
			ptr = ptr->next;
		else
		{
			calc->lap = 1;
			ptr = ps->stackb;
		}
	}
}

int	calc_rb(t_stack *num, t_params *params, t_stacks *ps)
{
	t_comp	*calc;
	t_stack	*ptr;
	int		index;
	int		head_index;

	head_index = find_head(params, ps);
	index = 0;
	ptr = ps->stackb;
	while (head_index--)
	{
		index++;
		ptr = ptr->next;
	}
	calc = init_comp(params, num);
	calc->index = index;
	algo_rb(calc, params, ps, ptr);
	free(calc);
	if (calc->lap == 0)
		return (calc->rb + calc->index);
	else
		return (calc->rbi);
}
