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


t_stack	*find_min_in_stack(t_stack *stack)
{
	t_stack	*min_el;

	if (!stack)
		return (NULL);
	min_el = stack;
	while (stack)
	{
		if (min_el->cont > stack->cont)
			min_el = stack;
		stack = stack->next;
	}
	return (min_el);
}

int		choose_direct_rot(t_stack *stack, t_stack *min)
{
	int 	r;
	int 	rr;

	r = 0;
	rr = 0;
	while (stack != min)
	{
		r++;
		stack = stack->next;
	}
	while (stack)
	{
		rr++;
		stack = stack->next;
	}
	if (r < rr)
		return (1);
	else
		return (0);
}

char	*selection_sort(t_stack **sta, t_stack **stb, char *cmds)
{
	t_stack *min;

	/*if ((*sta)->cont > (*sta)->next->cont)
	{
		sa(sta);
		cmds = ft_strjoin(cmds, "sa\n");
	}*/
	while ((*sta)->next)
	{
		min = find_min_in_stack(*sta);
		if (choose_direct_rot(*sta, min))
			while (min != *sta)
			{
				cmds = ft_strjoin(cmds, "ra\n");
				ra(sta);
				/*if ((*sta)->cont > (*sta)->next->cont && min != *sta)
				{
					sa(sta);
					cmds = ft_strjoin(cmds, "sa\n");
				}*/
			}
		else
			while (min != *sta)
			{
				cmds = ft_strjoin(cmds, "rra\n");
				rra(sta);
				/*if ((*sta)->cont > (*sta)->next->cont && min != *sta)
				{
					sa(sta);
					cmds = ft_strjoin(cmds, "sa\n");
				}*/
			}
		pb(sta, stb);
		cmds = ft_strjoin(cmds, "pb\n");
	}
	while (*stb)
	{
		pa(sta, stb);
		cmds = ft_strjoin(cmds, "pa\n");
	}
	return (cmds);
}

/*void	margesort(t_stack *sta, t_stack *stb, int qe)
{

}
margesort(&stacka, &stackb, ac - 1);*/

char*	bublesort(t_stack **sta, t_stack **stb, char *cmds)
{
	if (!sta || !*sta)
		return (NULL);
	while ((*sta)->next)
	{
		if ((*sta)->cont < (*sta)->next->cont)
		{
			pb(sta, stb);
			cmds = ft_strjoin(cmds, "pb\n");
		}
		else
		{
			sa(sta);
			cmds = ft_strjoin(cmds, "sa\n");
		}
	}
	while ((*stb)->next)
	{
		if ((*stb)->cont > (*stb)->next->cont)
		{
			pa(sta, stb);
			cmds = ft_strjoin(cmds, "pa\n");
		}
		else
		{
			sb(stb);
			cmds = ft_strjoin(cmds, "sb\n");
		}
	}
	if (*stb)
	{
		pa(sta, stb);
		cmds = ft_strjoin(cmds, "pa\n");
	}
	return (cmds);
}

//printf_num_l(cmds);

/*char *quicksort(t_stack **stacka, t_stack **stackb, char *cmds)
{

}*/






int partition (int arr[], int l, int h)
{
	int x = arr[h];
	int i = (l - 1);

	for (int j = l; j <= h- 1; j++)
	{
		if (arr[j] <= x)
		{
			i++;
			ft_swap (&arr[i], &arr[j]);
		}
		ft_putarr(arr, h + 1, ' ');
	}
	ft_swap (&arr[i + 1], &arr[h]);
	return (i + 1);
}

/* A[] --> Array to be sorted, l  --> Starting index, h  --> Ending index */
void quickSort(int A[], int l, int h)
{
	if (l < h)
	{
		int p = partition(A, l, h); /* Partitioning index */
		quickSort(A, l, p - 1);
		quickSort(A, p + 1, h);
	}
}








int		lstlen(t_stack *stack)
{
	int 	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int 	main(int ac, char **av)
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
		cmds = selection_sort(&stacka, &stackb, cmds);
		/*while (!is_sorted(stacka))
			cmds = bublesort(&stacka, &stackb, cmds);*/

	ft_putstr(cmds);
	//print_stack(stacka, stackb);


	/*stack ----> arr for qsort
	 *
	 * int maslen = lstlen(stacka);

	if(!(mas = ft_arrnew(maslen)))
		return (1);
	int i = 0;

	t_stack *tmphead;

	tmphead = stacka;
	while (i < maslen)
	{
		mas[i++] = tmphead->cont;
		tmphead = tmphead->next;
	}
	ft_putarr(mas, maslen, ' ');

	quickSort(mas, 0, maslen - 1);
	ft_putarr(mas, maslen, ' ');
	free(mas);*/
	delete_stack(&stacka);
	delete_stack(&stackb);
	return (0);
}