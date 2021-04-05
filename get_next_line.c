/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:33:26 by bledda            #+#    #+#             */
/*   Updated: 2021/04/06 00:22:29 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int			size_read ;
	char		buffer[BUFFER_SIZE + 1];
	static char	*current_line = 0;
	char		*tmp;

	size_read = 1;
	if (current_line == 0)
		current_line = ft_calloc(sizeof(char), 1);
	while (ft_strchr(current_line, '\n') == 0 && size_read > 0)
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		buffer[size_read] = 0;
		tmp = ft_strjoin(current_line, buffer);
		free(current_line);
		current_line = tmp;
		if (size_read == 0)
		{
			*line = ft_strdup(current_line);
			free(current_line);
			current_line = 0;
			return (0);
		}
	}
	if (size_read > 0)
	{
		*line = ft_substr(current_line, 0, (ft_strchr(current_line, '\n') - current_line));
		tmp = ft_strdup(current_line + (ft_strlen(*line) + 1));
		free(current_line);
		current_line = tmp;
		return (1);
	}
	if (fd == -1)
		free(current_line);
	return (-1);
}
