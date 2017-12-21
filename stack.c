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

#include "stack.h"

void add_node(t_stack **head, int cont)
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

void sa(t_stack **head)
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

void sb(t_stack **head)
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

void ss(t_stack **heada, t_stack **headb)
{
	sa(heada);
	sb(headb);
}

void pa(t_stack **heada, t_stack **headb)
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

void pb(t_stack **heada, t_stack **headb)
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

void ra(t_stack **head)
{
	t_stack *thead;

	if (head)
	{
		thead = *head;
		while (thead->next)
			thead = thead->next;
		thead->next = *head;
		thead = thead->next;
		*head = (*head)->next;
		thead->next = NULL;
	}
}

void rb(t_stack **head)
{
	t_stack *thead;

	if (head)
	{
		thead = *head;
		while (thead->next)
			thead = thead->next;
		thead->next = *head;
		thead = thead->next;
		*head = (*head)->next;
		thead->next = NULL;
	}
}

void rr(t_stack **heada, t_stack **headb)
{
	ra(heada);
	rb(headb);
}

void rra(t_stack **head)
{
	t_stack *thead;

	if (head)
	{
		
	}
}

