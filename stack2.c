/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:27:00 by amichak           #+#    #+#             */
/*   Updated: 2018/01/15 18:27:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **heada, t_stack **headb)
{
	t_stack *tmp;

	if (heada && headb)
		if (*headb)
		{
			tmp = *headb;
			*headb = (*headb)->next;
			tmp->next = *heada;
			*heada = tmp;
		}
}

void	pb(t_stack **heada, t_stack **headb)
{
	t_stack *tmp;

	if (heada && headb)
		if (*heada)
		{
			tmp = *heada;
			*heada = (*heada)->next;
			tmp->next = *headb;
			*headb = tmp;
		}
}

void	ra(t_stack **head)
{
	t_stack *thead;

	if (head)
	{
		if (!*head)
			return ;
		if (!(*head)->next)
			return ;
		thead = *head;
		while (thead->next)
			thead = thead->next;
		thead->next = *head;
		thead = thead->next;
		*head = (*head)->next;
		thead->next = NULL;
	}
}

void	rb(t_stack **head)
{
	t_stack *thead;

	if (head)
	{
		if (!*head)
			return ;
		if (!(*head)->next)
			return ;
		thead = *head;
		while (thead->next)
			thead = thead->next;
		thead->next = *head;
		thead = thead->next;
		*head = (*head)->next;
		thead->next = NULL;
	}
}

void	rr(t_stack **heada, t_stack **headb)
{
	ra(heada);
	rb(headb);
}
