/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:58:29 by lcamilo-          #+#    #+#             */
/*   Updated: 2022/10/31 21:58:30 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx/mlx.h"
#include "libft/libft.h"
#include "gnl/get_next_line.h"
#include <stdio.h>
#include <unistd.h>

typedef struct	s_coords
{
	int x;
	int y;
}	t_coords;

typedef struct	s_entity
{
	t_coords coords;
	void	*img;
}	t_entity;

#endif

