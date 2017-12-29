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
#include <stdio.h>

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

void delete_stack(t_stack **head)
{
	if (head && *head)
	{
		if ((*head)->next)
			delete_stack(&(*head)->next);
		free(*head);
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

void rb(t_stack **head)
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

void rrb(t_stack **head)
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

void rrr(t_stack **heada, t_stack **headb)
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
			printf("%12d ", head1->cont);
			head1 = head1->next;
		}
		else
			printf("%12c ", '-');
		if (head2)
		{
			printf("%12d\n", head2->cont);
			head2 = head2->next;
		}
		else
			printf("%12c\n", '-');
	}
	printf("%12s %12s\n", "a", "b");
}