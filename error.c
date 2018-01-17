/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <amichak@marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 23:46:00 by amichak           #+#    #+#             */
/*   Updated: 2018/01/17 23:46:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_error(char *message)
{
	ft_putendl_fd(message, 2);
	exit(0);
}

void		ft_delete_exit(char *mess, t_stack **st1, t_stack **st2,
						   t_ps_fl **f)
{
	if (st1)
		delete_stack(st1);
	if (st2)
		delete_stack(st2);
	if (f)
		if (*f)
			free(*f);
	ft_error(mess);
}
