/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 01:11:49 by lcamilo-          #+#    #+#             */
/*   Updated: 2022/11/29 01:11:50 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_tostr(t_mlx *mlx)
{
	char	*str;
	char	*temp;

	temp = ft_itoa(mlx->move);
	str = ft_strjoin("Moves : ", temp);
	mlx_string_put(mlx->mlx, mlx->mlx_win, 20,
				   mlx->map->c_max->y - 50, 0xFFFFFF, str);
	free(str);
	free(temp);
}
