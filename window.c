/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:31:20 by lcamilo-          #+#    #+#             */
/*   Updated: 2022/11/03 20:31:22 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*calculate_window(t_map *map)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	map = malloc(sizeof(*map));
	while (map->map[i])
	{
		while (map->map[j])
		{
			map->coords_max->y += 128;
			j++;
		}
		map->coords_max->x += 128;
		i++;
	}
	return (map);
}

t_vars	*new_vars(int c)
{
	t_vars	*vars;

	vars = malloc(sizeof(*vars));
	return (vars);
}
