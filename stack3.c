/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:28:00 by amichak           #+#    #+#             */
/*   Updated: 2018/01/15 18:28:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_printf/ft_printf.h"

void rra(t_stack **head)
{
	t_stack *thead;

	if (head)
	{
		if (!*head)
			return ;
		if (!(*head)->next)
			return ;
		thead = *head;
		while (thead->next->next)
			thead = thead->next;
		thead->next->next = *head;
		*head = thead->next;
		thead->next = NULL;
	}
}

void	rrb(t_stack **head)
{
	t_stack *thead;

	if (head)
	{
		if (!*head)
			return ;
		if (!(*head)->next)
			return ;
		thead = *head;
		while (thead->next->next)
			thead = thead->next;
		thead->next->next = *head;
		*head = thead->next;
		thead->next = NULL;
	}
}

void	rrr(t_stack **heada, t_stack **headb)
{
	rra(heada);
	rrb(headb);
}

void	print_stack(t_stack *head1, t_stack *head2)
{
	while (head1 || head2)
	{
		if (head1)
		{
			ft_printf("%12d ", head1->cont);
			head1 = head1->next;
		}
		else
			ft_printf("%12c ", '-');
		if (head2)
		{
			ft_printf("%12d\n", head2->cont);
			head2 = head2->next;
		}
		else
			ft_printf("%12c\n", '-');
	}
	ft_printf("________________________\n%12s %12s\n", "a", "b");
}
