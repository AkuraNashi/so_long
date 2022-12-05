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

/// Free le tableau envoyer
/// \param tab le tableau a free
void	free_tab(void **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
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
}

/// Permet de generer une image dans la window
/// \param x Coordonnees x de l'image
/// \param y Coordonees y de l'image
/// \param mlx structure de la window
/// \param nameimage nom de l'image a generer
void	drow_one_texture(int x, int y, t_mlx *mlx, char *nameimage)
{
	void	*img;

	img = NULL;
	img = mlx_xpm_file_to_image(mlx->mlx, nameimage, &mlx->w, &mlx->h);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img, x, y);
}

int	initialisation(int ac, char **av)
{
	if (ac < 2)
		return (0);
	if (!check_strname(av[1]))
	{
		ft_printf("Error\nMauvaise extension de fichier\nClosing...\n");
		return (0);
	}
	return (1);
}

/// Hook sur les touches afin de se deplacer, fermer la fenetre etc
/// \param keycode la touche envoyer
/// \param mlx structure de la window
/// \return
int	main(int ac, char **av)
{
	t_mlx		*mlx;
	void		*img;

	if (!initialisation(ac, av))
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
	img = mlx_xpm_file_to_image(mlx->mlx, "assets/terrain.xpm", &mlx->w, &mlx->h);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img,
		0, mlx->map->c_max->y - 128);
	mlx_hook(mlx->mlx_win, 2, 1L << 0, key_hook, mlx);
	mlx_hook(mlx->mlx_win, 17, 0, close_window, mlx);
	mlx_loop(mlx->mlx);
}
