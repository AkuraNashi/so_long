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

/// Check si toute la ligne correspond a un mur
/// \param str la ligne a checker
/// \return 1 si la ligne ne contient que des murs
int	check_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

///Check la bordure
/// \param mlx structure de la window
/// \return 0 si c'est faux 1 si c'est bon
int	check_border(t_mlx *mlx)
{
	char	**map;
	int		i;
	int		length;

	map = mlx->map->map;
	i = 0;
	length = ft_strlen(map[i]) - 1;
	while (map[i])
	{
		if (i == 0 || i == count_lines(mlx->file))
		{
			if (!check_str(map[i]))
				return (0);
		}
		else if (map[i][0] != '1' || map[i][length] != '1')
			return (0);
		i++;
	}
	return (1);
}

//Check pathfinding
//Ajouter ennemie
//Ajouter animation
//Ajouter moves dans la fenetre

/// Va checker les differents cas d'erreur possibles avec la map
/// \param mlx structure de la windows
/// \return 1 si la map passe sinon 0
int	check_map(t_mlx *mlx)
{
	if (!check_border(mlx))
	{
		ft_printf("Error\nLa map n'est pas entouré de mur\nClosing...\n");
		return (0);
	}
	if (!check_rectangle(mlx->map->map))
	{
		ft_printf("Error\nLa map n'est pas un rectangle\nClosing...\n");
		return (0);
	}
	if (!check_elements(mlx))
	{
		ft_printf("Error\nLa map ne contient pas un de ces elements :"
			"\n 1 Sortie\n 1 item\n 1 position de depart\nClosing...\n");
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

int	check_elements(t_mlx *mlx)
{
	if (mlx->coins >= 1 && mlx->start == 1 && mlx->exit == 1)
		return (1);
	else
		return (0);
}
