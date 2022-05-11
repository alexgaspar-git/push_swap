/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:12:52 by algaspar          #+#    #+#             */
/*   Updated: 2022/04/20 21:49:31 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	addint(t_stack **list, int i)
{
	t_stack	*new;
	t_stack	*ptr;

	new = new_list(i);
	if (!*list)
	{
		*list = new;
		return ;
	}
	ptr = *list;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new;
}

char	*ft_strjoin_space(int argc, char **argv)
{
	int		i;
	int		j;
	char	*allargs;

	i = 1;
	allargs = malloc(sizeof(char) * 1);
	allargs[0] = '\0';
	while (argv[i])
	{
		allargs = ft_strjoin(allargs, argv[i]);
		if (!allargs)
			return (NULL);
		j = 0;
		while (allargs[j] != '\0')
			j++;
		if (i != (argc - 1))
			allargs = ft_strjoin(allargs, " ");
		i++;
	}
	return (allargs);
}

int	check_int(char **cutargs)
{
	int	i;
	int	j;

	i = 0;
	while (cutargs[i])
	{
		j = 0;
		if (cutargs[i][j] == '-' && cutargs[i][j + 1] != '\0')
			j++;
		while (cutargs[i][j])
		{
			if (!ft_isdigit(cutargs[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_double(long i, t_stack *stack)
{
	t_stack	*ptr;

	ptr = stack;
	while (ptr)
	{
		if (ptr->i == i)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int	check_args(char **cutargs, t_stack **stack)
{
	long	tmp;
	int		i;

	i = 0;
	if (!check_int(cutargs))
		return (0);
	while (cutargs[i])
	{
		tmp = ft_atoi(cutargs[i]);
		if ((tmp <= 2147483647 && tmp >= -2147483648)
			&& check_double(tmp, (*stack)) == 1)
			addint(stack, (int)tmp);
		else
			return (0);
		i++;
	}
	return (1);
}
