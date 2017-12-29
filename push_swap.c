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
*/
int 	main(int ac, char **av)
{
	t_stack *stacka;
	t_stack *stackb;
	int fd;
	//time_t t;
	/*int i = 0;
	int num = 0;*/

	stacka = NULL;
	stackb = NULL;
	printf("ac = %d\n", ac);
	//srand((unsigned) time(&t));

	/*while (i < 10)
	{
		num += rand() % 15;
		add_node(&stacka, num);
		i++;
	}*/

	//add_node(&stackb, 5);
	//add_node(&stackb, 10);
	if (ac == 3)
		if (!ft_strcmp(av[1], "-f"))
		{
			fd = open(av[2], O_RDONLY);
			get_next_line(fd, av);
			ac = 2;
		}
	datatostack(ac - 1, av, &stacka);
	print_stack(stacka, stackb);
	/*if (is_sorted(stacka))
		ft_delete_exit("Stack is sorted", &stacka);
	else
		margesort(&stacka, &stackb, ac - 1);*/



	delete_stack(&stacka);
	delete_stack(&stackb);
	return (0);
}