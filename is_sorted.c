/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <amichak@marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 23:41:00 by amichak           #+#    #+#             */
/*   Updated: 2018/01/17 23:41:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int 	is_sorted_rev_n(t_stack *stack, int n)
{
	if (stack)
	{
		while (stack->next && n--)
		{
			if (stack->cont < stack->next->cont)
				return (0);
			else
				stack = stack->next;
		}
	}
	return (1);
}

int 	is_sorted_n(t_stack *st, int n)
{
	if (st)
		while (st->next && n--)
		{
			if (st->cont > st->next->cont)
				return (0);
			else
				st = st->next;
		}
	return (1);
}
