/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:35:00 by amichak           #+#    #+#             */
/*   Updated: 2017/12/21 13:35:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <time.h>
#include <stdio.h>

void	print_stack(t_stack *head1, t_stack *head2)
{
	int v1, v2;

	while (head1 || head2)
	{
		if (head1)
		{
			printf("%10d ", head1->cont);
			head1 = head1->next;
		}
		else
			printf("%10c ", '-');
		if (head2)
		{
			printf("%10d\n", head2->cont);
			head2 = head2->next;
		}
		else
			printf("%10c\n", '-');
	}
	printf("%10s %10s\n", "stack a", "stack b");
}

int 	main(void)
{
	t_stack *stacka;
	t_stack *stackb;
	time_t t;
	int i = 0;
	int num = 0;

	stacka = NULL;
	stackb = NULL;
	srand((unsigned) time(&t));

	while (i < 10)
	{
		num += rand() % 15;
		add_node(&stacka, num);
		i++;
	}
	//add_node(&stackb, 5);
	//add_node(&stackb, 10);

	print_stack(stacka, stackb);

	rrr(&stacka, &stackb);
	print_stack(stacka, stackb);
	/*sa(NULL);
	pb(&stacka, &stackb);
	print_stack(stacka, stackb);
	pb(&stacka, &stackb);
	print_stack(stacka, stackb);*/
	return (0);
}