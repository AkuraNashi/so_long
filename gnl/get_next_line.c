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

int	read_file(char **line, int fd)
{
	char		*tmp;
	char		buf[BUFFER_SIZE + 1];
	int			i;

	i = 1;
	while (!ft_strchr(*line, '\n') && i)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i && !*line)
			*line = ft_strldup(buf, i);
		else if (i)
		{
			tmp = *line;
			*line = ft_strljoin(tmp, buf, i);
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

char	*get_next_line(int fd)
{
	static char	*line;
	char		*tmp;
	char		*ret_str;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!read_file(&line, fd))
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i])
		i++;
	ret_str = ft_strldup(line, i);
	if (!ret_str)
		return (NULL);
	tmp = line;
	line = ft_strldup(tmp + i, ft_strlen(tmp + i));
	free(tmp);
	if (!line)
		return (NULL);
	return (ret_str);
}
