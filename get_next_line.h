/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_applaying_prescision.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 16:08:07 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 15:43:41 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 8

# endif

int				get_next_line(int fd, char **line);

typedef enum	e_bool
{
	true = 1, false = 0
}				t_bool;
char			*ft_strjoin(char *first, char *second);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(char *str);

#endif
