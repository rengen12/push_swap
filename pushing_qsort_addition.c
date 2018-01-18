/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_qsort_addition.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <amichak@marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 12:29:00 by amichak           #+#    #+#             */
/*   Updated: 2018/01/18 12:29:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *buble_sort_st(t_stack *st, int q)
{
	int	i;
	int y;
	t_stack *head;

	i = 0;
	head = st;
	while (i < q - 1)
	{
		y = 0;
		while (y < q - i - 1)
		{
			if (st && st->next && st->cont > st->next->cont)
				ft_swap(&st->cont, &st->next->cont);
			y++;
			if (st && st->next)
				st = st->next;
		}
		i++;
		st = head;
	}
	return (st);
}

t_stack *stcpy(t_stack *st)
{
	t_stack *newst;

	if (st)
		newst = stcpy(st->next);
	else
		return (NULL);
	add_node(&newst, st->cont);
	return (newst);
}

int		find_av_val(t_stack *st, int qel, int a)
{
	int 	i;
	t_stack *newst;
	t_stack *tmp;
	int 	res;

	i = 0;
	newst = buble_sort_st(stcpy(st), qel);
	tmp = newst;
	if (qel % 2 == 1 || a)
		while (i < qel / 2)
		{
			tmp = tmp->next;
			i++;
		}
	else
		while (i < qel / 2 - 1)
		{
			tmp = tmp->next;
			i++;
		}
	res = tmp->cont;
	delete_stack(&newst);
	return (res);
}

int		find_quant_to_move(t_stack *st, int av_val, char s_cmp)
{
	int 	res;

	res = 0;
	if (s_cmp == '<')
	{
		while (st)
		{
			if (st->cont <= av_val)
				res++;
			st = st->next;
		}
	}
	else if (s_cmp == '>')
	{
		while (st)
		{
			if (st->cont > av_val)
				res++;
			st = st->next;
		}
	}
	return (res);
}
