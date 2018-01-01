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
	mas[0] = mas[1];
	mas[1] = mas[2];
	mas[2] = last;
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
	while (st)
	{
		st = st->next;
		rewrite_mas(p_up, st);
	}
	return (find_min_arr(min, p_down, p_up));
}

char	*rotate_b(t_stack **stb, int rx, int rrx, char *cmds)
{
	if (rrx < rx)
		while (rrx-- > 0)
		{
			rrb(stb);
			cmds = ft_strjoin(cmds, "rrb\n");
		}
	else
		while (rx-- > 0)
		{
			rb(stb);
			cmds = ft_strjoin(cmds, "rb\n");
		}
	return (cmds);
}

char	*paste_in_tail(t_stack **stb, int to_find, char *cmds)
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
	/*if (tmp && tmp->next)
		tmp = tmp->next;*/
	while (tmp && tmp->next)
	{
		rrx++;
		tmp = tmp->next;
	}
	return (rotate_b(stb, rx, rrx, cmds));
}

char	*paste_in_head(t_stack **stb, int to_find, char *cmds)
{
	t_stack *tmp;
	int 	rx;
	int 	rrx;

	rx = 0;
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
	return (rotate_b(stb, rx, rrx, cmds));
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

char	*paste_in_body(t_stack **sta, t_stack **stb, int min, char *cmds)
{
	t_stack *tmp;
	int 	rx;
	int 	rrx;

	rx = 0;
	rrx = 0;
	tmp = *stb;
	while (tmp)
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
	return (rotate_b(stb, rx, rrx, cmds));
	//rb(stb);//disable
	//rb(stb);//disable
}

char	*insert_stb(t_stack **sta, t_stack **stb, int *extval, char *cmds)
{
	if (!*stb)
	{
		pb(sta, stb);
		cmds = ft_strjoin(cmds, "pb\n");
		extval[0] = (*stb)->cont;
		extval[1] = (*stb)->cont;
	}
	else if ((*sta)->cont < extval[0]) //lover minimal
	{
		cmds = paste_in_tail(stb, extval[0], cmds);
		pb(sta, stb);
		cmds = ft_strjoin(cmds, "pb\n");
		extval[0] = (*stb)->cont;
	}
	else if ((*sta)->cont > extval[1]) //bigger biggest
	{
		cmds = paste_in_head(stb, extval[1], cmds);
		pb(sta, stb);
		cmds = ft_strjoin(cmds, "pb\n");
		extval[1] = (*stb)->cont;
	}
	else
	{
		cmds = paste_in_body(sta, stb, extval[0], cmds);
		pb(sta, stb);
		cmds = ft_strjoin(cmds, "pb\n");
		//choose_direct_rot_f_insert(*stb, (*sta)->cont);
	}
	return (cmds);
}

t_stack *getlast(t_stack *cur)
{
	while (cur != NULL && cur->next != NULL)
		cur = cur->next;
	return (cur);
}

char 	*mysort(t_stack **sta, t_stack **stb, char *cmds)
{
	t_stack *min;
	int		qel;
	//int 	i;
	int 	extval[2];
/*i++ < ABS(qel)*/
	while (*sta)
	{
		//i = 0;
		qel = create_cmp_arr(*sta, &min);
		while (*sta != min)
		{
			if (qel < 0)
			{
				rra(sta);
				cmds = ft_strjoin(cmds, "rra\n");
			}
			else
			{
				ra(sta);
				cmds = ft_strjoin(cmds, "ra\n");
			}
		}
		if (!qel)
			qel = 1;
		while (qel)
		{
			cmds = insert_stb(sta, stb, extval, cmds);
			if (qel < 0)
				qel++;
			else
				qel--;
		}
		//print_stack(*sta, *stb);
	}
	cmds = paste_in_head(stb, extval[1], cmds);
	while (*stb)
	{
		pa(sta, stb);
		cmds = ft_strjoin(cmds, "pa\n");
	}
	return (cmds);
}