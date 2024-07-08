/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:11:39 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/07/08 20:50:51 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_line(char *s)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	tmp = ft_substr(s, 0, i + 1);
	return (tmp);
}

char	*ft_save(char *s)
{
	int		i;
	char	*tmp;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	tmp = ft_substr(s, i + 1, ft_strlen(s));
	free(s);
	return (tmp);
}

char	*ft_read_fd(int fd, char *s)
{
	char	*buffer;
	int		res;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	res = 1;
	while (!ft_strchr(s, '\n') && res != 0)
	{
		res = read(fd, buffer, BUFFER_SIZE);
		if (res == -1)
			return (free(buffer), NULL);
		buffer[res] = '\0';
		s = ft_strjoin(s, buffer);
	}
	free(buffer);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*s;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024 || read(fd, 0, 0) < 0)
		return (NULL);
	s = ft_read_fd(fd, s);
	if (!s)
		return (NULL);
	line = ft_line(s);
	s = ft_save(s);
	return (line);
}

// int	main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("example.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	if (close(fd) == -1)
// 	{
// 		perror("Error closing file");
// 		return (1);
// 	}
// 	return (0);
// }