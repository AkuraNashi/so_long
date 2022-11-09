/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <lcamilo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 00:28:46 by lcamilo-          #+#    #+#             */
/*   Updated: 2022/10/27 19:39:42 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);

int	read_line(char **line, int fd, int i)
{
	char	*tmp;
	char	buffer[BUFFER_SIZE + 1];

	while (!ft_strchr(*line, '\n') && i)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i && !*line)
		{
			buffer[i] = 0;
			*line = ft_strlendup(buffer, i);
		}
		else if (i)
		{
			tmp = *line;
			*line = ft_strlenjoin(tmp, buffer, i);
			free(tmp);
		}
		if (!*line || (!*line[0] && !i))
		{
			free(*line);
			*line = NULL;
			return (0);
		}
	}
	return (1);
}

int	read_buffer(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	return (i);
}

void	free_buffer(char **buffer)
{
	if (*buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*tmp;
	char		*str;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		free_buffer(&buffer);
		return (NULL);
	}
	if (!read_line(&buffer, fd, 1))
	{
		free(buffer);
		return (NULL);
	}
	i = read_buffer(buffer);
	str = ft_strlendup(buffer, i);
	if (!str)
		return (NULL);
	tmp = buffer;
	buffer = ft_strlendup(tmp + i, ft_strlen(tmp + i));
	if (!buffer)
		return (NULL);
	free(tmp);
	return (str);
}

//int main(void)
//{
//	int fd = open("text.txt", O_RDONLY);
//	char *c;
//
//	c = get_next_line(fd);
//	printf("%s\n", c);
//}

