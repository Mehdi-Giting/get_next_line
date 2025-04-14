/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:07:00 by ellabiad          #+#    #+#             */
/*   Updated: 2025/04/14 17:56:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_stash(char *buffer, char *stash, int fd)
{
	int	byte_read;

	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		buffer[byte_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		//printf("stash : %s\n", stash);
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
	if (stash[i] == '\n')
	{
		new_stash = ft_strjoin(NULL, stash + i + 1);
		//printf("newstash : %s\n", new_stash);
		//printf("stash + i : %s\n", stash + i + 1);
		free(stash);
	}
	else
		free(stash);
	stash = ft_strdup(new_stash);
	//printf("stash : %s\n", stash);
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
	//printf("stash : %s\n", stash);
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
	for (int j = 0; j < 2; j++)
	{
		str = get_next_line(i);
		printf("Line printed : %s", str);
		free(str);
	}
	printf("\n");
}