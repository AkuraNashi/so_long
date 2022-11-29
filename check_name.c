/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 22:55:26 by lcamilo-          #+#    #+#             */
/*   Updated: 2022/11/27 22:55:27 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_strname(t_mlx *mlx)
{
	int	i;

	i = count_lines(mlx->file);
	if (!(mlx->file[i - 1] == 'r'
			&& mlx->file[i - 2] == 'e'
			&& mlx->file[i - 3] == 'b'
			&& mlx->file[i - 4] == '.'))
		return (0);
	return (1);
}
