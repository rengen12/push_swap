/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_qsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengen <rengen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 13:03:00 by amichak           #+#    #+#             */
/*   Updated: 2018/01/18 00:37:36 by rengen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_in_start_pos(char *instr, int rx, t_stack **st, char **cmds)
{
	while (rx--)
	{
		rra(st);
		*cmds = ft_strjoin_fr_frst(*cmds, instr);
	}
}

int		find_to_move_a(t_stack **stb, int *av_val, int qel, int *needrotate)
{
	if (!*stb)
		return (0);
	*needrotate = (lstlen(*stb) != qel) ? 1 : 0;
	*av_val = find_av_val(*stb, qel, 0);
	return (find_quant_to_move(*stb, *av_val, '>'));
}

int		push_half_to_a(t_stack **sta, t_stack **stb, char **cmds, int qel)
{
	int		av_val;
	int		to_move;
	int		rx;
	int		needrotate;
	int		i;

	i = 0;
	rx = 0;
	to_move = find_to_move_a(stb, &av_val, qel, &needrotate);
	while (i < to_move)
		if ((*stb)->cont > av_val)
		{
			pa(sta, stb);
			i++;
			*cmds = ft_strjoin_fr_frst(*cmds, "pa\n");
		}
		else
		{
			rx++;
			rb(stb);
			*cmds = ft_strjoin_fr_frst(*cmds, "rb\n");
		}
	if (needrotate)
		rot_in_start_pos("rrb\n", rx, stb, cmds);
	return (to_move);
}

int		find_to_move_b(t_stack **sta, int *av_val, int qel, int *needrotate)
{
	if (!*sta)
		return (0);
	*needrotate = (lstlen(*sta) != qel) ? 1 : 0;
	*av_val = find_av_val(*sta, qel, 1);
	return (find_quant_to_move(*sta, *av_val, '<'));
}

int		push_half_to_b(t_stack **sta, t_stack **stb, char **cmds, int qel)
{
	int		av_val;
	int		to_move;
	int		rx;
	int		needrotate;
	int		i;

	i = 0;
	rx = 0;
	to_move = find_to_move_b(sta, &av_val, qel, &needrotate);
	while (i < to_move)
		if ((*sta)->cont <= av_val)
		{
			pb(sta, stb);
			i++;
			*cmds = ft_strjoin_fr_frst(*cmds, "pb\n");
		}
		else
		{
			ra(sta);
			rx++;
			*cmds = ft_strjoin_fr_frst(*cmds, "ra\n");
		}
	if (needrotate)
		rot_in_start_pos("rra\n", rx, sta, cmds);
	return (to_move);
}
