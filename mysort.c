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

char	*rotate_b(t_stack **st, int rx, int rrx, char *cmds)
{
	if (rrx < rx)
		while (rrx-- > 0)
		{
			rra(st);
			cmds = ft_strjoin(cmds, "rra\n");
		}
	else
		while (rx-- > 0)
		{
			ra(st);
			cmds = ft_strjoin(cmds, "ra\n");
		}
	return (cmds);
}

char	*paste_in_tail(t_stack **st, int to_find, char *cmds)
{
	t_stack *tmp;
	int 	rx;
	int 	rrx;

	rx = 1;
	rrx = 0;
	tmp = *st;
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
	return (rotate_b(st, rx, rrx, cmds));
}

char	*paste_in_head(t_stack **st, int to_find, char *cmds)
{
	t_stack *tmp;
	int 	rx;
	int 	rrx;

	rx = 0;
	rrx = 0;
	tmp = *st;
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
	return (rotate_b(st, rx, rrx, cmds));
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

char	*paste_in_body(t_stack **sta, t_stack **stb, int max, char *cmds)
{
	t_stack *tmp;
	int 	rx;
	int 	rrx;

	rx = 0;
	rrx = 0;
	tmp = *sta;
	while (tmp)
	{
		if (max >= tmp->cont && tmp->cont > (*stb)->cont)
			max = tmp->cont;
		tmp = tmp->next;
	}
	tmp = *sta;
	while (tmp && tmp->cont != max)
	{
		rx++;
		tmp = tmp->next;
	}
	while (tmp)
	{
		rrx++;
		tmp = tmp->next;
	}
	return (rotate_b(sta, rx, rrx, cmds));
	//rb(stb);//disable
	//rb(stb);//disable
}

t_stack *getlast(t_stack *cur)
{
	while (cur != NULL && cur->next != NULL)
		cur = cur->next;
	return (cur);
}

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

int 	find_min_val(t_stack *st)
{
	int 	min;

	if (!st)
		return (0);
	min = st->cont;
	while (st)
	{
		if (st->cont <  min)
			min = st->cont;
		st = st->next;
	}
	return (min);
}

int 	find_max_val(t_stack *st)
{
	int 	max;

	if (!st)
		return (0);
	max = st->cont;
	while (st)
	{
		if (st->cont >  max)
			max = st->cont;
		st = st->next;
	}
	return (max);
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

void 	swap_st_elem(t_stack **prev, t_stack **cur, t_stack **nxt)
{
	t_stack *newnxt;

	/*if (*prev)
	{
		//(*prev)->next = *nxt;
		//newnxt = (*nxt)->next;
		//(*nxt)->next = *cur;
		//(*cur)->next = newnxt;
		//*cur = (*prev)->next;
		(*cur)->next = (*nxt)->next;
		(*nxt)->next = *cur;
		*cur = *nxt;
	}
	else
	{
		(*cur)->next = (*nxt)->next;
		(*nxt)->next = *cur;
		*cur = *nxt;
		//newnxt = (*nxt)->next;
		//(*nxt)->next = *cur;
		//(*cur)->next = newnxt;
		//*cur = *nxt;
	}*/
	newnxt = *nxt;
	(*cur)->next = (*nxt)->next;
	newnxt->next = *cur;
	*cur = newnxt;
	if (*prev)
		(*prev)->next = *cur;
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

void	ft_qsort(t_stack **a, t_stack **b, char **cmds)
{
	//int moved;
	//int	qel;
	t_stack *pivot;

	//qel = lstlen(*a);
	//moved = push_half_to_b(a, b, cmds, qel);
	pivot = *a;
	pb(a, b);
	while (!is_sorted(*a))
		if (*a && (*a)->cont < pivot->cont)
		{
			rb(a);

		}
		else
		{
			pb(a, b);
		}
}

char	*insert_stb(t_stack **sta, t_stack **stb, int *extval, char *cmds)
{
	if (!*sta)
	{
		pa(sta, stb);
		cmds = ft_strjoin(cmds, "pa\n");
		extval[0] = (*sta)->cont;
		extval[1] = (*sta)->cont;
	}
	else if ((*stb)->cont > extval[1]) //bigger biggest
	{
		cmds = paste_in_tail(sta, extval[1], cmds);
		pa(sta, stb);
		cmds = ft_strjoin(cmds, "pa\n");
		extval[1] = (*sta)->cont;
	}
	else if ((*stb)->cont < extval[0]) //lover minimal
	{
		cmds = paste_in_head(sta, extval[0], cmds);
		pa(sta, stb);
		cmds = ft_strjoin(cmds, "pa\n");
		extval[0] = (*sta)->cont;
	}
	else
	{
		cmds = paste_in_body(sta, stb, extval[1], cmds);
		pa(sta, stb);
		cmds = ft_strjoin(cmds, "pa\n");
		//choose_direct_rot_f_insert(*stb, (*sta)->cont);
	}
	return (cmds);
}

char 	*mysort(t_stack **sta, t_stack **stb, char *cmds)
{
	t_stack *min;
	int 	qel;
	int 	extval[2];
	//int 	lsthalf;
	int 	i;
	int 	moved;
/*i++ < ABS(qel)*/

	//lsthalf = lstlen(*sta) / 2;
	/*while (lsthalf)
	{
		pb(sta, stb);
		cmds = ft_strjoin(cmds, "pb\n");
		lsthalf--;
	}*/
	extval[0] = find_min_val(*sta);
	extval[1] = find_max_val(*sta);




	/*while (*sta)
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
			qel = 1;*/
		qel = lstlen(*stb);
		while (qel)
		{
			//print_stack(*sta, *stb);
			cmds = insert_stb(sta, stb, extval, cmds);
			if (qel < 0)
				qel++;
			else
				qel--;
		}
		//print_stack(*sta, *stb);
	//}
	cmds = paste_in_head(sta, extval[0], cmds);
	/*while (*stb)
	{
		pa(sta, stb);
		cmds = ft_strjoin(cmds, "pa\n");
	}*/
	return (cmds);
}
