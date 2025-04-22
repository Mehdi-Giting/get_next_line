/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellabiad <ellabiad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:07:29 by ellabiad          #+#    #+#             */
/*   Updated: 2025/04/22 17:18:46 by ellabiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
	# define BUFFER_SIZE 5
#endif
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*fill_stash(char *buffer, char *stash, int fd);
char	*fill_line(char **stash);
size_t	ft_strlen(const char *str);
char	*ft_strchr(char *str, char c);
char	*ft_strdup(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);

#endif