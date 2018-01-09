/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:51:00 by amichak           #+#    #+#             */
/*   Updated: 2018/01/09 15:51:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rewrite_mas(t_stack **mas, t_stack *last)
{
	mas[0] = mas[1];
	mas[1] = mas[2];
	mas[2] = last;
}

void	prep_vars(t_stack **mas1, t_stack **mas2, int *i)
{
	*i = 0;
	mas1[0] = NULL;
	mas2[0] = NULL;
	mas1[1] = NULL;
	mas2[1] = NULL;
	mas1[2] = NULL;
	mas2[2] = NULL;
}

int 	retmin(t_stack **min, t_stack **mas, int val)
{
	*min = *mas;
	return (val);
}

int 	find_nearest(t_stack **p_down, t_stack **p_up, t_stack **min, int q)
{
	int 	i;

	i = 0;
	while (i < 2)
		if ((p_down[i] && p_down[i]->cont < (*min)->cont) || \
				(p_up[i] && p_up[i]->cont < (*min)->cont))
			break ;
		else
			i++;
	if ((p_down[i] && p_down[i]->cont < (*min)->cont) && \
			(p_up[i] && p_up[i]->cont < (*min)->cont))
	{
		if (p_down[i]->cont < p_up[i]->cont)
			return (retmin(min, &p_down[i], q));
		else
			return (retmin(min, &p_up[i], (q * -1)));
	}
	if ((p_down[i] && p_down[i]->cont < (*min)->cont))
		return (retmin(min, &p_down[i], q));
	return (retmin(min, &p_up[i], (q * -1)));
}

int		find_min_arr(t_stack **min, t_stack **p_down, t_stack **p_up)
{
	int 	que1;
	int 	que2;
	int 	i;

	i = 0;
	que1 = 0;
	que2 = 0;
	while (i < 3)
	{
		if (p_down[i] && p_down[i]->cont < (*min)->cont)
			que1++;
		if (p_up[i] && p_up[i]->cont < (*min)->cont)
			que2++;
		i++;
	}
	if (que1 == que2 && que1)
		return (find_nearest(p_down, p_up, min, que1));
	else if (que1 > que2)
		return (retmin(min, p_down, que1));
	else if (que1 < que2)
		return (retmin(min, p_up, (que2 * -1)));
	return (0);
}

int		create_cmp_arr(t_stack *st, t_stack **min)
{
	t_stack	*p_down[3];
	t_stack	*p_up[3];
	int 	i;

	*min = st;
	prep_vars(p_down, p_up, &i);
	while (i < 3 && st->next)
	{
		st = st->next;
		p_down[i++] = st;
	}
	while (st)
	{
		st = st->next;
		rewrite_mas(p_up, st);
	}
	return (find_min_arr(min, p_down, p_up));
}


char	*rotate_b(t_stack **st, int rx, int rrx, char *cmds)
{
	if (rrx < rx)
		while (rrx-- > 0)
		{
			rra(st);
			cmds = ft_strjoin(cmds, "rra\n");
		}
	else
		while (rx-- > 0)
		{
			ra(st);
			cmds = ft_strjoin(cmds, "ra\n");
		}
	return (cmds);
}

char	*paste_in_tail(t_stack **st, int to_find, char *cmds)
{
	t_stack *tmp;
	int 	rx;
	int 	rrx;

	rx = 1;
	rrx = 0;
	tmp = *st;
	while (tmp && tmp->cont != to_find)
	{
		rx++;
		tmp = tmp->next;
	}
	/*if (tmp && tmp->next)
		tmp = tmp->next;*/
	while (tmp && tmp->next)
	{
		rrx++;
		tmp = tmp->next;
	}
	return (rotate_b(st, rx, rrx, cmds));
}

char	*paste_in_head(t_stack **st, int to_find, char *cmds)
{
	t_stack *tmp;
	int 	rx;
	int 	rrx;

	rx = 0;
	rrx = 0;
	tmp = *st;
	while (tmp && tmp->cont != to_find)
	{
		rx++;
		tmp = tmp->next;
	}
	while (tmp)
	{
		rrx++;
		tmp = tmp->next;
	}
	return (rotate_b(st, rx, rrx, cmds));
	//pb(sta, stb);
	//rb(stb); //disable
}

/*int		choose_direct_rot_f_insert(t_stack *stack, int val)
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
}*/

char	*paste_in_body(t_stack **sta, t_stack **stb, int max, char *cmds)
{
	t_stack *tmp;
	int 	rx;
	int 	rrx;

	rx = 0;
	rrx = 0;
	tmp = *sta;
	while (tmp)
	{
		if (max >= tmp->cont && tmp->cont > (*stb)->cont)
			max = tmp->cont;
		tmp = tmp->next;
	}
	tmp = *sta;
	while (tmp && tmp->cont != max)
	{
		rx++;
		tmp = tmp->next;
	}
	while (tmp)
	{
		rrx++;
		tmp = tmp->next;
	}
	return (rotate_b(sta, rx, rrx, cmds));
	//rb(stb);//disable
	//rb(stb);//disable
}

t_stack *getlast(t_stack *cur)
{
	while (cur != NULL && cur->next != NULL)
		cur = cur->next;
	return (cur);
}




int 	find_min_val(t_stack *st)
{
	int 	min;

	if (!st)
		return (0);
	min = st->cont;
	while (st)
	{
		if (st->cont <  min)
			min = st->cont;
		st = st->next;
	}
	return (min);
}

int 	find_max_val(t_stack *st)
{
	int 	max;

	if (!st)
		return (0);
	max = st->cont;
	while (st)
	{
		if (st->cont >  max)
			max = st->cont;
		st = st->next;
	}
	return (max);
}



void	ft_qsort(t_stack **a, t_stack **b)
{
	//int moved;
	//int	qel;
	t_stack *pivot;

	//qel = lstlen(*a);
	//moved = push_half_to_b(a, b, cmds, qel);
	pivot = *a;
	pb(a, b);
	while (!is_sorted(*a))
		if (*a && (*a)->cont < pivot->cont)
		{
			rb(a);

		}
		else
		{
			pb(a, b);
		}
}

char	*insert_stb(t_stack **sta, t_stack **stb, int *extval, char *cmds)
{
	if (!*sta)
	{
		pa(sta, stb);
		cmds = ft_strjoin(cmds, "pa\n");
		extval[0] = (*sta)->cont;
		extval[1] = (*sta)->cont;
	}
	else if ((*stb)->cont > extval[1]) //bigger biggest
	{
		cmds = paste_in_tail(sta, extval[1], cmds);
		pa(sta, stb);
		cmds = ft_strjoin(cmds, "pa\n");
		extval[1] = (*sta)->cont;
	}
	else if ((*stb)->cont < extval[0]) //lover minimal
	{
		cmds = paste_in_head(sta, extval[0], cmds);
		pa(sta, stb);
		cmds = ft_strjoin(cmds, "pa\n");
		extval[0] = (*sta)->cont;
	}
	else
	{
		cmds = paste_in_body(sta, stb, extval[1], cmds);
		pa(sta, stb);
		cmds = ft_strjoin(cmds, "pa\n");
		//choose_direct_rot_f_insert(*stb, (*sta)->cont);
	}
	return (cmds);
}

char 	*mysort(t_stack **sta, t_stack **stb, char *cmds)
{
	//t_stack *min;
	int 	qel;
	int 	extval[2];
	//int 	lsthalf;
	//int 	i;
	//int 	moved;
/*i++ < ABS(qel)*/

	//lsthalf = lstlen(*sta) / 2;
	/*while (lsthalf)
	{
		pb(sta, stb);
		cmds = ft_strjoin(cmds, "pb\n");
		lsthalf--;
	}*/
	extval[0] = find_min_val(*sta);
	extval[1] = find_max_val(*sta);




	/*while (*sta)
	{
		//i = 0;
		qel = create_cmp_arr(*sta, &min);
		while (*sta != min)
		{
			if (qel < 0)
			{
				rra(sta);
				cmds = ft_strjoin(cmds, "rra\n");
			}
			else
			{
				ra(sta);
				cmds = ft_strjoin(cmds, "ra\n");
			}
		}
		if (!qel)
			qel = 1;*/
	qel = lstlen(*stb);
	while (qel)
	{
		//print_stack(*sta, *stb);
		cmds = insert_stb(sta, stb, extval, cmds);
		if (qel < 0)
			qel++;
		else
			qel--;
	}
	//print_stack(*sta, *stb);
	//}
	cmds = paste_in_head(sta, extval[0], cmds);
	/*while (*stb)
	{
		pa(sta, stb);
		cmds = ft_strjoin(cmds, "pa\n");
	}*/
	return (cmds);
}














int		find_min_val_stack(t_stack *stack)
{
	t_stack	*min_el;

	if (!stack)
		return (0);
	min_el = stack;
	while (stack)
	{
		if (min_el->cont > stack->cont)
			min_el = stack;
		stack = stack->next;
	}
	return (min_el->cont);
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



/*
// qsort for array
//
int partition (int arr[], int b, int e)
{
	int x = arr[e];
	int i = (b - 1);
	ft_putendl("in partition. Mas orig mas");
	ft_putarr(arr, 10, ' ');
	ft_putendl("operations");
	for (int j = b; j <= e - 1; j++)
	{
		if (arr[j] <= x)
		{
			i++;
			ft_swap (&arr[i], &arr[j]);
		}
		ft_putarr(arr, 10, ' ');
	}
	ft_swap (&arr[i + 1], &arr[e]);
	ft_putendl("mas after cycle");
	ft_putarr(arr, 10, ' ');
	ft_putendl("");
	return (i + 1);
}


void quickSort(int A[], int b, int e)
{
	if (b < e)
	{
		int p = partition(A, b, e);
		ft_putendl("first");
		quickSort(A, b, p - 1);
		ft_putendl("second");
		quickSort(A, p + 1, e);
	}
	else
		ft_putendl("pb");
}*/


/*char	*cutstring(char **orig, char *start, char *todelete, char *paste)
{

	if (start)
	{

	}
}

char	*opt_cmds(char *cmds)
{
	char *res;
	res = cutstring(cmds, ft_strstr(&cmds, "ra\nrb\n"), "ra\nrb\n")
	ft_putstr(new);

}*/

/*
//-8119124 -3873710 2278516 40158649 54157143 59938666 108535001 129505786 207821177 213156669
//-8119124 -3873710 2278516 40158649 54157143 59938666 108535001 129505786 207821177 213156669
int 	mypartition(int arr[], int b, int e)
{
	int	x = arr[e];
	int i = (b - 1);
	int j = b;
	while (j < e)
	{
		if (arr[j] < x)
			ft_swap(&arr[++i], &arr[j]);
		j++;
	}
	ft_swap(&arr[i + 1], &arr[e]);
	return (i + 1);
}

void	myquicksort(int arr[], int b, int e)
{
	if (b < e)
	{
		int p = mypartition(arr, b, e);
		myquicksort(arr, b, p - 1);
		myquicksort(arr, p + 1, e);
	}
}
*/



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
}



/* DRAFT */

t_stack	*get_tail(t_stack *head)
{
	if (head)
		while (head->next)
			head = head->next;
	return (head);
}

/*t_stack	*partiton(t_stack **a, t_stack **b)
{
	t_stack *pivot;
	t_stack *cur;

	pb(a, b);
	pivot = *b;
	cur = *a;
	while (cur)
	{

		cur = cur->next;
	}

}*/

t_stack *mypartition(t_stack **a, t_stack **b)
{
	t_stack *end;

	end = get_tail(*a);
	while (*a)
	{

		if ((*a)->cont < end->cont)
		{
			if ((*a)->next && (*a)->cont > (*a)->next->cont)
				sa(a);
			ra(a);
		}
		else
		{
			if ((*a)->next && (*a)->cont > (*a)->next->cont && (*a)->next != end)
				sa(a);
			pb(a, b);
		}
	}
	/*while (*a != pivot)
	{
		if ((*a)->cont > pivot->cont)
		{
			pb(a, b);
		}
		else
			rb(a);
	}*/
	return (end);
}



/*stack ----> arr for qsort
	 *
	 * */
/*int maslen = lstlen(stacka);

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
//myquicksort(mas, 0, maslen - 1);
//quickSort(mas, 0, maslen - 1);
ft_putarr(mas, maslen, ' ');
free(mas);*/