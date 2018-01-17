/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:25:00 by amichak           #+#    #+#             */
/*   Updated: 2018/01/16 18:25:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		max_at_the_end(t_stack **sta, t_stack **stb, char **cmds)
{
	rb(stb);
	*cmds = ft_strjoin_fr_frst(*cmds, "rb\n");
	sb(stb);
	*cmds = ft_strjoin_fr_frst(*cmds, "sb\n");
	pa(sta, stb);
	*cmds = ft_strjoin_fr_frst(*cmds, "pa\n");
	rrb(stb);
	*cmds = ft_strjoin_fr_frst(*cmds, "rrb\n");
	return (2);
}

int		sort_3_nonempty_stb(t_stack **a, t_stack **b, char **cmds, int max)
{
	if (is_sorted_rev_n(*b, 3))
		return (3);
	if ((*b)->cont == max)
	{
		pa(a, b);
		*cmds = ft_strjoin_fr_frst(*cmds, "pa\n");
		return (2);
	}
	else if ((*b)->cont == find_min_val_n(*b, 3) && (*b)->next->cont == max)
	{
		sb(b);
		*cmds = ft_strjoin_fr_frst(*cmds, "sb\n");
		pa(a, b);
		*cmds = ft_strjoin_fr_frst(*cmds, "pa\n");
		return (2);
	}
	else if ((*b)->next->next->cont == max)
		return (max_at_the_end(a, b, cmds));
	return (3);
}

void	pa3x(t_stack **sta, t_stack **stb, int q, char **cmds)
{
	while (*stb && q--)
	{
		pa(sta, stb);
		*cmds = ft_strjoin_fr_frst(*cmds, "pa\n");
	}
}

void	sort_3par_b(t_stack **a, t_stack **b, char **cmds, int q)
{
	int	min;

	min = find_min_val_n(*b, q);
	if (q == 3 && *b && (*b)->next && (*b)->next->next && lstlen(*b) == 3)
	{
		if ((*b)->cont == min)
		{
			rb(b);
			*cmds = ft_strjoin_fr_frst(*cmds, "rb\n");
		}
		else if ((*b)->next->cont == min)
		{
			rrb(b);
			*cmds = ft_strjoin_fr_frst(*cmds, "rrb\n");
		}
	}
	else if (q == 3 && *b && (*b)->next && (*b)->next->next)
		q = sort_3_nonempty_stb(a, b, cmds, find_max_val_n(*b, 3));
	if (*b && (*b)->next)
		if ((*b)->cont < (*b)->next->cont)
		{
			sb(b);
			*cmds = ft_strjoin_fr_frst(*cmds, "sb\n");
		}
	pa3x(a, b, q, cmds);
}
