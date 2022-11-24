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

//Check la bordure
//Check pathfinding
//Ajouter ennemie
//Ajouter animation
//Ajouter moves dans la fenetre
int	check_map(t_mlx *mlx)
{
	int	i;

	i = ft_strlen(mlx->file);
	if (!(mlx->file[i - 1] == 'b'
			&& mlx->file[i - 2] == 'e'
			&& mlx->file[i - 3] == 'r'
			&& mlx->file[i - 4] == '.'))
	{
		ft_printf("Error\nMauvaise extension de fichier\nClosing...\n");
		return (0);
	}
	if (!check_rectangle(mlx->map->map))
	{
		ft_printf("Error\nLa map n'est pas un rectangle\nClosing...\n");
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
