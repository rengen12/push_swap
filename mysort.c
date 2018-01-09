/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <amichak@marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 13:03:00 by amichak           #+#    #+#             */
/*   Updated: 2018/01/01 13:03:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		lstlen(t_stack *stack)
{
	int 	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int 	find_min_val_n(t_stack *st, int q)
{
	int 	min;

	if (!st)
		return (0);
	min = st->cont;
	while (st && q--)
	{
		if (st->cont <  min)
			min = st->cont;
		st = st->next;
	}
	return (min);
}

int 	find_max_val_n(t_stack *st, int q)
{
	int 	max;

	if (!st)
		return (0);
	max = st->cont;
	while (st && q--)
	{
		if (st->cont >  max)
			max = st->cont;
		st = st->next;
	}
	return (max);
}

void	swap_st_cont(int *a, int *b)
{
	int 	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

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
				swap_st_cont(&st->cont, &st->next->cont);
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

int		find_av_val(t_stack *st, int qel)
{
	int 	i;
	t_stack *newst;
	t_stack *tmp;
	int 	res;

	i = 0;
	newst = buble_sort_st(stcpy(st), qel);
	tmp = newst;
	while (i < qel / 2)
	{
		tmp = tmp->next;
		i++;
	}
	res = tmp->cont;
	delete_stack(&newst);
	return (res);
}

int		push_half_to_a(t_stack **sta, t_stack **stb, char **cmds, int qel)
{
	int 	av_val;
	int 	to_move;
	int 	rx;
	int 	needrotate;

	to_move = 0;
	rx = 0;
	if (!*stb)
		return (0);
	needrotate = (lstlen(*stb) != qel) ? 1 : 0;
	av_val = find_av_val(*stb, qel);
	while (qel--)
		if ((*stb)->cont > av_val)
		{
			/*good*/
			/*if ((*stb)->next && (*stb)->cont < (*stb)->next->cont)
			{
				sb(stb);
				*cmds = ft_strjoin(*cmds, "sb\n");
			}*/
			pa(sta, stb);
			to_move++;
			*cmds = ft_strjoin(*cmds, "pa\n");
			/*good*/
			/*if (*sta && (*sta)->next && (*sta)->cont > (*sta)->next->cont)
			{
				sa(sta);
				*cmds = ft_strjoin(*cmds, "sa\n");
			}*/
		}
		else
		{
			rx++;
			rb(stb);
			if (*stb)
				*cmds = ft_strjoin(*cmds, "rb\n");
		}
	if (needrotate)
		while (rx--)
		{
			rrb(stb);
			*cmds = ft_strjoin(*cmds, "rrb\n");
		}
	return (to_move);
}

int		push_half_to_b(t_stack **sta, t_stack **stb, char **cmds, int qel)
{
	int 	av_val;
	int 	to_move;
	int 	rx;
	int 	needrotate;

	rx = 0;
	to_move = 0;
	needrotate = (lstlen(*sta) != qel) ? 1 : 0;
	if (!*sta)
		return (0);
	av_val = find_av_val(*sta, qel);
	while (qel--)
		if ((*sta)->cont < av_val)
		{
			/*good*/
			/*if ((*sta)->next && (*sta)->cont > (*sta)->next->cont)
			{
				sa(sta);
				*cmds = ft_strjoin(*cmds, "sa\n");
			}*/
			pb(sta, stb);
			to_move++;
			*cmds = ft_strjoin(*cmds, "pb\n");
			/*bad idea
			 * if (*stb && (*stb)->next && (*stb)->cont < (*stb)->next->cont)
			{
				sb(stb);
				*cmds = ft_strjoin(*cmds, "sb\n");
			}*/
		}
		else
		{
			ra(sta);
			rx++;
			if (*sta)
				*cmds = ft_strjoin(*cmds, "ra\n");
		}
	if (needrotate)
		while (rx--)
		{
			rra(sta);
			*cmds = ft_strjoin(*cmds, "rra\n");
		}
	return (to_move);
}
