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
void	ft_delete_exit(char *message, t_stack **stack);
int 	is_sorted(t_stack *stack);

int		lstlen(t_stack *stack);

char 	*mysort(t_stack **sta, t_stack **stb, char *cmds);
int		choose_direct_rot(t_stack *stack, t_stack *min);

void	ft_qsort(t_stack **sta, t_stack **stb, char **cmds);
int 	is_sorted_n(t_stack *st, int n);
int 	is_sorted_rev(t_stack *st);
int		push_half_to_b(t_stack **sta, t_stack **stb, char **cmds, int qel);

#endif