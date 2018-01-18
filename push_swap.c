/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <amichak@marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 20:40:00 by amichak           #+#    #+#             */
/*   Updated: 2017/12/29 20:40:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static float	sort_factor(t_stack *st, int qel)
{
	float	res;

	res = 1;
	while (st && st->next)
	{
		if (st->cont > st->next->cont)
			res++;
		st = st->next;
	}
	return (res / qel * 100);
}

int				main(int ac, char **av)
{
	t_stack *stacka;
	t_stack *stackb;
	char 	*cmds;
	t_ps_fl	*fl;

	stacka = NULL;
	stackb = NULL;
	fl = handle_data(ac, av, &stacka, &stackb);
	if (ac == 1 || fl->st >= ac)
		ft_delete_exit(NULL, &stacka, &stackb, &fl);
	cmds = ft_strnew(1);
	if (is_sorted(stacka))
		ft_delete_exit("Stack is sorted", &stacka, &stackb, &fl);
	else
		if (sort_factor(stacka, lstlen(stacka)) >= 70.0)
			cmds = selection_sort(&stacka, &stackb, cmds);
		else
			myqsort_stack_a(&stacka, &stackb, lstlen(stacka), &cmds);
	cmds = opt_cmds(cmds);
	cmds = opt_cmds(cmds);
	cmds = opt_cmds(cmds);
	ft_putstr(cmds);
	free(cmds);
	ft_delete_exit(NULL, &stacka, &stackb, &fl);
	return (0);
}
