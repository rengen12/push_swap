/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myqsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <amichak@marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 00:19:00 by amichak           #+#    #+#             */
/*   Updated: 2018/01/18 00:19:00 by amichak          ###   ########.fr       */
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

void		myqsort_stack_a(t_stack **a, t_stack **b, int q, char **cmds)
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
