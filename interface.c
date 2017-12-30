/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <amichak@marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 20:44:00 by amichak           #+#    #+#             */
/*   Updated: 2017/12/29 20:44:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *message)
{
	ft_putendl_fd(message, 2);
	exit(0);
}

void	ft_delete_exit(char *message, t_stack **stack)
{
	delete_stack(stack);
	ft_error(message);
}

int		check_duplicates(int num, t_stack *stack)
{
	while (stack)
		if (stack->cont == num)
			return (1);
		else
			stack = stack->next;
	return (0);
}

void	datatostack(int ac, int file, char **av, t_stack **stack)
{
	ssize_t	num;

	while (ac || file)
	{
		if ((!ft_isdigit(*av[ac]) && *av[ac] != '-') || \
				(!ft_isdigit(*(av[ac] + 1)) && *av[ac] == '-'))
			ft_delete_exit("Error!\nWrong argument", stack);
		num = ft_atoi(av[ac--]);
		if (num > 2147483647 || num < -2147483648)
			ft_delete_exit("Error!\nOut of int's range", stack);
		if (check_duplicates((int)num, *stack))
			ft_delete_exit("Error!\nDuplicate found", stack);
		add_node(stack, (int)num);
		if (file)
			break ;
	}
}

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
