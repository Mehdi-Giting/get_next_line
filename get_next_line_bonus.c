/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:07:00 by ellabiad          #+#    #+#             */
/*   Updated: 2025/04/15 18:09:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Quick note here, ft_strjoin is used but due to its only purpose to set stash
//to its new value, i free the old stash inside ft_strjoin. It is the only
//difference with the "real" ft_strjoin we had to make for the libft.

#include "get_next_line_bonus.h"

char	*fill_stash(char *buffer, char *stash, int fd)
{
	int	byte_read;

	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
			return (NULL);
		buffer[byte_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (ft_strchr(buffer, '\n') != NULL)
			break ;
	}
	return (stash);
}

char	*fill_line(char **stash_ptr)
{
	char	*line;
	char	*new_stash;
	char	*stash;
	int		i;

	i = 0;
	stash = *stash_ptr;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		line = ft_substr(stash, 0, i + 1);
	else
		line = ft_substr(stash, 0, i);
	if (stash[i] == '\n')
		new_stash = ft_substr(stash, i + 1, ft_strlen(stash) - i);
	else
		new_stash = NULL;
	free(*stash_ptr);
	*stash_ptr = new_stash;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*stash[1024] = { NULL };

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	stash[fd] = fill_stash(buffer, stash[fd], fd);
	free(buffer);
	if (!stash[fd] || stash[fd][0] == '\0')
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	if (!stash[fd])
		return (NULL);
	line = fill_line(&stash[fd]);
	return (line);
}

// int	main(void)
// {
// 	int		fd1, fd2, fd3;
// 	char	*line;

// 	fd1 = open("test1.txt", O_RDONLY);
// 	fd2 = open("test2.txt", O_RDONLY);
// 	fd3 = open("test3.txt", O_RDONLY);

// 	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
// 	{
// 		perror("Error opening one of the files");
// 		return (1);
// 	}

// 	line = get_next_line(fd1);
// 	if (line)
// 	{
// 		printf("test1.txt: %s", line);
// 		free(line);
// 	}

// 	line = get_next_line(fd2);
// 	if (line)
// 	{
// 		printf("test2.txt: %s", line);
// 		free(line);
// 	}

// 	line = get_next_line(fd3);
// 	if (line)
// 	{
// 		printf("test3.txt: %s", line);
// 		free(line);
// 	}

// 	line = get_next_line(fd1);
// 	if (line)
// 	{
// 		printf("test1.txt: %s", line);
// 		free(line);
// 	}

// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }