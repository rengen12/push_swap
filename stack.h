/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:25:00 by amichak           #+#    #+#             */
/*   Updated: 2017/12/21 13:25:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_stack
{
	int				cont;
	struct s_stack	*next;
}				t_stack;

void	add_node(t_stack **head, int cont);
void	delete_stack(t_stack **head);
void	print_stack(t_stack *head1, t_stack *head2);
void	sa(t_stack **head);
void	sb(t_stack **head);
void	ss(t_stack **heada, t_stack **headb);
void	pa(t_stack **heada, t_stack **headb);
void	pb(t_stack **heada, t_stack **headb);
void	ra(t_stack **head);
void	rb(t_stack **head);
void	rr(t_stack **heada, t_stack **headb);
void	rra(t_stack **head);
void	rrb(t_stack **head);
void	rrr(t_stack **heada, t_stack **headb);


#endif