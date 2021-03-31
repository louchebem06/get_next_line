/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:33:26 by bledda            #+#    #+#             */
/*   Updated: 2021/03/31 15:36:09 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char buffer[BUFFER_SIZE + 1];
	int ret = read(fd, buffer, BUFFER_SIZE);

	(void)fd;
	(void)line;
	buffer[ret + 1] = 0;
	if (fd == -1 || ret <= 0)
		return (-1);
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