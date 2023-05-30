/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:32:52 by luizedua          #+#    #+#             */
/*   Updated: 2023/05/30 15:05:26 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(int fd)
{
	char	*line_buffer;
	int		retread;
	char	*line;
	char	*temp_line;

	line = NULL;
	retread = 1;
	line_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (retread)
	{
		retread = read(fd, line_buffer, BUFFER_SIZE);
		if (retread <= 0)
			break ;
		line_buffer[retread] = '\0';
		temp_line = ft_strjoin(line, line_buffer);
		if (line != NULL)
			free(line);
		line = temp_line;
		if (ft_strchr(line, '\n'))
			break ;
		if (line == NULL)
			return (NULL);
	}
	free (line_buffer);
	return (line);
}

void	line_checker(char **line, char **line_end, char **reminiscent, int fd)
{
	if (!ft_strchr(*reminiscent, '\n'))
	{
		*line_end = read_line(fd);
		if (line_end == NULL)
			*line = ft_strdup(*reminiscent);
		else
			*line = ft_strjoin(*reminiscent, *line_end);
		free(*reminiscent);
		free(*line_end);
		*reminiscent = NULL;
	}
	else
	{
		*line = ft_strdup(*reminiscent);
		free(*reminiscent);
		*reminiscent = NULL;
	}	
}

char	*line_trimmer(int fd)
{
	char		*linetobtrim;
	char		*line_end;
	static char	*reminiscent[1024];

	linetobtrim = NULL;
	if (reminiscent[fd] != NULL)
		line_checker(&linetobtrim, &line_end, &reminiscent[fd], fd);
	else
		linetobtrim = read_line(fd);
	line_end = ft_strchr(linetobtrim, '\n');
	if (line_end != NULL && line_end[1] != '\0')
	{
		reminiscent[fd] = ft_strdup(line_end + 1);
		line_end[1] = '\0';
	}
	return (linetobtrim);
}

char	*get_next_line(int fd)
{
	char	*line;

	if (fd < 0)
		return (NULL);
	line = line_trimmer(fd);
	return (line);
}
