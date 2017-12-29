/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:10:41 by amichak           #+#    #+#             */
/*   Updated: 2017/11/20 22:18:12 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include "libft/libft.h"
# define BUFF_SIZE 12

int		get_next_line(const int fd, char **line);

#endif
