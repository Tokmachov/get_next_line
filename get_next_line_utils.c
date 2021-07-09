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
#include "get_next_line.h"

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

char			*ft_strchr(const char *s, int c)
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
