/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_qsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengen <rengen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 13:03:00 by amichak           #+#    #+#             */
/*   Updated: 2018/01/18 00:37:36 by rengen           ###   ########.fr       */
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

int		push_half_to_a(t_stack **sta, t_stack **stb, char **cmds, int qel)
{
	int 	av_val;
	int 	to_move;
	int 	rx;
	int 	needrotate;
	int		i;

	i = 0;
	rx = 0;
	if (!*stb)
		return (0);
	needrotate = (lstlen(*stb) != qel) ? 1 : 0;
	av_val = find_av_val(*stb, qel, 0);
	to_move = find_quant_to_move(*stb, av_val, '>');
	while (i < to_move)
		if ((*stb)->cont > av_val)
		{
			pa(sta, stb);
			i++;
			*cmds = ft_strjoin_fr_frst(*cmds, "pa\n");
		}
		else
		{
			rx++;
			rb(stb);
			if (*stb)
				*cmds = ft_strjoin_fr_frst(*cmds, "rb\n");
		}
	if (needrotate)
		while (rx--)
		{
			rrb(stb);
			*cmds = ft_strjoin_fr_frst(*cmds, "rrb\n");
		}
	return (to_move);
}

int		push_half_to_b(t_stack **sta, t_stack **stb, char **cmds, int qel)
{
	int 	av_val;
	int 	to_move;
	int 	rx;
	int 	needrotate;
	int 	i;

	rx = 0;
	i = 0;
	needrotate = (lstlen(*sta) != qel) ? 1 : 0;
	if (!*sta)
		return (0);
	av_val = find_av_val(*sta, qel, 1);
	to_move = find_quant_to_move(*sta, av_val, '<');
	while (i < to_move)
		if ((*sta)->cont <= av_val)
		{
			pb(sta, stb);
			i++;
			*cmds = ft_strjoin_fr_frst(*cmds, "pb\n");
		}
		else
		{
			ra(sta);
			rx++;
			if (*sta)
				*cmds = ft_strjoin_fr_frst(*cmds, "ra\n");
		}
	if (needrotate)
		while (rx--)
		{
			rra(sta);
			*cmds = ft_strjoin_fr_frst(*cmds, "rra\n");
		}
	return (to_move);
}
