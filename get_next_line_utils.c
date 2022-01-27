/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:52:16 by jschapin          #+#    #+#             */
/*   Updated: 2021/12/22 14:52:21 by jschapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	if (s == NULL)
		return (NULL);
	i = 0;
	ptr = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			ptr = (char *)(s + i);
		i++;
	}
	if (s[i] == (char)c)
		ptr = (char *)(s + i);
	return (ptr);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*catstr;
	size_t	i;
	size_t	j;

	if ((ft_strlen(s1) + ft_strlen(s2)) == 0)
		return (NULL);
	catstr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!catstr)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		catstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		catstr[i + j] = s2[j];
		j++;
	}
	catstr[i + j] = '\0';
	return (free(s1), catstr);
}
