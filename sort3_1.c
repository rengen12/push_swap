/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:20:00 by amichak           #+#    #+#             */
/*   Updated: 2018/01/16 18:20:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_nonempty_sta(t_stack **st, char **cmds, int max)
{
	if ((*st)->next->cont == max)
	{
		ra(st);
		*cmds = ft_strjoin_fr_frst(*cmds, "ra\n");
		sa(st);
		*cmds = ft_strjoin_fr_frst(*cmds, "sa\n");
		rra(st);
		*cmds = ft_strjoin_fr_frst(*cmds, "rra\n");
	}
	else if ((*st)->cont == max)
	{
		sa(st);
		*cmds = ft_strjoin_fr_frst(*cmds, "sa\n");
		ra(st);
		*cmds = ft_strjoin_fr_frst(*cmds, "ra\n");
		sa(st);
		*cmds = ft_strjoin_fr_frst(*cmds, "sa\n");
		rra(st);
		*cmds = ft_strjoin_fr_frst(*cmds, "rra\n");
	}
}

void 	sort_3par_a(t_stack **st, char **cmds, int q)
{
	int 	max;

	max = find_max_val_n(*st, 3);
	if (q == 3 && *st && (*st)->next && (*st)->next->next && lstlen(*st) == 3)
	{
		if ((*st)->cont == max)
		{
			ra(st);
			*cmds = ft_strjoin_fr_frst(*cmds, "ra\n");
		}
		else if ((*st)->next->cont == max)
		{
			rra(st);
			*cmds = ft_strjoin_fr_frst(*cmds, "rra\n");
		}
	}
	else if (q == 3 && *st && (*st)->next && (*st)->next->next)
		sort_3_nonempty_sta(st, cmds, max);
	if (*st && (*st)->next)
		if ((*st)->cont > (*st)->next->cont)
		{
			sa(st);
			*cmds = ft_strjoin_fr_frst(*cmds, "sa\n");
		}
}