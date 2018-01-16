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

# define ABS(x) ((x < 0) ? (-x) : (x))

void	datatostack(int ac, int file, char **av, t_stack **stack);
void	handle_data(int ac, char **av, t_stack **a, t_stack **b);
void	ft_delete_exit(char *message, t_stack **stack1, t_stack **stack2);
int 	is_sorted(t_stack *stack);
char	*ft_strjoin_fr_frst(char *s1, char const *s2);

int		lstlen(t_stack *stack);

char 	*mysort(t_stack **sta, t_stack **stb, char *cmds);
int		choose_direct_rot(t_stack *stack, t_stack *min);

int 	is_sorted_n(t_stack *st, int n);
int 	is_sorted_rev(t_stack *st);
int 	is_sorted_rev_n(t_stack *stack, int n);
int		push_half_to_b(t_stack **sta, t_stack **stb, char **cmds, int qel);
int		push_half_to_a(t_stack **sta, t_stack **stb, char **cmds, int qel);

void	myqsort_stack_a(t_stack **a, t_stack **b, int q, char **cmds);
void	myqsort_stack_b(t_stack **a, t_stack **b, int q, char **cmds);

int 	find_min_val_n(t_stack *st, int q);
int 	find_max_val_n(t_stack *st, int q);
t_stack	*find_min_in_stack(t_stack *stack);

void 	sort_3par_a(t_stack **st, char **cmds, int q);
void 	sort_3par_b(t_stack **a, t_stack **b, char **cmds, int q);


#endif