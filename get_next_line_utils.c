/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:10:01 by luizedua          #+#    #+#             */
/*   Updated: 2023/05/30 14:13:47 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		c;

	c = 0;
	dup = malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (s[c])
	{
		dup[c] = s[c];
		c++;
	}
	dup[c] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		res_len;
	int		index;
	char	*n_string;

	index = 0;
	if (s2 == NULL)
		return (ft_strdup(s1));
	if (s1 == NULL)
		return (ft_strdup(s2));
	res_len = ft_strlen(s1) + ft_strlen(s2);
	n_string = malloc((res_len + 1) * sizeof(char));
	if (n_string == NULL)
		return (NULL);
	while (*s1 != '\0')
		n_string[index++] = *s1++;
	while (*s2 != '\0')
		n_string[index++] = *s2++;
	n_string[index] = '\0';
	return (n_string);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char)c && *s != '\0')
		s++;
	if ((char)c == *s)
		return ((char *)s);
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mem;
	size_t	vartimes;

	vartimes = nmemb * size;
	if (!nmemb || !size)
		return (malloc(0));
	if (vartimes > __INT_MAX__ || vartimes / nmemb != size)
		return (NULL);
	mem = malloc(vartimes);
	if (!mem)
	{
		while (vartimes != 0)
		{
			vartimes--;
			mem[vartimes] = '\0';
		}
	}
	return ((void *)mem);
}
