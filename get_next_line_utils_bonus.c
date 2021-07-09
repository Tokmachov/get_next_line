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

#include <stdlib.h>
#include "get_next_line_bonus.h"

static	size_t	ft_strlen(char *str)
{
	size_t len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char			*ft_strjoin(char *first, char *second)
{
	size_t	first_len;
	size_t	second_len;
	char	*str_joined;
	size_t	i;

	first_len = first ? ft_strlen(first) : 0;
	second_len = second ? ft_strlen(second) : 0;
	str_joined = (char*)malloc((first_len + second_len + 1) * sizeof(char));
	i = 0;
	while (i < first_len)
	{
		str_joined[i] = first[i];
		i++;
	}
	while (i < first_len + second_len)
	{
		str_joined[i] = second[i - first_len];
		i++;
	}
	str_joined[i] = '\0';
	return (str_joined);
}

char			*ft_strdup(char *str)
{
	size_t	len;
	char	*cpy;
	int		i;

	len = ft_strlen(str);
	cpy = (char*)malloc((len + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	i = 0;
	while ((cpy[i] = str[i]))
		i++;
	return (cpy);
}

t_storage		*ft_lstnew(char *line_cache, int fd)
{
	t_storage *new_list;

	new_list = (t_storage*)malloc(1 * sizeof(t_storage));
	if (new_list)
	{
		new_list->line_cache = line_cache;
		new_list->fd = fd;
		new_list->next = NULL;
	}
	return (new_list);
}

void			lst_clear(t_storage **storage_head)
{
	t_storage *current;
	t_storage *next;

	current = *storage_head;
	while (current)
	{
		next = current->next;
		free(current->line_cache);
		free(current);
		current = next;
	}
}
