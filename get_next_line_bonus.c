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

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>

#define NOT_SET -10
#define SUCCESS 1
#define NEW_LINE_WAS_READ 1
#define EOF_WAS_REACHED 0
#define ALL_REMAINDER_WAS_READ 0
#define ERROR -1

static	char		*ft_strchr(const char *s, int c)
{
	char	searched_ch;
	char	*ptr;

	searched_ch = (char)c;
	ptr = (char*)s;
	while (*ptr)
	{
		if (*ptr == searched_ch)
			return (ptr);
		ptr++;
	}
	if (searched_ch == '\0')
		return (ptr);
	else
		return (0);
}

static	int			get_line_from_cache(char **remainder, char **line)
{
	char *nl_ptr;
	char *tmp;

	if ((nl_ptr = ft_strchr(*remainder, '\n')))
	{
		*nl_ptr = '\0';
		*line = ft_strdup(*remainder);
		tmp = *remainder;
		*remainder = ft_strdup(++nl_ptr);
		free(tmp);
	}
	else
		*line = ft_strdup(*remainder);
	if (!*line || !*remainder)
		return (ERROR);
	else
		return (nl_ptr ? NEW_LINE_WAS_READ : ALL_REMAINDER_WAS_READ);
}

static	int			refill_cache_untill_nl(int fd, char **remainder)
{
	ssize_t	number_of_read_bytes;
	char	*buffer;
	char	*tmp;

	buffer = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (ERROR);
	while ((number_of_read_bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[number_of_read_bytes] = '\0';
		tmp = *remainder;
		if (!(*remainder = ft_strjoin(*remainder, buffer)))
			return (ERROR);
		free(tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	if (number_of_read_bytes < 0)
		return (ERROR);
	else
		return (SUCCESS);
}

static	t_storage	*get_storage_for_fd(int fd, t_storage **storage_head)
{
	t_storage	*current;
	t_storage	*new_storage;
	char		*line_cache;

	if (!(line_cache = ft_strdup("")) \
		|| !(new_storage = ft_lstnew(line_cache, fd)))
		return (NULL);
	if (!*storage_head)
		*storage_head = new_storage;
	else
	{
		current = *storage_head;
		while (current->fd != fd && current->next)
			current = current->next;
		if (current->fd == fd)
			return (current);
		else
			current->next = new_storage;
	}
	return (new_storage);
}

int					get_next_line(int fd, char **line)
{
	static t_storage	*storage_head;
	t_storage			*current_storage;
	int					result;

	if (!line || BUFFER_SIZE <= 0)
		return (ERROR);
	if (!(current_storage = get_storage_for_fd(fd, &storage_head)))
	{
		lst_clear(&storage_head);
		return (ERROR);
	}
	result = NOT_SET;
	if (!(ft_strchr(current_storage->line_cache, '\n')))
		result = refill_cache_untill_nl(fd, &current_storage->line_cache);
	if (result != ERROR)
		result = get_line_from_cache(&current_storage->line_cache, line);
	if (result == ERROR)
		lst_clear(&storage_head);
	if (result == EOF_WAS_REACHED)
		*current_storage->line_cache = '\0';
	return (result);
}
