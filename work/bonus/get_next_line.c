/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:41:30 by moaregra          #+#    #+#             */
/*   Updated: 2024/05/16 10:41:52 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <fcntl.h>
#include <unistd.h>

static char	*read_left(char *str)
{
	char	*result;
	int		i;

	i = 0;
	if (!str || !str[i])
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	result = (char *)malloc((i + 2) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		result[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static char	*read_right(char *str)
{
	char	*result;
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	result = (char *)malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (!result)
	{
		free(result);
		return (NULL);
	}
	i++;
	while (str[i] != '\0')
		result[j++] = str[i++];
	result[j] = '\0';
	free(str);
	return (result);
}

static char	*fill_buffer(char *str, int fd)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		return (NULL);
	}
	while (bytes_read != 0 && !ft_strchr(str, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		str = ft_strjoinn(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result = fill_buffer(result, fd);
	if (!result)
	{
		free(result);
		return (NULL);
	}
	line = read_left(result);
	result = read_right(result);
	return (line);
}
