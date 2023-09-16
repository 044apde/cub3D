/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:57:01 by marvin            #+#    #+#             */
/*   Updated: 2023/04/22 22:06:21 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd, char **remain, char *buffer, int count_read)
{
	char	*temp_remain;

	while (count_read)
	{
		count_read = read(fd, buffer, BUFFER_SIZE);
		if (count_read == 0)
			break ;
		if (count_read == -1)
			return (NULL);
		buffer[count_read] = '\0';
		if (*remain == NULL)
			*remain = ft_strdup("");
		if (*remain == NULL)
			return (NULL);
		temp_remain = *remain;
		*remain = ft_strjoin(temp_remain, buffer);
		free(temp_remain);
		temp_remain = NULL;
		if (*remain == NULL)
			return (NULL);
		if (ft_strchr(*remain, '\n') != NULL)
			return (*remain);
	}
	return (*remain);
}

static char	*make_remain(char *line)
{
	ssize_t	index;
	char	*new_remain;

	index = 0;
	while (line[index] != '\0' && line[index] != '\n')
		++index;
	if (line[index] == '\0' || line[index + 1] == '\0')
		return (NULL);
	else
	{
		new_remain = ft_strdup(line + index + 1);
		line[index + 1] = '\0';
	}
	return (new_remain);
}

static char	*tirm_line(char *line)
{
	char	*temp_line;

	temp_line = line;
	line = ft_strdup(temp_line);
	free (temp_line);
	temp_line = NULL;
	if (line == NULL)
		return (NULL);
	return (line);
}

static char	*free_remain(char **remain)
{
	free(*remain);
	*remain = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*remain;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (free_remain(&remain));
	line = read_file(fd, &remain, buffer, 1);
	free (buffer);
	buffer = NULL;
	if (line == NULL)
	{
		if (remain != NULL)
			return (free_remain(&remain));
		return (NULL);
	}
	remain = make_remain(line);
	line = tirm_line(line);
	if (line == NULL && remain != NULL)
		free_remain(&remain);
	return (line);
}
