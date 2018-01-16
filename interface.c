/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <amichak@marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 20:44:00 by amichak           #+#    #+#             */
/*   Updated: 2017/12/29 20:44:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *message)
{
	ft_putendl_fd(message, 2);
	exit(0);
}

void	ft_delete_exit(char *mess, t_stack **st1, t_stack **st2, t_ps_fl **f)
{
	if (st1)
		delete_stack(st1);
	if (st2)
		delete_stack(st2);
	if (f)
		if (*f)
			free(*f);
	ft_error(mess);
}

int		check_duplicates(int num, t_stack *stack)
{
	while (stack)
		if (stack->cont == num)
			return (1);
		else
			stack = stack->next;
	return (0);
}

void	datatostack(t_ps_fl *fl, int file, char **av, t_stack **stack)
{
	ssize_t	num;

	while (fl->st <= fl->ac || file)
	{
		if ((!ft_isdigit(*av[fl->ac]) && *av[fl->ac] != '-') || \
				(!ft_isdigit(*(av[fl->ac] + 1)) && *av[fl->ac] == '-'))
			ft_delete_exit("Error!\nWrong argument", stack, NULL, &fl);
		num = ft_atoi(av[fl->ac]);
		if (num > 2147483647 || num < -2147483648)
			ft_delete_exit("Error!\nOut of int's range", stack, NULL, &fl);
		if (check_duplicates((int)num, *stack))
			ft_delete_exit("Error!\nDuplicate found", stack, NULL, &fl);
		add_node(stack, (int)num);
		if (file)
		{
			free(*av);
			break ;
		}
		else
			fl->ac--;
	}
}


t_ps_fl *alloc_struct(int ac)
{
	t_ps_fl	*fl;

	if (!(fl = (t_ps_fl *)malloc(sizeof(t_ps_fl))))
		return (NULL);
	fl->c = 0;
	fl->f = 0;
	fl->v = 0;
	fl->st = 0;
	fl->ac = ac - 1;
	return (fl);
}

t_ps_fl *search_flags(int ac, char **av)
{
	t_ps_fl	*fl;
	int		i;
	int 	ii;

	if (!(fl = alloc_struct(ac)))
		return (NULL);
	i = 0;
	while (++i < ac)
	{
		ii = 1;
		if (av[i][0] == '-' && !ft_isdigit(av[i][1]))
			while (av[i][ii])
				if (av[i][ii] == 'f')
					fl->f = 1;
				else if (av[i][ii] == 'v')
					fl->v = 1;
				else if (av[i][ii] == 'c')
					fl->c = 1;
				else
					i++;
		else
			break ;
	}
	fl->st = i;
	return (fl);
}

int		is_com_line_arg(char *s)
{
	int 	res;

	res = 0;
	while (*s && !ft_isdigit(*s))
		s++;
	if (*s && ft_isdigit(*s))
		res++;
	while (*s && ft_isdigit(*s))
		s++;
	if (*s && *s == ' ')
		res++;
	while (*s && !ft_isdigit(*s))
		s++;
	if (*s && ft_isdigit(*s))
		res++;
	if (res == 3)
		return (1);
	return (0);
}

t_ps_fl *handle_data(int ac, char **av, t_stack **a, t_stack **b)
{
	int 	fd;
	t_ps_fl	*fl;

	fl = search_flags(ac, av);
	if (fl->st >= ac)
		return (fl);
	if (fl->f)
	{
		if ((fd = open(av[2], O_RDONLY)) == -1)
			ft_delete_exit("File not exist", NULL, NULL, &fl);
		while (get_next_line(fd, av) > 0 && (fl->ac = 0) == 0)
			datatostack(fl, 1, av, b);
		close(fd);
	}
	else if (is_com_line_arg(av[fl->st]))
	{
		av = ft_strsplit(av[1], ' ');
		while (*av && (fl->ac = 0) == 0)
			datatostack(fl, 1, av++, b);
	}
	else
		datatostack(fl, 0, av, a);
	while(*b)
		pa(a, b);
	return (fl);
}

int 	is_sorted(t_stack *stack)
{
	if (stack)
	{
		while (stack->next)
			if (stack->cont > stack->next->cont)
				return (0);
			else
				stack = stack->next;
	}
	return (1);
}

int 	is_sorted_rev(t_stack *stack)
{
	if (stack)
	{
		while (stack->next)
			if (stack->cont < stack->next->cont)
				return (0);
			else
				stack = stack->next;
	}
	return (1);
}

int 	is_sorted_rev_n(t_stack *stack, int n)
{
	if (stack)
	{
		while (stack->next && n--)
		{
			if (stack->cont < stack->next->cont)
				return (0);
			else
				stack = stack->next;
		}
	}
	return (1);
}

int 	is_sorted_n(t_stack *st, int n)
{
	if (st)
		while (st->next && n--)
		{
			if (st->cont > st->next->cont)
				return (0);
			else
				st = st->next;
		}
	return (1);
}