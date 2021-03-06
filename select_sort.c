/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:51:00 by amichak           #+#    #+#             */
/*   Updated: 2018/01/09 15:51:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		choose_direct_rot(t_stack *stack, t_stack *min)
{
	int	r;
	int	rr;

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
}

static t_stack	*find_min_in_stack(t_stack *stack)
{
	t_stack	*min_el;

	if (!stack)
		return (NULL);
	min_el = stack;
	while (stack)
	{
		if (min_el->cont > stack->cont)
			min_el = stack;
		stack = stack->next;
	}
	return (min_el);
}

static char		*swapping(char *cmds, t_stack **sta, t_stack *min)
{
	if ((*sta)->cont > (*sta)->next->cont && min != *sta)
	{
		sa(sta);
		cmds = ft_strjoin_fr_frst(cmds, "sa\n");
	}
	return (cmds);
}

static char		*push_to_a(t_stack **sta, t_stack **stb, char *cmds)
{
	while (*stb)
	{
		pa(sta, stb);
		cmds = ft_strjoin_fr_frst(cmds, "pa\n");
	}
	return (cmds);
}

char			*selection_sort(t_stack **sta, t_stack **stb, char *cmds)
{
	t_stack *min;

	while ((*sta)->next)
	{
		min = find_min_in_stack(*sta);
		if (choose_direct_rot(*sta, min))
			while (min != *sta)
			{
				cmds = ft_strjoin_fr_frst(cmds, "ra\n");
				ra(sta);
				cmds = swapping(cmds, sta, min);
			}
		else
			while (min != *sta)
			{
				cmds = ft_strjoin_fr_frst(cmds, "rra\n");
				rra(sta);
				cmds = swapping(cmds, sta, min);
			}
		pb(sta, stb);
		cmds = ft_strjoin_fr_frst(cmds, "pb\n");
	}
	return (push_to_a(sta, stb, cmds));
}
