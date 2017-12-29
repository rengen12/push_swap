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

#include "libft/libft.h"
#include "stack.h"
//#include <time.h>
#include <stdio.h>

void	print_stack(t_stack *head1, t_stack *head2)
{
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
	printf("%10s %10s\n", "a", "b");
}

void ft_error(char *message)
{
	ft_putendl_fd(message, 2);
	exit(0);
}

void ft_delete_exit(char *message, t_stack **stack)
{
	delete_stack(stack);
	ft_error(message);
}

int	check_duplicates(int num, t_stack *stack)
{
	while (stack)
		if (stack->cont == num)
			return (1);
		else
			stack = stack->next;
	return (0);
}

void datatostack(int ac, char **av, t_stack **stack)
{
	ssize_t	num;

	while (ac)
	{
		if (!ft_isdigit(*av[ac]))
			ft_delete_exit("Error!", stack);
		num = ft_atoi(av[ac--]);
		if (num > 2147483647 || num < -2147483648)
			ft_delete_exit("Error!", stack);
		if (check_duplicates((int)num, *stack))
			ft_delete_exit("Error!\nDuplicate found", stack);
		add_node(stack, (int)num);
	}
}

int 	main(int ac, char **av)
{
	t_stack *stacka;
	t_stack *stackb;
	//time_t t;
	/*int i = 0;
	int num = 0;*/

	stacka = NULL;
	stackb = NULL;
	//srand((unsigned) time(&t));

	/*while (i < 10)
	{
		num += rand() % 15;
		add_node(&stacka, num);
		i++;
	}*/

	//add_node(&stackb, 5);
	//add_node(&stackb, 10);

	print_stack(stacka, stackb);
	datatostack(ac - 1, av, &stacka);
	//sb(&stackb);
	//rrr(&stacka, &stackb);
	print_stack(stacka, stackb);
	/*sa(NULL);
	pb(&stacka, &stackb);
	print_stack(stacka, stackb);
	pb(&stacka, &stackb);
	print_stack(stacka, stackb);*/




	delete_stack(&stacka);
	delete_stack(&stackb);
	return (0);
}