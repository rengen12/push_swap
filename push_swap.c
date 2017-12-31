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

// Returns the last node of the list
t_stack *getTail(t_stack *cur)
{
	while (cur != NULL && cur->next != NULL)
		cur = cur->next;
	return (cur);
}

// Partitions the list taking the last element as the pivot
t_stack *partition(t_stack *head, t_stack *end,
					   t_stack **newHead, t_stack **newEnd)
{
	t_stack *pivot = end;
	t_stack *prev = NULL, *cur = head, *tail = pivot;

	// During partition, both the head and end of the list might change
	// which is updated in the newHead and newEnd variables
	while (cur != pivot)
	{
		if (cur->cont < pivot->cont)
		{
			// First node that has a value less than the pivot - becomes
			// the new head
			if ((*newHead) == NULL)
				(*newHead) = cur;

			prev = cur;
			cur = cur->next;
		}
		else // If cur node is greater than pivot
		{
			// Move cur node to next of tail, and change tail
			if (prev)
				prev->next = cur->next;
			t_stack *tmp = cur->next;
			cur->next = NULL;
			tail->next = cur;
			tail = cur;
			cur = tmp;
		}
	}

	// If the pivot data is the smallest element in the current list,
	// pivot becomes the head
	if ((*newHead) == NULL)
		(*newHead) = pivot;

	// Update newEnd to the current last node
	(*newEnd) = tail;

	// Return the pivot node
	return pivot;
}


//here the sorting happens exclusive of the end node
t_stack *quickSortRecur(t_stack *head, t_stack *end)
{
	// base condition
	if (!head || head == end)
		return head;

	t_stack *newHead = NULL, *newEnd = NULL;

	// Partition the list, newHead and newEnd will be updated
	// by the partition function
	t_stack *pivot = partition(head, end, &newHead, &newEnd);

	// If pivot is the smallest element - no need to recur for
	// the left part.
	if (newHead != pivot)
	{
		// Set the node before the pivot node as NULL
		t_stack *tmp = newHead;
		while (tmp->next != pivot)
			tmp = tmp->next;
		tmp->next = NULL;

		// Recur for the list before pivot
		newHead = quickSortRecur(newHead, tmp);

		// Change next of last node of the left half to pivot
		tmp = getTail(newHead);
		tmp->next =  pivot;
	}

	// Recur for the list after the pivot element
	pivot->next = quickSortRecur(pivot->next, newEnd);

	return newHead;
}

// The main function for quick sort. This is a wrapper over recursive
// function quickSortRecur()
void quickSort(t_stack **headRef)
{
	(*headRef) = quickSortRecur(*headRef, getTail(*headRef));
	return;
}




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






/*int partition (int arr[], int b, int e)
{
	int x = arr[e];
	int i = (b - 1);

	for (int j = b; j <= e - 1; j++)
	{
		if (arr[j] <= x)
		{
			i++;
			ft_swap (&arr[i], &arr[j]);
		}
	}
	ft_swap (&arr[i + 1], &arr[e]);
	ft_putarr(arr, e + 1, ' ');
	return (i + 1);
}


void quickSort(int A[], int b, int e)
{
	if (b < e)
	{
		int p = partition(A, b, e);
		quickSort(A, b, p - 1);
		quickSort(A, p + 1, e);
	}
}*/








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
	int 	*mas;

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
	print_stack(stacka, stackb);


	if (is_sorted(stacka))
		ft_delete_exit("Stack is sorted", &stacka);
	else
		quickSort(&stacka);
		/*cmds = selection_sort(&stacka, &stackb, cmds);*/
		/*while (!is_sorted(stacka))
			cmds = bublesort(&stacka, &stackb, cmds);*/

	//ft_putstr(cmds);
	ft_putstr("\n\n");
	print_stack(stacka, stackb);
	if (is_sorted(stacka))
		ft_putstr("Stack is sorted");

	/*stack ----> arr for qsort
	 *
	 * */
/*	int maslen = lstlen(stacka);

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