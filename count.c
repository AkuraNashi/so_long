/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 22:35:40 by lcamilo-          #+#    #+#             */
/*   Updated: 2022/11/27 22:35:41 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

///Compte les lignes du fichiers
/// \param file nom du fichier
/// \return le nombre de lignes

int	count_lines(char *file)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	count = 0;
	while (line != NULL)
	{
		if (line[0] != '\n')
			count++;
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	printf("count line fd : [%p]\n", &fd);
	printf("count line line : [%p]\n", line);
	printf("count line count : [%p]\n", &count);
	free(line);
	close(fd);
	return (count);
}

///Compte le nb de coins dans la map
/// \param map tableau en 2d
/// \return la structure window

int	count_coins(char **map)
{
	int	i;
	int	j;
	int	coins;

	coins = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				coins++;
			j++;
		}
		i++;
	}
	return (coins);
}

///compte le nombre de player sur la map
/// \param map
/// \return le nombre de player
int	count_player(char **map)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				player++;
			j++;
		}
		i++;
	}
	return (player);
}

/// Compte le nombre d'exit sur la map
/// \param map
/// \return le nombre d'exit
int	count_exit(char **map)
{
	int	i;
	int	j;
	int	exit;

	i = 0;
	exit = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	return (exit);
}
