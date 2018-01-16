/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:25:00 by amichak           #+#    #+#             */
/*   Updated: 2017/12/21 13:25:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node(t_stack **head, int cont)
{
	t_stack *node;

	if (head)
	{
		if (!(node = (t_stack *)malloc(sizeof(t_stack))))
			return ;
		node->cont = cont;
		node->next = *head;
		*head = node;
	}
}

void	delete_stack(t_stack **head)
{
	if (head && *head)
	{
		if ((*head)->next)
			delete_stack(&(*head)->next);
		free(*head);
	}
}

void	sa(t_stack **head)
{
	t_stack *next;

	if (head)
		if (*head && (*head)->next)
		{
			next = (*head)->next;
			(*head)->next = next->next;
			next->next = *head;
			*head = next;
		}
}

void	sb(t_stack **head)
{
	t_stack *next;

	if (head)
		if (*head && (*head)->next)
		{
			next = (*head)->next;
			(*head)->next = next->next;
			next->next = *head;
			*head = next;
		}
}

void	ss(t_stack **heada, t_stack **headb)
{
	sa(heada);
	sb(headb);
}
