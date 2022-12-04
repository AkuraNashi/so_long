/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:33:25 by lcamilo-          #+#    #+#             */
/*   Updated: 2022/10/31 21:33:30 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// Permet d'effectuer des actions via les entrees claviers
/// \param keycode la touche du claviers
/// \param mlx structure de la window
/// \return
int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		close_window(mlx);
	if (keycode == 2)
		movement_right(mlx);
	else if (keycode == 0)
		movement_left(mlx);
	else if (keycode == 13)
		movement_up(mlx);
	else if (keycode == 1)
		movement_down(mlx);
	else if (keycode == 7)
		check_coins(mlx);
	return (0);
}

/// Permet de generer une image dans la window lors d'un deplacement
/// \param x Coordonnees x de l'image
/// \param y Coordonees y de l'image
/// \param mlx structure de la window
/// \param nameimage nom de l'image a generer
void	drow_movement(int x, int y, t_mlx *mlx, char *nameimage)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx->mlx, nameimage, &mlx->w, &mlx->h);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img, x * 128, y * 128);
	printf("drow movement img : [%p]\n", img);

}

/// Permet de generer une image dans la window
/// \param x Coordonnees x de l'image
/// \param y Coordonees y de l'image
/// \param mlx structure de la window
/// \param nameimage nom de l'image a generer
void	drow_one_texture(int x, int y, t_mlx *mlx, char *nameimage)
{
	void	*img = NULL;

	img = mlx_xpm_file_to_image(mlx->mlx, nameimage, &mlx->w, &mlx->h);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img, x, y);
	printf("drow one texture img : [%p]\n", img);
}

/// Hook sur les touches afin de se deplacer, fermer la fenetre etc
/// \param keycode la touche envoyer
/// \param mlx structure de la window
/// \return
int	main(int ac, char **av)
{
	t_mlx		*mlx;
	void		*img;

	if (ac < 2)
		return (0);
	mlx = new_mlx(av);
	if (mlx == NULL)
	{
		ft_printf("Probleme lors de l'initialisation\nClosing...\n");
		return (0);
	}
	if (!check_map(mlx))
		close_window(mlx);
	check_coins(mlx);
	generate_map(mlx, 0, 0);
	img = mlx_xpm_file_to_image(mlx->mlx, "terrain.xpm", &mlx->w, &mlx->h);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img, 0, mlx->map->c_max->y - 128);
	mlx_hook(mlx->mlx_win, 2, 1L << 0, key_hook, mlx);
	mlx_hook(mlx->mlx_win, 17, 0, close_window, mlx);
	mlx_loop(mlx->mlx);
}
