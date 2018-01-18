/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:16:19 by amichak           #+#    #+#             */
/*   Updated: 2018/01/18 17:16:20 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	in_str(const char *str, const char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i] && str[i] && to_find[i] == str[i])
		i++;
	if (!to_find[i])
		return (1);
	return (0);
}

static int	change_instr(char **res, char *inst_to_paste, int ic, int *i)
{
	*res = ft_strcat(*res, inst_to_paste);
	*i += ft_strlen(inst_to_paste);
	return (ic);
}

char		*opt_cmds(char *c)
{
	char	*res;
	int		i;
	int		ic;

	i = 0;
	ic = 0;
	if (!(res = ft_strnew(ft_strlen(c))))
		return (NULL);
	while (c[ic])
		if (in_str(&c[ic], "\nra\nrb\n") || in_str(&c[ic], "\nrb\nra\n"))
			ic += change_instr(&res, "\nrr\n", 7, &i);
		else if (in_str(&c[ic], "rra\nrrb\n") || in_str(&c[ic], "rrb\nrra\n"))
			ic += change_instr(&res, "rrr\n", 8, &i);
		else if (in_str(&c[ic], "sa\npb\npb\nsa\n"))
			ic += change_instr(&res, "pb\npb\nss\n", 12, &i);
		else if (in_str(&c[ic], "sb\npa\npa\nsb\n"))
			ic += change_instr(&res, "pa\npa\nss\n", 12, &i);
		else if (in_str(&c[ic], "sa\nsb\n") || in_str(&c[ic], "sb\nsa\n"))
			ic += change_instr(&res, "ss\n", 6, &i);
		else if (in_str(&c[ic], "pa\npb\n") || in_str(&c[ic], "pb\npa\n"))
			ic += 6;
		else
			res[i++] = c[ic++];
	free(c);
	return (res);
}
