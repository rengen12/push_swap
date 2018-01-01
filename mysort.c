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

void	rewrite_mas(t_stack **mas, t_stack *last)
{
	mas[2] = mas[1];
	mas[1] = mas[0];
	mas[0] = last;
}

void	prep_vars(t_stack **mas1, t_stack **mas2, int *i)
{
	*i = 0;
	mas1[0] = NULL;
	mas2[0] = NULL;
	mas1[1] = NULL;
	mas2[1] = NULL;
	mas1[2] = NULL;
	mas2[2] = NULL;
}

int 	retmin(t_stack **min, t_stack **mas, int val)
{
	*min = *mas;
	return (val);
}

int 	find_nearest(t_stack **p_down, t_stack **p_up, t_stack **min, int q)
{
	int 	i;

	i = 0;
	while (i < 2)
		if ((p_down[i] && p_down[i]->cont < (*min)->cont) || \
				(p_up[i] && p_up[i]->cont < (*min)->cont))
			break ;
		else
			i++;
	if ((p_down[i] && p_down[i]->cont < (*min)->cont) && \
			(p_up[i] && p_up[i]->cont < (*min)->cont))
	{
		if (p_down[i]->cont < p_up[i]->cont)
			return (retmin(min, &p_down[i], q));
		else
			return (retmin(min, &p_up[i], (q * -1)));
	}
	if ((p_down[i] && p_down[i]->cont < (*min)->cont))
		return (retmin(min, &p_down[i], q));
	return (retmin(min, &p_up[i], (q * -1)));
}

int		find_min_arr(t_stack **min, t_stack **p_down, t_stack **p_up)
{
	int 	que1;
	int 	que2;
	int 	i;

	i = 0;
	que1 = 0;
	que2 = 0;
	while (i < 3)
	{
		if (p_down[i] && p_down[i]->cont < (*min)->cont)
			que1++;
		if (p_up[i] && p_up[i]->cont < (*min)->cont)
			que2++;
		i++;
	}
	if (que1 == que2 && que1)
		return (find_nearest(p_down, p_up, min, que1));
	else if (que1 > que2)
		return (retmin(min, p_down, que1));
	else if (que1 < que2)
		return (retmin(min, p_up, (que2 * -1)));
	return (0);
}

int		create_cmp_arr(t_stack *st, t_stack **min)
{
	t_stack	*p_down[3];
	t_stack	*p_up[3];
	int 	i;

	*min = st;
	prep_vars(p_down, p_up, &i);
	while (i < 3 && st->next)
	{
		st = st->next;
		p_down[i++] = st;
	}
	while (st->next)
	{
		st = st->next;
		rewrite_mas(p_up, st);
	}
	return (find_min_arr(min, p_down, p_up));
}

void	rotate_b(t_stack **stb, int rx, int rrx)
{
	if (rrx < rx)
		while (rrx-- > 0)
			rrb(stb);
	else
		while (rx-- > 0)
			rb(stb);
}

void	paste_in_tail(t_stack **sta, t_stack **stb, int to_find)
{
	t_stack *tmp;
	int 	rx;
	int 	rrx;

	rx = 1;
	rrx = 0;
	tmp = *stb;
	while (tmp && tmp->cont != to_find)
	{
		rx++;
		tmp = tmp->next;
	}
	while (tmp)
	{
		rrx++;
		tmp = tmp->next;
	}
	rotate_b(stb, rx, rrx);
}

void	paste_in_head(t_stack **sta, t_stack **stb, int to_find)
{
	t_stack *tmp;
	int 	rx;
	int 	rrx;

	rx = 0;
	rrx = 1;
	tmp = *stb;
	while (tmp && tmp->cont != to_find)
	{
		rx++;
		tmp = tmp->next;
	}
	while (tmp)
	{
		rrx++;
		tmp = tmp->next;
	}
	rotate_b(stb, rx, rrx);
	//pb(sta, stb);
	//rb(stb); //disable
}

/*int		choose_direct_rot_f_insert(t_stack *stack, int val)
{
	int 	r;
	int 	rr;

	r = 0;
	rr = 0;
	while (stack != min)
	{
		r++;
		stack = stack->next;
	}
	while (stack)
	{
		rr++;
		stack = stack->next;
	}
	if (r < rr)
		return (1);
	else
		return (0);
}*/

void	paste_in_body(t_stack **sta, t_stack **stb, int min)
{
	t_stack *tmp;
	int 	rx;
	int 	rrx;

	rx = 0;
	rrx = 1;
	tmp = *stb;
	while (tmp && tmp->cont)
	{
		if (min <= tmp->cont && tmp->cont < (*sta)->cont)
			min = tmp->cont;
		tmp = tmp->next;
	}
	tmp = *stb;
	while (tmp && tmp->cont != min)
	{
		rx++;
		tmp = tmp->next;
	}
	while (tmp)
	{
		rrx++;
		tmp = tmp->next;
	}
	rotate_b(stb, rx, rrx);
	pb(sta, stb);
	//rb(stb);//disable
	//rb(stb);//disable
}

void	insert_stb(t_stack **sta, t_stack **stb, int *extval)
{
	if (!*stb)
	{
		pb(sta, stb);
		extval[0] = (*stb)->cont;
		extval[1] = (*stb)->cont;
	}
	else if ((*sta)->cont < extval[0]) //lover minimal
	{
		paste_in_tail(sta, stb, extval[0]);
		pb(sta, stb);
		extval[0] = (*stb)->cont;
	}
	else if ((*sta)->cont > extval[1]) //bigger biggest
	{
		paste_in_head(sta, stb, extval[1]);
		pb(sta, stb);
		extval[1] = (*stb)->cont;
	}
	else
	{
		paste_in_body(sta, stb, extval[0]);
		//choose_direct_rot_f_insert(*stb, (*sta)->cont);
	}
}

t_stack *getlast(t_stack *cur)
{
	while (cur != NULL && cur->next != NULL)
		cur = cur->next;
	return (cur);
}

char 	*mysort(t_stack **sta, t_stack **stb)
{
	t_stack *min;
	int		qel;
	int 	i;
	int 	extval[2];

	i = 0;
	/*while (*sta)
	{
		qel = create_cmp_arr(*sta, &min);
		while (i++ < ABS(qel))
		{
			if (qel < 0)
				rra(sta);
			else
				ra(sta);
		}
		insert_stb(sta, stb, extval);
		print_stack(*sta, *stb);
	}*/
	paste_in_tail(sta, stb, -20438801);
	print_stack(*sta, *stb);
	/*while (*stb)
		pa(sta, stb);*/
}
