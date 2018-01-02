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
#include "get_next_line.h"

static void func_cmnds(t_stack **a, t_stack **b, char *cmd)
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
	{
		delete_stack(a);
		ft_delete_exit("Wrong command in command list", b);
	}
}

int 	main(int ac, char **av)
{
	char	*line;
	t_stack *stacka;
	t_stack *stackb;
	int 	fd;

	stacka = NULL;
	stackb = NULL;
	if (ac == 1)
		ft_delete_exit("Enter pls correct num line and command list", NULL);
	if (ac == 3 && !ft_strcmp(av[1], "-f"))
	{
		fd = open(av[2], O_RDONLY);
		if (fd == -1)
			ft_delete_exit("File not exist", &stacka);
		while (get_next_line(fd, av) > 0)
			datatostack(0, 1, av, &stackb);
		while(stackb)
			pa(&stacka, &stackb);
		close(fd);
	}
	else
		datatostack(ac - 1, 0, av, &stacka);
	while (get_next_line(0, &line) > 0)
		func_cmnds(&stacka, &stackb, line);
	if (is_sorted(stacka))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	delete_stack(&stacka);
	delete_stack(&stackb);
	return (0);
}