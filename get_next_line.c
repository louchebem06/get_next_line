/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:33:26 by bledda            #+#    #+#             */
/*   Updated: 2021/03/31 18:24:30 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char 		buffer[BUFFER_SIZE + 1];
	int 		read_fd;
	static int 	cursor = 0;
	static int	first_dim = 1;
	int i;

	i = 0;
	read_fd = read(fd, buffer, BUFFER_SIZE);
	if (fd == -1 || read_fd < 0)
		return (-1);
	while (buffer[cursor] != 0 && cursor <= BUFFER_SIZE)
	{
		if (buffer[cursor] == '\n')
		{
			line = malloc(sizeof(char *) * first_dim + 1);
			if (line == 0)
				return (-1);
			line = 0;
			line[first_dim - 1] = malloc(sizeof(char) * i + 1);
			if (line[first_dim - 1] == 0)
				return (-1);
			line[first_dim - 1][i] = 0;
			while (i >= 0)
			{
				if (cursor - 1 < 0)
					line[first_dim - 1][i] = 0;
				else
					line[first_dim - 1][i] = buffer[cursor - 1];
				i--;
				cursor--;
			}
			while (buffer[cursor] != '\n')
				cursor++;
			cursor++;
			first_dim++;
			return (1);
		}
		i++;
		cursor++;
	}
	return (0);
}

/*
int get_next_line(int fd, char **line);
Fichiers de rendu get_next_line.c, get_next_line_utils.c,
get_next_line.h
ParamËtres #1. le file descriptor sur lequel lire
#2. La valeur de ce qui a ÈtÈ lu
Valeur de retour 1 : Une ligne a ÈtÈ lue
0 : La fin de fichier a ÈtÈ atteinte
-1 : Une erreur est survenue
Fonctions externes autorisÈes
read, malloc, free
Description Ecrivez une fonction qui retourne une ligne lue
depuis un file descriptor, sans le retour a la
ligne
*/