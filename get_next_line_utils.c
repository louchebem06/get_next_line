/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:33:14 by bledda            #+#    #+#             */
/*   Updated: 2021/03/30 18:43:40 by bledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void 	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	str = malloc(size * count);
	if (str == 0)
		return (0);
	ft_memset(str, 0, size * count);
	return (str);
}


void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		((char *)b)[i++] = c;
	return (b);
}

