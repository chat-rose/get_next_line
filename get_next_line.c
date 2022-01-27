/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:49:40 by jschapin          #+#    #+#             */
/*   Updated: 2021/12/22 14:55:45 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_str(char *str)
{
	char	*clean_str;
	size_t	i;
	size_t	j;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!ft_strchr(str, '\n') || ft_strlen(&str[i + 1]) == 0)
		return (free(str), NULL);
	clean_str = malloc(sizeof(char) * (ft_strlen(&str[i + 1]) + 1));
	if (!clean_str)
		return (free(str), NULL);
	j = 0;
	while (str && str[i + 1 + j] != '\0')
	{
		clean_str[j] = str[i + 1 + j];
		j++;
	}
	clean_str[j] = '\0';
	free(str);
	return (clean_str);
}

char	*get_line(char *str)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!ft_strchr(str, '\n'))
		i--;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	j = 0;
	while (j <= i)
	{
		line[j] = str[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*get_str(int fd, char *str)
{
	char	*buf;
	int		read_len;

	read_len = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (read_len && !ft_strchr(str, '\n'))
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len < 0)
		{
			free (buf);
			return (NULL);
		}
		else
		{
			buf[read_len] = '\0';
			str = ft_strjoin(str, buf);
		}
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = get_str(fd, str);
	if (!str)
	{
		free(str);
		return (NULL);
	}
	line = get_line(str);
	str = clean_str(str);
	return (line);
}
