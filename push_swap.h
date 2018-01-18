/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:19:05 by amichak           #+#    #+#             */
/*   Updated: 2018/01/18 17:19:06 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "stack.h"

typedef struct	s_ps_fl{
	int		v;
	int		f;
	int		st;
	int		ac;
}				t_ps_fl;

void			ft_delete_exit(char *mess, t_stack **st1, t_stack **st2,
							t_ps_fl **f);
t_ps_fl			*handle_data(int ac, char **av, t_stack **a, t_stack **b);
t_ps_fl			*alloc_struct(int ac);
int				lstlen(t_stack *stack);
int				find_max_val_n(t_stack *st, int q);

int				is_sorted(t_stack *stack);
int				is_sorted_n(t_stack *st, int n);
int				is_sorted_rev_n(t_stack *stack, int n);

void			myqsort_stack_a(t_stack **a, t_stack **b, int q, char **cmds);
char			*selection_sort(t_stack **sta, t_stack **stb, char *cmds);

int				find_av_val(t_stack *st, int qel, int a);
int				find_quant_to_move(t_stack *st, int av_val, char s_cmp);
int				push_half_to_b(t_stack **sta, t_stack **stb, char **cmds,
								int qel);
int				push_half_to_a(t_stack **sta, t_stack **stb, char **cmds,
								int qel);

void			sort_3par_a(t_stack **st, char **cmds, int q);
void			sort_3par_b(t_stack **a, t_stack **b, char **cmds, int q);

char			*opt_cmds(char *c);

#endif
