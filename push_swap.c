/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <amichak@marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 20:40:00 by amichak           #+#    #+#             */
/*   Updated: 2017/12/29 20:40:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	myqsort_stack_b(t_stack **a, t_stack **b, int q, char **cmds)
{
	int		moved;
	int 	i;

	i = 0;
	if (is_sorted_rev_n(*b, q))
	{
		while (i < q && *b)
		{
			pa(a, b);
			*cmds = ft_strjoin_fr_frst(*cmds, "pa\n");
			i++;
		}
		return ;
	}
	if (q > 3)
	{
		moved = push_half_to_a(a, b, cmds, q);
		myqsort_stack_a(a, b, moved, cmds);
		myqsort_stack_b(a, b, q - moved, cmds);
	}
	else
		sort_3par_b(a, b, cmds, q);
}

void	myqsort_stack_a(t_stack **a, t_stack **b, int q, char **cmds)
{
	int		moved;

	if (is_sorted_n(*a, q))
		return ;
	if (q > 3)
	{
		moved = push_half_to_b(a, b, cmds, q);
		myqsort_stack_a(a, b, q - moved, cmds);
		myqsort_stack_b(a, b, moved, cmds);
	}
	else
		sort_3par_a(a, cmds, q);
}

float 	sort_factor(t_stack *st, int qel)
{
	float	res;

	res = 1;
	while (st && st->next)
	{
		if (st->cont > st->next->cont)
			res++;
		st = st->next;
	}
	return (res / qel * 100);
}

t_stack	*getlast(t_stack *cur)
{
	while (cur != NULL && cur->next != NULL)
		cur = cur->next;
	return (cur);
}

void	buble_sort(t_stack **a, char **cmds)
{
	int 	f;
	t_stack *tmp;

	f = 1;
	while (f && (tmp = getlast(*a)))
	{
		f = 0;
		while ((*a)->cont != tmp->cont)
			if ((*a)->cont > (*a)->next->cont)
			{
				f = 1;
				sa(a);
				*cmds = ft_strjoin_fr_frst(*cmds, "sa\n");
			}
			else
			{
				ra(a);
				*cmds = ft_strjoin_fr_frst(*cmds, "ra\n");
			}
		if (f)
		{
			ra(a);
			*cmds = ft_strjoin_fr_frst(*cmds, "ra\n");
		}
	}
}

int 	in_str(const char *str, const char *to_find)
{
	int 	i;

	i = 0;
	while (to_find[i] && str[i] && to_find[i] == str[i])
		i++;
	if (!to_find[i])
		return (1);
	return (0);
}

char	*opt_cmds(char *c)
{
	char 	*res;
	int 	i;
	int 	ic;

	i = 0;
	ic = 0;
	if (!(res = ft_strnew(ft_strlen(c))))
		return (NULL);
	while (c[ic])
	{
		if (in_str(&c[ic], "\nra\nrb\n") || in_str(&c[ic], "\nrb\nra\n"))
		{
			res = ft_strcat(res, "\nrr\n");
			ic += 7;
			i += 4;
		}
		else if (in_str(&c[ic], "rra\nrrb\n") || in_str(&c[ic], "rrb\nrra\n"))
		{
			res = ft_strcat(res, "rrr\n");
			ic += 8;
			i += 4;
		}
		else if (in_str(&c[ic], "sa\npb\npb\nsa\n"))
		{
			res = ft_strcat(res, "pb\npb\nss\n");
			ic += 12;
			i += 9;
		}
		else if (in_str(&c[ic], "sb\npa\npa\nsb\n"))
		{
			res = ft_strcat(res, "pa\npa\nss\n");
			ic += 12;
			i += 9;
		}
		else if (in_str(&c[ic], "sa\nsb\n") || in_str(&c[ic], "sb\nsa\n"))
		{
			res = ft_strcat(res, "ss\n");
			ic += 6;
			i += 3;
		}
		else if (in_str(&c[ic], "pa\npb\n") || in_str(&c[ic], "pb\npa\n"))
			ic += 6;
		else
			res[i++] = c[ic++];
	}
	free(c);
	return (res);
}

int		main(int ac, char **av)
{
	t_stack *stacka;
	t_stack *stackb;
	char 	*cmds;

	if (ac == 1)
		return (0);
	stacka = NULL;
	stackb = NULL;
	cmds = ft_strnew(1);
	handle_data(ac, av, &stacka, &stackb);
	if (is_sorted(stacka))
		ft_delete_exit("Stack is sorted", &stacka, NULL);
	else
		if (sort_factor(stacka, lstlen(stacka)) >= 76.9)
			cmds = mysort(&stacka, &stackb, cmds);
		else
			myqsort_stack_a(&stacka, &stackb, lstlen(stacka), &cmds);
	cmds = opt_cmds(cmds);
	cmds = opt_cmds(cmds);
	cmds = opt_cmds(cmds);
	ft_putstr(cmds);
	free(cmds);
	delete_stack(&stacka);
	delete_stack(&stackb);
	return (0);
}