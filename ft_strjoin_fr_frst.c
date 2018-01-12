/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_fr_frst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:37:28 by amichak           #+#    #+#             */
/*   Updated: 2017/10/30 15:37:30 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin_fr_frst(char *s1, char const *s2)
{
	char	*r;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	if (!(r = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	i = 0;
	ft_strcpy(r, s1);
	ft_strcat(r, s2);
	free(s1);
	return (r);
}