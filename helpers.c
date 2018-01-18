/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:23:37 by amichak           #+#    #+#             */
/*   Updated: 2018/01/18 17:23:38 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_fl	*alloc_struct(int ac)
{
	t_ps_fl	*fl;

	if (!(fl = (t_ps_fl *)malloc(sizeof(t_ps_fl))))
		return (NULL);
	fl->f = 0;
	fl->v = 0;
	fl->st = 0;
	fl->ac = ac - 1;
	return (fl);
}

int		lstlen(t_stack *stack)
{
	int		i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
