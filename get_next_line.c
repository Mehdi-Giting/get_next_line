/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellabiad <ellabiad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:07:00 by ellabiad          #+#    #+#             */
/*   Updated: 2025/04/10 15:23:22 by ellabiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		nbyte;
	int		i;
	char	*dest;

	nbyte = 5;
	i = 0;
	dest = malloc(sizeof(char) * nbyte + 1);
	if (!dest)
		return (NULL);
	read(fd, dest, nbyte);
	while (dest[i] != '\n' && dest[i])
	{
		ft_putchar(dest[i]);
		i++;
	}
	return (dest);
}

int	main(void)
{
	char *str = get_next_line;
}