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
#include <stdio.h>
#include "get_next_line.h"

/*void	margesort(t_stack *sta, t_stack *stb, int qe)
{

}
margesort(&stacka, &stackb, ac - 1);*/

char*	bublesort(t_stack **sta, t_stack **stb, char *cmds)
{
	if (!sta || !*sta)
		return (NULL);
	while ((*sta)->next)
	{
		if ((*sta)->cont < (*sta)->next->cont)
		{
			pb(sta, stb);
			cmds = ft_strjoin(cmds, "pb\n");
		}
		else
		{
			sa(sta);
			cmds = ft_strjoin(cmds, "sa\n");
		}
	}
	while ((*stb)->next)
	{
		if ((*stb)->cont > (*stb)->next->cont)
		{
			pa(sta, stb);
			cmds = ft_strjoin(cmds, "pa\n");
		}
		else
		{
			sb(stb);
			cmds = ft_strjoin(cmds, "sb\n");
		}
	}
	if (*stb)
	{
		pa(sta, stb);
		cmds = ft_strjoin(cmds, "pa\n");
	}
	return (cmds);
}

int 	main(int ac, char **av)
{
	t_stack *stacka;
	t_stack *stackb;
	int 	fd;
	char 	*cmds;

	stacka = NULL;
	stackb = NULL;
	cmds = "";
	//printf("ac = %d\n", ac);

	if (ac == 3 && !ft_strcmp(av[1], "-f"))
	{
		fd = open(av[2], O_RDONLY);
		while (get_next_line(fd, av) > 0)
			datatostack(0, 1, av, &stacka);
		close(fd);
	}
	else
		datatostack(ac - 1, 0, av, &stacka);
	//print_stack(stacka, stackb);
	if (is_sorted(stacka))
		ft_delete_exit("Stack is sorted", &stacka);
	else
		while (!is_sorted(stacka))
		{
			cmds = bublesort(&stacka, &stackb, cmds);
		}
	ft_putstr(cmds);
	//print_stack(stacka, stackb);


	delete_stack(&stacka);
	delete_stack(&stackb);
	return (0);
}