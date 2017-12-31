/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <amichak@marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 23:07:00 by amichak           #+#    #+#             */
/*   Updated: 2017/12/30 23:07:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putarr(int *arr, int len, char separator)
{
	int		i;

	i = 0;
	while (i < len)
	{
		ft_putnbr(arr[i++]);
		if (i < len)
			ft_putchar(separator);
		else
			ft_putchar('\n');
	}
}