/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <amichak@marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 20:40:00 by amichak           #+#    #+#             */
/*   Updated: 2017/12/29 20:40:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include "get_next_line.h"

void	sort_3_nonempty_sta(t_stack **st, char **cmds, int max)
{
	if ((*st)->next->cont == max)
	{
		ra(st);
		*cmds = ft_strjoin(*cmds, "ra\n");
		sa(st);
		*cmds = ft_strjoin(*cmds, "sa\n");
		rra(st);
		*cmds = ft_strjoin(*cmds, "rra\n");
	}
	else if ((*st)->cont == max)
	{
		sa(st);
		*cmds = ft_strjoin(*cmds, "sa\n");
		ra(st);
		*cmds = ft_strjoin(*cmds, "ra\n");
		sa(st);
		*cmds = ft_strjoin(*cmds, "sa\n");
		rra(st);
		*cmds = ft_strjoin(*cmds, "rra\n");
	}
}

void 	sort_3par_a(t_stack **st, char **cmds, int q)
{
	int 	max;

	max = find_max_val_n(*st, 3);
	if (q == 3 && *st && (*st)->next && (*st)->next->next && lstlen(*st) == 3)
	{
		if ((*st)->cont == max)
		{
			ra(st);
			*cmds = ft_strjoin(*cmds, "ra\n");
		}
		else if ((*st)->next->cont == max)
		{
			rra(st);
			*cmds = ft_strjoin(*cmds, "rra\n");
		}
	}
	else if (q == 3 && *st && (*st)->next && (*st)->next->next)
		sort_3_nonempty_sta(st, cmds, max);
	if (*st && (*st)->next)
		if ((*st)->cont > (*st)->next->cont)
		{
			sa(st);
			*cmds = ft_strjoin(*cmds, "sa\n");
		}
}

int 	max_at_the_end(t_stack **sta, t_stack **stb, char **cmds)
{
	rb(stb);
	*cmds = ft_strjoin(*cmds, "rb\n");
	sb(stb);
	*cmds = ft_strjoin(*cmds, "sb\n");
	pa(sta, stb);
	*cmds = ft_strjoin(*cmds, "pa\n");
	rrb(stb);
	*cmds = ft_strjoin(*cmds, "rrb\n");
	return (2);
}

int		sort_3_nonempty_stb(t_stack **sta, t_stack **stb, char **cmds, int max)
{
	if (is_sorted_rev_n(*stb, 3))
		return (3);
	if ((*stb)->cont == max)
	{
		pa(sta, stb);
		*cmds = ft_strjoin(*cmds, "pa\n");
		return (2);
	}
	else if ((*stb)->cont == find_min_val_n(*stb, 3) && (*stb)->next->cont == max)
	{
		sb(stb);
		*cmds = ft_strjoin(*cmds, "sb\n");
		pa(sta, stb);
		*cmds = ft_strjoin(*cmds, "pa\n");
		return (2);
	}
	else if ((*stb)->next->next->cont == max)
		return (max_at_the_end(sta, stb, cmds));
	return (3);
}

void	pa3x(t_stack **sta, t_stack **stb, int q, char **cmds)
{
	while (*stb && q--)
	{
		pa(sta, stb);
		*cmds = ft_strjoin(*cmds, "pa\n");
	}
}
void 	sort_3par_b(t_stack **a, t_stack **b, char **cmds, int q)
{
	int 	min;

	min = find_min_val_n(*b, q);
	if (q == 3 && *b && (*b)->next && (*b)->next->next && lstlen(*b) == 3)
	{
		if ((*b)->cont == min)
		{
			rb(b);
			*cmds = ft_strjoin(*cmds, "rb\n");
		}
		else if ((*b)->next->cont == min)
		{
			rrb(b);
			*cmds = ft_strjoin(*cmds, "rrb\n");
		}
	}
	else if (q == 3 && *b && (*b)->next && (*b)->next->next)
		q = sort_3_nonempty_stb(a, b, cmds, find_max_val_n(*b, 3));
	if (*b && (*b)->next)
		if ((*b)->cont < (*b)->next->cont)
		{
			sb(b);
			*cmds = ft_strjoin(*cmds, "sb\n");
		}
	pa3x(a, b, q, cmds);
}

void	myqsort_stack_b(t_stack **a, t_stack **b, int q, char **cmds)
{
	int		moved;
	int 	i;

	i = 0;
	/*ft_putendl("________________");
	ft_putendl("qs B start");
	ft_putstr("q = ");
	ft_putnbr(q);
	ft_putendl("");
	print_stack(*a, *b);*/
	if (is_sorted_rev_n(*b, q))
	{
		while (i < q && *b)
		{
			pa(a, b);
			*cmds = ft_strjoin(*cmds, "pa\n");
			i++;
		}
		return ;
	}

		if (q > 3)
		{

			moved = push_half_to_a(a, b, cmds, q);
			/*ft_putendl("________________");
			ft_putendl("qs B after pushing");
			ft_putstr("q = ");
			ft_putnbr(q);
			ft_putendl("");
			print_stack(*a, *b);*/

			myqsort_stack_a(a, b, moved, cmds);
			myqsort_stack_b(a, b, q - moved, cmds);

		}
		else
			sort_3par_b(a, b, cmds, q);

	/*ft_putendl("________________");
	ft_putendl("qs B end");
	ft_putstr("q = ");
	ft_putnbr(q);
	ft_putendl("");
	print_stack(*a, *b);*/
}

void	myqsort_stack_a(t_stack **a, t_stack **b, int q, char **cmds)
{
	int		moved;

	/*ft_putendl("________________");
	ft_putendl("qs A start");
	ft_putstr("q = ");
	ft_putnbr(q);
	ft_putendl("");
	print_stack(*a, *b);*/
	if (is_sorted_n(*a, q))
		return ;
	if (q > 3)
	{
		moved = push_half_to_b(a, b, cmds, q);
		/*ft_putendl("________________");
		ft_putendl("qs A after pushing");
		ft_putstr("q = ");
		ft_putnbr(q);
		ft_putendl("");
		print_stack(*a, *b);*/

		myqsort_stack_a(a, b, q - moved, cmds);
		myqsort_stack_b(a, b, moved, cmds);
	}
	else
		sort_3par_a(a, cmds, q);
	/*ft_putendl("________________");
	ft_putendl("qs A end");
	ft_putstr("q = ");
	ft_putnbr(q);
	ft_putendl("");
	print_stack(*a, *b);*/


}

int main(int ac, char **av)
{
	t_stack *stacka;
	t_stack *stackb;
	int 	fd;
	char 	*cmds;
	//int 	*mas;

	stacka = NULL;
	stackb = NULL;
	cmds = "";
	//printf("ac = %d\n", ac);


	if (ac == 3 && !ft_strcmp(av[1], "-f"))
	{
		fd = open(av[2], O_RDONLY);
		while (get_next_line(fd, av) > 0)
			datatostack(0, 1, av, &stackb);
		while(stackb)
			pa(&stacka, &stackb);
		close(fd);
	}
	else
		datatostack(ac - 1, 0, av, &stacka);
	//print_stack(stacka, stackb);


	if (is_sorted(stacka))
		ft_delete_exit("Stack is sorted", &stacka);
	else
	{

			myqsort_stack_a(&stacka, &stackb, lstlen(stacka), &cmds);
			//myqsort_stack_b(&stacka, &stackb, lstlen(stackb), &cmds);
		//cmds = mysort(&stacka, &stackb, cmds);

	}
		//ft_qsort(&stacka, &stackb, &cmds);
		//cmds = mysort(&stacka, &stackb, cmds);
		//median_sort(&stacka, &stackb, cmds);
		//quickSort(&stacka);
		//cmds = selection_sort(&stacka, &stackb, cmds);
		/*while (!is_sorted(stacka))
			cmds = bublesort(&stacka, &stackb, cmds);*/

	ft_putstr(cmds);
	//cmds = opt_cmds(cmds);
	/*ft_putendl("\n\nFINAL");
	print_stack(stacka, stackb);*/
	/*if (is_sorted(stacka))
		ft_putendl("Stack is sorted");*/

	delete_stack(&stacka);
	delete_stack(&stackb);
	return (0);
}