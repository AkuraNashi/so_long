/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:35:13 by lcamilo-          #+#    #+#             */
/*   Updated: 2022/11/07 16:35:15 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// Cree une structure player
/// \param map tableau en 2d
/// permettant de savoir ou est le joueur
/// \return la structure player
t_entity	*new_player(char **map)
{
	t_entity	*player;

	player = malloc(sizeof(*player));
	player->coords = find_player(map);
	player->coins = 0;
	return (player);
}

///Permet de savoir ou est le joueur dans la matrice
/// \param map tableau en 2d
/// \return return la coordonnes du joueur

t_coords	*find_player(char **map)
{
	t_coords	*coords;
	int			i;
	int			j;

	coords = malloc(sizeof(*coords));
	if (!coords)
		return (NULL);
	i = 0;
	coords->x = 0;
	coords->y = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				coords->x = j;
				coords->y = i;
			}
			j++;
		}
		i++;
	}
	return (coords);
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
