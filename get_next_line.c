/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:07:00 by ellabiad          #+#    #+#             */
/*   Updated: 2025/04/14 14:39:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// line 51 i do substr stash and i plus 1 so i can jump the \n
char	*fill_stash(char *buffer, char *stash, int fd)
{
	int	byte_read;

	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		buffer[byte_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (ft_strchr(buffer, '\n') != NULL)
			return (stash);
	}
	return (stash);
}

char	*fill_line(char *stash)
{
	char	*line;
	char	*new_stash;
	int		i;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		line = ft_substr(stash, 0, i + 1);
	else
		line = ft_substr(stash, 0, i);
	if (ft_strchr(stash, '\n'))
		new_stash = ft_substr(stash, i + 1, ft_strlen(stash) - i);
	else
		new_stash = NULL;
	free(stash);
	stash = new_stash;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*stash;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (fd < 0)
		return (NULL);
	stash = fill_stash(buffer, stash, fd);
	line = fill_line(stash);
	if (!stash || !stash[0])
	{
		free(buffer);
		return (NULL);
	}
	free(buffer);
	return (line);
}

int	main(void)
{
	int	i = open("./test.txt", O_RDONLY);
	char *str;
	str = get_next_line(i);
	printf("%s\n", str);
	free(str);
	// for (int j = 0; j < 10; j++)
	// {
	// 	str = get_next_line(i);
	// 	printf("%s\n", str);
	// 	free(str);
	// }
}