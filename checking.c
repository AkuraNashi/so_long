/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:12:02 by lcamilo-          #+#    #+#             */
/*   Updated: 2022/11/24 14:12:03 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/// Va checker les differents cas d'erreur possibles avec la map
/// \param mlx structure de la windows
/// \return 1 si la map passe sinon 0
int check_map(t_mlx *mlx)
{
	if (!check_rectangle(mlx->map->map))
	{

		return (0);
	}
	return (1);
}

/// Check si la map est un rectangle ou non
/// \param map tableau en 2d contenant la map
/// \return	1 si c'est bon

int	check_rectangle(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			j++;
		}
		i++;
	}
	if (j > i || i > j)
		return (1);
	return (0);
}
