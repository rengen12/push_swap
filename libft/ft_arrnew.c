/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <amichak@marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 22:11:00 by amichak           #+#    #+#             */
/*   Updated: 2017/12/30 22:11:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int 	*ft_arrnew(int len)
{
	int		*mas;

	if (!(mas = (int *)malloc(sizeof(int) * len)))
		return (NULL);
	return (ft_memset(mas, 0, len));
}
