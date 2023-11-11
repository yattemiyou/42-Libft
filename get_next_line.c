/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 05:51:41 by anonymous         #+#    #+#             */
/*   Updated: 2023/11/12 07:31:06 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static ssize_t	initialize(int fd, char	**buffer)
{
	ssize_t	len;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > SSIZE_MAX)
		return (-1);
	if (*buffer == NULL)
	{
		*buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (*buffer == NULL)
			return (-1);
	}
	len = (ssize_t)ft_strlen(*buffer);
	if (len == 0)
		len = read(fd, *buffer, BUFFER_SIZE);
	return (len);
}

static void	finalize(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

static ssize_t	concatenate(char **line, char *buffer)
{
	char	*ptr;
	char	*temp;
	char	c;

	ptr = ft_strchr(buffer, '\n');
	if (ptr != NULL)
	{
		c = *(++ptr);
		*ptr = '\0';
	}
	if (*line == NULL)
		temp = ft_strdup(buffer);
	else
		temp = ft_strjoin(*line, buffer);
	if (temp == NULL)
		return (-1);
	free(*line);
	*line = temp;
	if (ptr != NULL)
	{
		*ptr = c;
		ft_memmove(buffer, ptr, ft_strlen(ptr) + 1);
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;
	ssize_t		ret;

	line = NULL;
	ret = initialize(fd, &buffer);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		ret = concatenate(&line, buffer);
		if (ret < 0)
			break ;
		if (ret == 0)
			return (line);
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	if (ret < 0)
		finalize(&line);
	finalize(&buffer);
	return (line);
}
