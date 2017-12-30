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

void	datatostack(int ac, int file, char **av, t_stack **stack);
void	ft_delete_exit(char *message, t_stack **stack);
int 	is_sorted(t_stack *stack);

#endif