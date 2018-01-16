/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <amichak@marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 17:37:00 by amichak           #+#    #+#             */
/*   Updated: 2017/12/29 17:37:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	use_flags(t_stack **a, t_stack **b, t_ps_fl *fl)
{
	if (fl->v)
		print_stack(*a, *b);
}

static void	func_cmnds(t_stack **a, t_stack **b, char *cmd, t_ps_fl *fl)
{
	if (!ft_strcmp(cmd, "sa"))
		sa(a);
	else if (!ft_strcmp(cmd, "sb"))
		sb(b);
	else if (!ft_strcmp(cmd, "ss"))
		ss(a, b);
	else if (!ft_strcmp(cmd, "pa"))
		pa(a, b);
	else if (!ft_strcmp(cmd, "pb"))
		pb(a, b);
	else if (!ft_strcmp(cmd, "ra"))
		ra(a);
	else if (!ft_strcmp(cmd, "rb"))
		rb(b);
	else if (!ft_strcmp(cmd, "rr"))
		rr(a, b);
	else if (!ft_strcmp(cmd, "rra"))
		rra(a);
	else if (!ft_strcmp(cmd, "rrb"))
		rrb(b);
	else if (!ft_strcmp(cmd, "rrr"))
		rrr(a, b);
	else
		ft_delete_exit("Wrong command in command list", a, b, &fl);
	use_flags(a, b, fl);
}

int			main(int ac, char **av)
{
	char	*line;
	t_stack *stacka;
	t_stack *stackb;
	t_ps_fl	*fl;

	stacka = NULL;
	stackb = NULL;
	fl = handle_data(ac, av, &stacka, &stackb);
	if (ac == 1 || fl->st >= ac)
		ft_delete_exit(NULL, &stacka, &stackb, &fl);
	while (get_next_line(0, &line) > 0)
		func_cmnds(&stacka, &stackb, line, fl);
	if (is_sorted(stacka) && !stackb)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	ft_delete_exit(NULL, &stacka, &stackb, &fl);
	return (0);
}