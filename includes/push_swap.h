/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:55:17 by algaspar          #+#    #+#             */
/*   Updated: 2022/05/10 14:28:32 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct move {
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	val;
}	t_move;

typedef struct params
{
	int	index;
	int	size_a;
	int	size_b;
	int	head;
	int	tail;
	int	head_index;
}	t_params;

typedef struct stack {
	int					i;
	struct stack		*next;
}	t_stack;

typedef struct stacks {
	t_stack	*stacka;
	t_stack	*stackb;
}	t_stacks;

typedef struct comp {
	int	rb;
	int	rbi;
	int	lap;
	int	size;
	int	index;
	int	num;
}	t_comp;

enum
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
};

void		addint(t_stack **list, int i);
void		case_five(t_stacks *ps);
void		case_four(t_stacks *ps);
void		case_three(t_stacks *ps);
void		checkstax(t_stack *stacka, t_stack *stackb);
void		clean_list(t_stack *list);
void		do_op(int op, t_stack **stacka, t_stack **stackb);
void		exec_ops(t_move *best, t_stacks *ps, t_params **params);
void		free_stacks(t_move *best,
				t_move *tmp, t_params *params);
void		lst_add_back(t_stack **stack, t_stack *new);
void		lst_add_front(t_stack **stack, t_stack *new);
void		push(t_stack **stacka, t_stack **stackb);
void		push_case(t_stacks *ps, int x);
void		revrotate(t_stack **stack);
void		rotate(t_stack **stack);
void		set_tmp(t_params **params, t_stack *ptr,
				t_move **tmp, t_stacks *ps);
void		set_val(t_move *src, t_move **dest);
void		sorting_algo(t_stacks *ps, t_params *params,
				t_move *best, t_move *tmp);
void		swap(t_stack **stack);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strjoin_space(int argc, char **argv);
int			calc_rb(t_stack *num, t_params *params, t_stacks *ps);
int			check_args(char **cutargs, t_stack **stack);
int			check_double(long i, t_stack *stack);
int			check_int(char **cutargs);
int			check_ops(t_move *move);
int			find_head(t_params *params, t_stacks *ps);
int			ft_isdigit(int c);
int			is_bigger(t_stack *stack, int num);
int			is_sorted(t_stack *stack);
int			is_revsorted(t_stack *stack);
int			lst_count(t_stack *stack);
long		ft_atoi(char *str);
size_t		ft_strlen(const char *str);
t_comp		*init_comp(t_params *params, t_stack *num);
t_move		*init_move(void);
t_params	*init_params(int size_a, int size_b, t_stacks *ps);
t_stack		*bflast_stack(t_stack *stack);
t_stack		*biggest_stack(t_stack *stack);
t_stack		*last_stack(t_stack *stack);
t_stack		*new_list(int i);
t_stack		*smallest_stack(t_stack *stack);

#endif