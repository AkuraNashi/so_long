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
//i = y
//j = x
void	recursive_path(t_mlx *mlx, t_coords *c, int i)
{
	char	**map;

	map = mlx->map->map;
	c = mlx->player->coords;
	//Haut
	if (map[c->y][c->x] && map[c->y - 1][c->x] != '1')
	{
		c->y -= 1;
		i += 1;
		recursive_path(mlx, c, i);
	}
}

void	check_coins(t_mlx *mlx)
{
	char		**map;
	int			i;
	int			j;
	t_coords	*coords;

	coords = malloc(sizeof(*coords));
	if (!coords)
		return ;
	coords->x = 0;
	coords->y = 0;
	map = mlx->map->map;
	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				coords->x = j;
				coords->y = i;
				recursive_path(mlx, coords, 0);
			}
			j++;
		}
		i++;
	}
}