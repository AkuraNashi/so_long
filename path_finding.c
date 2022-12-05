/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:48:00 by lcamilo-          #+#    #+#             */
/*   Updated: 2022/11/16 15:48:01 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
///Check la coords XY dans le tableau afin de savoir si c'est un mur ou non
/// \param mlx la structure window
/// \param x la parcelle X
/// \param y la parcelle Y
/// \return

int	check_adjacent(t_mlx *mlx, int x, int y)
{
	t_coords	*c;
	char		**map;

	map = mlx->map->map;
	printf("check adjacent map : [%p]\n", map);
	c = malloc(sizeof(*c));
	c->x = x;
	c->y = y;
	if (map[c->y][c->x] != '1')
		map[c->y][c->x] = 'B';
	free(c);
	return (0);
}
///Check les differentes tiles autour de la coordonnees
/// \param mlx structure de la window
/// \param x coordonnees x de la matrice
/// \param y coordonnees x de la matrice

void	recursive_path(t_mlx *mlx, int x, int y)
{
	char	**map;

	map = mlx->map->map;
	printf("recursive path map : [%p]\n", map);
	if (map[y][x] == '1' || map[y][x] == 'B')
		return ;
	check_adjacent(mlx, x, y);
	recursive_path(mlx, x, y - 1);
	recursive_path(mlx, x + 1, y);
	recursive_path(mlx, x, y + 1);
	recursive_path(mlx, x - 1, y);
}
/// Check le nb de coins dans la matrice
/// \param mlx structure de la window

void	check_coins(t_mlx *mlx)
{
	char	**map;
	int		i;
	int		j;

	map = mlx->map->map;
	printf("check coin map : [%p]\n", map);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				mlx->cp->x = j;
				mlx->cp->y = i;
				recursive_path(mlx, j, i);
			}
			j++;
		}
		i++;
	}
	free_tab((void *)mlx->map->map);
	mlx->map->map = fillmap(mlx->file);
}
