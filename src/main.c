/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:38:05 by algaspar          #+#    #+#             */
/*   Updated: 2022/05/10 16:45:59 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stacks(t_move *best, t_move *tmp, t_params *params)
{
	free(params);
	free(tmp);
	free(best);
}

static void	free_lists(char **cutargs, t_stack **list, t_stack **list2)
{
	int	i;

	i = 0;
	while (cutargs[i])
	{
		free(cutargs[i]);
		i++;
	}
	free(cutargs);
	clean_list(*list);
	(*list) = NULL;
	clean_list(*list2);
	(*list2) = NULL;
}

static void	sort_stack(t_stacks *ps)
{
	t_params	*params;
	t_move		*tmp;
	t_move		*best;
	int			i;

	params = init_params(lst_count(ps->stacka), lst_count(ps->stackb), ps);
	tmp = init_move();
	best = init_move();
	i = lst_count(ps->stacka);
	if (i == 2)
		do_op(sa, &ps->stacka, &ps->stackb);
	else if (i == 3)
		case_three(ps);
	else if (i == 4)
		case_four(ps);
	else if (i == 5)
		case_five(ps);
	else
		sorting_algo(ps, params, best, tmp);
	free_stacks(best, tmp, params);
}

int	main(int argc, char **argv)
{
	t_stacks	ps;
	char		*allargs;
	char		**cutargs;

	if (argc < 2)
		return (0);
	ps.stacka = NULL;
	ps.stackb = NULL;
	allargs = ft_strjoin_space(argc, argv);
	cutargs = ft_split(allargs, ' ');
	free(allargs);
	if (!check_args(cutargs, &ps.stacka))
	{
		free_lists(cutargs, &ps.stacka, &ps.stackb);
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (!is_sorted(ps.stacka))
		sort_stack(&ps);
	free_lists(cutargs, &ps.stacka, &ps.stackb);
	return (0);
}
