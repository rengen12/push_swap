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

int 	is_sorted(t_stack *stack)
{
	if (stack)
	{
		while (stack->next)
			if (stack->cont > stack->next->cont)
				return (0);
			else
				stack = stack->next;
	}
	return (1);
}

/*void	margesort(t_stack *sta, t_stack *stb, int qe)
{

}
margesort(&stacka, &stackb, ac - 1);*/

char*	bublesort(t_stack *sta, t_stack *stb)
{
	t_stack *heada;

	if (!sta)
		return (NULL);
	heada = sta;
	while (heada)
	{
		while (sta->next)
			if (sta->cont > sta->next->cont)
				break;
			else
				sta = sta->next;
		while (heada != sta && sta->next)
			pb(&sta, &stb);
		if (sta->cont > sta->next->cont)
			sa(&heada);
		sta = heada;
		print_stack(sta, stb);
	}
}

int 	main(int ac, char **av)
{
	t_stack *stacka;
	t_stack *stackb;
	int 	fd;
	char 	*cmnds;

	stacka = NULL;
	stackb = NULL;
	printf("ac = %d\n", ac);

	if (ac == 3 && !ft_strcmp(av[1], "-f"))
	{
		fd = open(av[2], O_RDONLY);
		while (get_next_line(fd, av) > 0)
			datatostack(0, 1, av, &stacka);
		close(fd);
	}
	else
		datatostack(ac - 1, 0, av, &stacka);
	print_stack(stacka, stackb);
	if (is_sorted(stacka))
		ft_delete_exit("Stack is sorted", &stacka);
	else
		cmnds = bublesort(stacka, stackb);
	//ft_putstr(cmnds);
	print_stack(stacka, stackb);


	delete_stack(&stacka);
	delete_stack(&stackb);
	return (0);
}