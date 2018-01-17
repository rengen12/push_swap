/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <amichak@marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 20:43:00 by amichak           #+#    #+#             */
/*   Updated: 2017/12/29 20:43:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "stack.h"

typedef struct s_ps_fl{
	int 	v;
	int 	f;
	int 	st;
	int 	ac;
}				t_ps_fl;

void	ft_delete_exit(char *mess, t_stack **st1, t_stack **st2, t_ps_fl **f);
t_ps_fl	*alloc_struct(int ac);
t_ps_fl *handle_data(int ac, char **av, t_stack **a, t_stack **b);
int		lstlen(t_stack *stack);

int 	is_sorted(t_stack *stack);
int 	is_sorted_n(t_stack *st, int n);
int 	is_sorted_rev_n(t_stack *stack, int n);
char	*opt_cmds(char *c);

void 	sort_3par_a(t_stack **st, char **cmds, int q);
void 	sort_3par_b(t_stack **a, t_stack **b, char **cmds, int q);



char 	*mysort(t_stack **sta, t_stack **stb, char *cmds);
int		choose_direct_rot(t_stack *stack, t_stack *min);








int		push_half_to_b(t_stack **sta, t_stack **stb, char **cmds, int qel);
int		push_half_to_a(t_stack **sta, t_stack **stb, char **cmds, int qel);

void	myqsort_stack_a(t_stack **a, t_stack **b, int q, char **cmds);
void	myqsort_stack_b(t_stack **a, t_stack **b, int q, char **cmds);






#endif